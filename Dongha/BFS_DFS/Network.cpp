#include <string>
#include <vector>
#include <iostream>


using namespace std;

#define MAX_COMPUTER 200

bool visited[MAX_COMPUTER];

void dfs(int cur, vector<vector<int>> computers){
    if(visited[cur]==true)
        return;
    // printf("%d\n",cur);
    visited[cur] = true;
    for(int j=0; j<computers.size(); j++){
        if(j!=cur && computers[cur][j] == 1)
            dfs(j, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for(int i=0; i<n; i++){
        if(visited[i]!=true){
            answer++;
            dfs(i, computers);
        }
    }
    return answer;
}

int main(){
    vector<vector<int>> computers;
    int n = 3;

    computers.resize(n);
    for(int i=0;i<n;i++){
        computers[i].resize(n);
    }
    computers[0][0] = computers[0][1] = computers[1][0] = computers[1][1] = computers[2][2] = 1;

    cout << solution(n,computers) << endl;
}