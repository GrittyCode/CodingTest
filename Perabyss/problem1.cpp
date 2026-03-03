#include <vector>

using namespace std;

vector<int> solution(vector<int> v, int x, int y)
{
    v.erase(v.begin(), v.begin() + x);
    v.erase(v.end() - y, v.end());
    int minNum = x + y;
    for (auto &num : v)
    {
        if (num < minNum)
            num = 0;
    }

    return v;
}
