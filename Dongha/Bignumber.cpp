#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    int size = number.length();

    int start = 0;
    int max = 0;
    for(int i = 0; i<size-k+1; i++){
        int digit = (int)number[i]-48;
        if(max < digit){
            max = digit;
            start = i;
        }
        if(max == 9)
            break;
    }

    // cout << number << endl;

    number.erase(0,min(start,k));

    // cout << number << endl;

    while(number.size() > size-k){
        bool found = false;
        for(int i = 1; i < number.size()-1; i++){
            if(number[i] < number[i+1]){
                number.erase(i,1);
                found = true;
                break;
            }
        }
        if(!found)
            number.erase(number.size()-1,1);

        // cout << number << endl;
    }

    return number;
}

int main(){
    string number = "9876";
    int k = 1;

    cout << solution(number, k) << endl;
}

