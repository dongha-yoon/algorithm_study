#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int max = 0;

    for(int i: reserve){
        answer++;
        if(i-1 != max)
            answer++;
        if(i+1 != n){
            answer++;
            max = i+1;
        }
    }


    return answer;
}