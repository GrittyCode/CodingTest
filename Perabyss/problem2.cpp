#include <vector>
using namespace std;

// cuts: 잘라낼 칸들의 좌표 목록 {row, col}
// n: 행 수, m: 열 수

vector<vector<int>> solution(int n, int m, vector<pair<int, int>> cuts)
{
    vector<vector<int>> paper(n, vector<int>(m, 1));
    for (const auto &[r, c] : cuts)
    {
        paper[r][c] = 0;
        paper[r][m - 1 - c] = 0; // 가로 대칭
        paper[n - 1 - r][m -1 - c] = 0; //가로 대칭 세로 대칭
        paper[n - 1 -r][c] = 0;// 세로 대칭 
    }

    return paper;
}