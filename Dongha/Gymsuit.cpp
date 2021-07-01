#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    vector<int>::iterator iter_lost = lost.begin();
    vector<int>::iterator iter_reserve = reserve.begin();

    while(iter_lost != lost.end()
            && iter_reserve != reserve.end()){
        
        if(*iter_lost == *iter_reserve){
            lost.erase(iter_lost);
            reserve.erase(iter_reserve);
            continue;
        }
        if(*iter_lost > *iter_reserve)
            iter_reserve++;
        else
            iter_lost++;
    }

    iter_lost = lost.begin();

    while(iter_lost != lost.end()){
        bool isfound = false;

        if(!reserve.empty()){
            for(iter_reserve = reserve.begin(); iter_reserve != reserve.end();iter_reserve++){
                if(*iter_lost == *iter_reserve-1
                    || *iter_lost == *iter_reserve+1){

                    isfound = true;
                    reserve.erase(iter_reserve);
                    
                    break;
                }
            }
        }
        if(!isfound)
            answer--;
            
        iter_lost++;
    }

    return answer;
}


int main(){
    int n = 12;
    vector<int> lost,reserve;

    lost.push_back(1);
    lost.push_back(2);
    lost.push_back(3);
    lost.push_back(4);
    lost.push_back(8);
    lost.push_back(9);
    lost.push_back(10);
    lost.push_back(12);
    
    reserve.push_back(1);
    
    cout << solution(n,lost,reserve) << endl;
}

