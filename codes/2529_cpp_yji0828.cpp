#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int k;
char sign[11];
bool num_used[11];
vector<string> answers;
pair<string, string> comb(int left_digit, string num, bool num_used[10], char* sign);

int main() {
    cin >> k;

    for (int i = 1; i <= k; i++)
        cin >> sign[i];

    pair <string, string> answer = comb(k+1, "", num_used, sign);
    cout << answer.second << '\n';
    cout<< answer.first;

    return 0;
}

pair<string, string> comb(int left_digit, string num, bool num_used[10], char* sign) {
    if (left_digit == 0)
        return make_pair(num, num);

    pair<string, string> ans = make_pair("9999999999", "0");
    for (int i = 0; i <= 9; i++) {
        if (num_used[i] || (*sign == '>' && (num.back() - '0') % 10 <= i) || (*sign == '<' && (num.back() - '0') % 10 >= i))
            continue;
        num_used[i] = true;

        pair<string, string> part = comb(left_digit - 1, num + to_string(i), num_used, sign + 1);

        ans.first = min(ans.first, part.first);
        ans.second = max(ans.second, part.second);
        num_used[i] = false;
    }
    return ans;
}