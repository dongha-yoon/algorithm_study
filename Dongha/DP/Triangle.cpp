//https://programmers.co.kr/learn/courses/30/lessons/43105
#include <string>
#include <vector>

using namespace std;

int DP[500][500];
int recurse(vector<vector<int>> triangle, int h, int x);

int solution(vector<vector<int>> triangle) {
    int h = triangle.size();
    
    for(int i=h-1; i>0; i--){
        for(int j=0; j<i; j++){
            triangle[i-1][j] += max(triangle[i][j], triangle[i][j+1]);
        }
    }
    return triangle[0][0];
}

int recurse(vector<vector<int>> triangle, int h, int x){
    if(DP[h][x] != 0)
        return DP[h][x];
    
    if(h == triangle.size()-1)
        return DP[h][x] = triangle[h][x];
    
    else
        return DP[h][x] = triangle[h][x] + max(recurse(triangle,h+1,x), recurse(triangle,h+1,x+1));
}