#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<int> numbers, string hand)
{
    string answer = "";

    unordered_map<int, pair<int, int>> dialogNumberDirecotry;

    dialogNumberDirecotry[0] = {3, 1};

    for (int i = 1; i <= 9; ++i)
    {
        int idx = i - 1;
        dialogNumberDirecotry[i] = {idx / 3, idx % 3};
    }

    pair<int, int> leftPoint = {3, 0}, rightPoint = {3, 2}, destPoint;
    string ch;

    for (const int number : numbers)
    {
        destPoint = dialogNumberDirecotry[number];

        if (destPoint.second < 1)
        {
            ch = "L";
            leftPoint = destPoint;
        }
        else if (destPoint.second > 1)
        {
            ch = "R";
            rightPoint = destPoint;
        }
        else
        {
            auto leftWeight =
                abs(destPoint.first - leftPoint.first) + abs(destPoint.second - leftPoint.second);

            auto rightWeight =
                abs(destPoint.first - rightPoint.first) + abs(destPoint.second - rightPoint.second);

            if (leftWeight == rightWeight)
            {
                if (hand.compare("right") == 0)
                {
                    ch = "R";
                    rightPoint = destPoint;
                }
                else
                {
                    ch = "L";
                    leftPoint = destPoint;
                }
            }
            else
            {
                if (leftWeight > rightWeight)
                {
                    ch = "R";
                    rightPoint = destPoint;
                }
                else
                {
                    ch = "L";
                    leftPoint = destPoint;
                }
            }
        }

        answer += ch;
    }

    return answer;
}
