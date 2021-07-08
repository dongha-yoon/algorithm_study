//https://programmers.co.kr/learn/courses/30/lessons/42895
#include <iostream>

#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
#define SIZE 32001

vector<vector<int>> countList;
map<int,int> DP; //(num, cnt)
map<int,vector<int>> pending;//(cnt, num list)

void setDP(int num, int cnt, int N){
    // printf("num: %d, cnt: %d\n",num, cnt);
    if(DP[num+N] == 0){
        DP[num+N] = cnt+1;
        countList[cnt+1].push_back(num+N);
    }
    // printf("1 ");
    if(num-N > 0 && DP[num-N] == 0){
        DP[num-N] = cnt+1;
        countList[cnt+1].push_back(num-N);
    }
    // printf("2 ");
    if(DP[num*N] == 0){
        DP[num*N] = cnt+1;
        countList[cnt+1].push_back(num*N);
    }
    // printf("3 ");
    if( num%N ==0 && DP[num/N] == 0){
        DP[num/N] = cnt+1;
        countList[cnt+1].push_back(num/N);
    }
    // printf("4\n");
    int cnt1 = cnt;
    int num1 = num;
    for(int cnt2=1; cnt2<=cnt1; cnt2++){
        if(cnt1 + cnt2 <= 8){
            for(int num2: countList[cnt2]){
                if(DP[num1+num2] == 0)
                    pending[cnt1+cnt2].push_back(num1+num2);
                if(num1-num2 > 0 && DP[num1-num2] == 0)
                    pending[cnt1+cnt2].push_back(num1-num2);
                else if(num2-num1 > 0 && DP[num2-num1] == 0)
                    pending[cnt1+cnt2].push_back(num2-num1);                    
                if(DP[num1*num2] == 0)
                    pending[cnt1+cnt2].push_back(num1*num2);
                if(num1%num2==0 && DP[num1/num2] == 0)
                    pending[cnt1+cnt2].push_back(num1/num2);
                else if(num2%num1==0 && DP[num2/num1] == 0)
                    pending[cnt1+cnt2].push_back(num2/num1);
            }
        }    
    }
        
}


int solution(int N, int number) {
    //initialize
    countList.resize(10);

    int nnn = N;
    for(int cnt=1; cnt<=8;cnt++){
        // printf("cnt: %d\n",cnt);
        countList[cnt].push_back(nnn);
        if(nnn < SIZE)
            DP[nnn] = cnt;
        nnn = nnn*10 + N;

        for(int i: pending[cnt]){
            if(DP[i] == 0){
                DP[i] = cnt;
                countList[cnt].push_back(i);
            }
        }
        for(int i: countList[cnt]){
            setDP(i, cnt, N);
        }
            
    }
    return (DP[number]==0||DP[number]>8)?-1:DP[number];
}

int main(){
    int N;
    int num;
    cin >> N >> num;
    // cout << "==============" << endl;
    cout << solution(N,num) << endl;

    // for(pair<int,int> p: DP){
    //     if(p.second != 0 && p.second != 8)
    //         printf("%d: %d\n",p.first, p.second);
    // }

}