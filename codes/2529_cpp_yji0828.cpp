#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int k;
char sign[11];
int num[11];
bool check[11];
vector<string> answers;
string maximum, minimum;

bool check_one(char a, char b, char oper);
void comb(int index, string num);

int main() {
    cin >> k;

    for (int i = 0; i < k; i++)
        cin >> sign[i];

    comb(0, "");
    sort(answers.begin(), answers.end());
    cout << answers.back() << '\n' << answers.front();

    return 0;
}

bool check_one(char a, char b, char oper) {
    if (oper == '<') {
        if (a > b) return false;
    }
    else {
        if (a < b) return false;
    }
    return true;
}

void comb(int index, string num) {
    if (index == (k + 1)) {
        answers.push_back(num);
        return;
    }

    for (int i = 0; i <= 9; i++) {
        if (check[i]) continue;
        if (index == 0 || check_one(num[index - 1], i + '0', sign[index - 1])) {
            check[i] = true;
            comb(index + 1, num + to_string(i));
            check[i] = false;
        }
    }
}