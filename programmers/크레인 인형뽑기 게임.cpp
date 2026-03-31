#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    stack<int> dollStack;
    int answer = 0;

    for (int move : moves)
    {
        for (int i = 0; i < (int)board.size(); ++i)
        {
            int doll = board[i][move - 1];
            if (doll == 0)
                continue;

            board[i][move - 1] = 0;

            if (!dollStack.empty() && dollStack.top() == doll)
            {
                answer += 2;
                dollStack.pop();
            }
            else
            {
                dollStack.push(doll);
            }
            break;
        }
    }

    return answer;
}