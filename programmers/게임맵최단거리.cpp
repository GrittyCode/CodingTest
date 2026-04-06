#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> maps)
{
    queue<pair<int, int>> q;
    vector<vector<int>> dist(maps.size(), vector<int>(maps[0].size(), -1));
    q.push({0, 0});
    dist[0][0] = 1;

    int dc[] = {-1, 1, 0, 0};
    int dr[] = {0, 0, -1, 1};

    while (!q.empty())
    {
        auto [col, row] = q.front();
        q.pop();

        if (col == (int)maps.size() - 1 && row == (int)maps[0].size() - 1)
            return dist[col][row];

        for (int i = 0; i < 4; ++i)
        {
            int nc = col + dc[i];
            int nr = row + dr[i];
            if (nc >= 0 && nc < (int)maps.size() &&
                nr >= 0 && nr < (int)maps[0].size() &&
                maps[nc][nr] == 1 && dist[nc][nr] == -1)
            {
                dist[nc][nr] = dist[col][row] + 1;
                q.push({nc, nr});
            }
        }
    }

    return -1;
}