#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
    queue<pair<int, int>> deliverQueue;
    queue<pair<int, int>> pickupQueue;

    for (int i = n - 1; i >= 0; --i)
    {
        if (deliveries[i] > 0)
            deliverQueue.push({i + 1, deliveries[i]});
        if (pickups[i] > 0)
            pickupQueue.push({i + 1, pickups[i]});
    }

    auto consume = [&](queue<pair<int, int>> &q, int space)
    {
        while (space > 0 && !q.empty())
        {
            auto &[pos, cnt] = q.front();
            if (cnt <= space)
            {
                space -= cnt;
                q.pop();
            }
            else
            {
                cnt -= space;
                space = 0;
            }
        }
    };

    auto frontPos = [](queue<pair<int, int>> &q)
    {
        return q.empty() ? 0 : q.front().first;
    };

    long long answer = 0;

    while (!deliverQueue.empty() || !pickupQueue.empty())
    {
        int distance = max(frontPos(deliverQueue), frontPos(pickupQueue));
        consume(deliverQueue, cap);
        consume(pickupQueue, cap);
        answer += distance * 2;
    }

    return answer;
}