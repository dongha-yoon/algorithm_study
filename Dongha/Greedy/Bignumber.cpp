#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    int size = number.length();
    int start = 0;
    int max = 0;
    for(int i = 0; i<k; i++){
        int digit = (int)number[i]-48;
        if(max < digit){
            max = digit;
            start = i;
        }
        if(max == 9)
            break;
    }
    start = min(start,k);

    if(start == 0 && number[start]== '0'){
        while(number[start] == '0')
            start++;
    }
    else{
        while(number[start] == '0')
            start--;
    }
        
    number.erase(0,start);

    while(number.size() > size-k){
        bool found = false;
        int min = (int)'9';
        int min_idx = 0;

        for(int i = 1; i < number.size(); i++){
            if(min >= number[i]){
                min = number[i];
                min_idx = i;
            }

            if(number[i-1] < number[i]){
                number.erase(i-1,1);
                found = true;
                break;
            }
        }
        if(!found)
            number.erase(min_idx,1);
    }

    return number;
}

int main(){
    string number = "000090001000100";
    int k = 7;

    cout << solution(number, k) << endl;
}

