//https://programmers.co.kr/learn/courses/30/lessons/42895
#include <iostream>

#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
#define MAX 300000
#define SIZE 32001

vector<vector<int>> countList;
map<int,int> DP;

void setDP(int num, int cnt, int N){
    printf("num: %d, cnt: %d\n",num, cnt);
    if(DP.find(num+N) == DP.end()){
        DP.insert(pair<int,int>(num+N, cnt+1));
        countList[cnt+1].push_back(num+N);
    }
    // printf("1 ");
    if(num-N > 0 && DP.find(num-N) == DP.end()){
        DP.insert(pair<int,int>(num-N, cnt+1));
        countList[cnt+1].push_back(num-N);
    }
    // printf("2 ");
    if(DP.find(num*N) == DP.end()){
        DP.insert(pair<int,int>(num*N, cnt+1));
        countList[cnt+1].push_back(num*N);
    }
    // printf("3 ");
    if( num%N ==0 && DP.find(num/N) == DP.end()){
        DP.insert(pair<int,int>(num/N, cnt+1));
        countList[cnt+1].push_back(num/N);
    }
    // printf("4\n");
    if(num*num < MAX){
        if(num*num < SIZE && DP.find(num*num) == DP.end())
            DP.insert(pair<int,int>(num*num, cnt*2));
        if(cnt*2 < 8)
            countList[cnt*2].push_back(num*num);
    }
}


int solution(int N, int number) {
    //initialize
    countList.resize(9);

    int nnn = N;
    for(int cnt=1; cnt<5;cnt++){
        // printf("cnt: %d\n",cnt);
        countList[cnt].push_back(nnn);
        if(nnn < SIZE)
            DP.insert(pair<int,int>(nnn, cnt));
        nnn = nnn*10 + N;
        for(int i: countList[cnt]){
            setDP(i, cnt, N);
            if(DP[number]!=0)
                return DP[number];
        }
    }

    return -1;
}

int main(){
    int N;
    int num;
    cin >> N >> num;
    // cout << "==============" << endl;
    cout << solution(N,num) << endl;
}