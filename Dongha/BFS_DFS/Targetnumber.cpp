#include <string>
#include <vector>
#include <queue>


using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;

    queue<int> Q;
    Q.push(0);

    for(int n: numbers){
        int size = Q.size();
        for(int i=0;i<size;i++){
            int front = Q.front();
            Q.pop();
            Q.push(front+n);
            Q.push(front-n);
        }
    }

    while(!Q.empty()){
        if(Q.front()==target)
            answer++;
        Q.pop();
    }

    return answer;
}