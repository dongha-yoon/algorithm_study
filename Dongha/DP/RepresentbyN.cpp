//https://programmers.co.kr/learn/courses/30/lessons/42895
#include <iostream>

#include <string>
#include <vector>
#include <cmath>

using namespace std;
#define MAX 300000

int DP[MAX];

void init(int N){
    int count = 1;
    int num = N;
    while(num<MAX){
        DP[num] = count;
        DP[num/N] = DP[num-N] = DP[num+N] = count+1;

        num = num*10 + N;
        count++;
    }
}


int solution(int N, int number) {

    if(number >= MAX)
        return MAX;

    if(DP[number] != 0)
        return DP[number];

    if(number == 1)
        return DP[number] = 2;

    if(number < N)
        return DP[number] = number+1;
    // printf("%d\n",number);
    int min = 10;

    int temp1 = DP[number+N]+1;
    int temp2 = DP[number-N]+1;
    int temp3 = DP[number/N]+1;
    temp3 = number%N==0?temp3:MAX;
    int temp4 = DP[number*N]+1;
    if(temp1 !=0 && temp1 < min)
        min = temp1;
    if(temp2 !=0 && temp2 < min)
        min = temp1;
    if(temp3 !=0 && temp3 < min)
        min = temp1;
    if(temp4 !=0 && temp4 < min)
        min = temp1;
    
    
    for(int i=1; i<=number/2; i++){
        if(i != 1 && i <= sqrt(number) && number%i==0){
            int temp = solution(N,i) + solution(N,number/i);
            if(temp < min)
                min = temp;
        }
        int temp = solution(N,i) + solution(N,number-i);
        if(temp < min)
            min = temp;
    }

    if(min > 7){
        DP[number] = MAX;
    }
    else
        DP[number] = min;

    return DP[number];
}

int main(){
    int N = 5;
    init(N);
    

    cout << "==============" << endl;
    cout << solution(N,32000) << endl;

    // for(int i=0;i<MAX;i++){
    //     bool flag = DP[i] != 0 && DP[i] != MAX;
    //     if(flag)
    //         printf("%d: %d\n",i,DP[i]);
    // }

    cout << solution(N,12) << endl;


}