#include <vector>
using namespace std;

void dfs(int idx, const vector<vector<int>>& computers, vector<bool>& visited) {
    visited[idx] = true;
    for (int i = 0; i < (int)computers.size(); i++) {
        if (!visited[i] && computers[idx][i] == 1)
            dfs(i, computers, visited);
    }
}

int solution(int n, vector<vector<int>> computers) {
    vector<bool> visited(n, false);
    int answer = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, computers, visited);
            answer++;
        }
    }
    return answer;
}