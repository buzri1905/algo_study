#include<iostream>
using namespace std;
void dfs(int prime,int digit, int goal);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int goal_digit;
	cin >> goal_digit;
	dfs(2, 1, goal_digit);
	dfs(3, 1, goal_digit);
	dfs(5, 1, goal_digit);
	dfs(7, 1, goal_digit);
	return 0;
}
void dfs(int prime, int digit, int goal) {
	if (digit == goal) {
		cout << prime<<'\n';
		return;
	}
	for (int i = 1; i < 10; i+=2)
	{
		int x = prime * 10 + i;
		bool is_prime = true;
		for (int j = 3; j*j <= x; j+=2)
		{
			if (x % j == 0)
			{
				is_prime = false;
				break;
			}
		}
		if (!is_prime)
			continue;
		dfs(x, digit + 1, goal);
	}
}
