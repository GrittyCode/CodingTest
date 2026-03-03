#include <vector>
#include <iostream>

using namespace std;

vector<int> unfold(int size, int foldCount, int idx)
{
    vector<int> points = {idx};

    for (int i = 0; i < foldCount; ++i)
    {
        size *= 2;
        int prev = points.size();
        for (int j = 0; j < prev; ++j)
            points.push_back(size - points[j] - 1);
    }

    return points;
}

vector<vector<int>> solution(int n, int m, vector<int> fold, vector<vector<int>> cut)
{
    int widthFold = 0, heightFold = 0;
    for (int f : fold)
    {
        f == 1 ? (m /= 2, ++widthFold) : (n /= 2, ++heightFold);
    }

    vector<vector<int>> answer(n, vector<int>(m, 1));

    for (auto &c : cut)
    {
        auto rows = unfold(n, heightFold, c[0] - 1);
        auto cols = unfold(m, widthFold, c[1] - 1);

        for (int r : rows)
            for (int c : cols)
                answer[r][c] = 0;
    }

    return answer;
}