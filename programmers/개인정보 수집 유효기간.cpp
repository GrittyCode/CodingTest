#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

int GetTotalDate(string today)
{
    // 2024.05.01
    int y = stoi(today.substr(0, 4));
    int m = stoi(today.substr(5, 2));
    int d = stoi(today.substr(8, 2));
    return y * 28 * 12 + m * 28 + d;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies)
{
    vector<int> answer;

    int todayDate = GetTotalDate(today);

    unordered_map<string, int> term_directory;
    string type;
    int month;

    for (auto &term : terms)
    {
        stringstream ss(term);
        ss >> type >> month;
        term_directory[type] = month * 28;
    }
    string date;
    int index = 1;
    for (const auto &privacie : privacies)
    {
        int toatalDate = GetTotalDate(privacie.substr(0, 10)) + term_directory[privacie.substr(11)];
        if (toatalDate <= todayDate)
        {
            answer.push_back(index);
        }

        ++index;
    }

    return answer;
}