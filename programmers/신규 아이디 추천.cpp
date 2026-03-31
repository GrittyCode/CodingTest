
#include <string>
#include <vector>
#include <regex>

using namespace std;

void Lower(string &new_id)
{
    // A ~ Z

    for (auto &ch : new_id)
    {
        if (ch >= 'A' && ch <= 'Z')
            ch |= 32;
    }
}

string solution(string new_id)
{
    Lower(new_id); // 1단계

    new_id = regex_replace(new_id, regex("[^a-z0-9_\\-\\.]"), ""); // 2단계

    new_id = regex_replace(new_id, regex(R"(\.{2,})"), "."); // 3단계

    new_id = regex_replace(new_id, regex(R"(^\.|\.$)"), ""); // 4단계

    if (new_id.empty())
        new_id += "a"; // 5단계

    if (new_id.length() >= 16)
        new_id = new_id.substr(0, 15);

    new_id = regex_replace(new_id, regex(R"(\.$)"), ""); // 6단계

    while (new_id.length() <= 2)
    {
        new_id.push_back(new_id.back());
    }

    return new_id;
}