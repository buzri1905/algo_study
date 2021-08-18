#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int sticker[100001][2];
int DP[100001][2];

int main() {
	int test_case;
	cin >> test_case;

	while (test_case--) {
		int columns;
		cin >> columns;

		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= columns; j++) {
				scanf("%d", &sticker[j][i]);
			}
		}

		DP[1][0] = sticker[1][0];
		DP[1][1] = sticker[1][1];

		for (int t = 2; t <= columns; t++) {
			DP[t][0] = max(DP[t - 1][1], DP[t - 2][1]) + sticker[t][0];
			DP[t][1] = max(DP[t - 1][0], DP[t - 2][0]) + sticker[t][1];
		}

		printf("%d\n", max(DP[columns][0], DP[columns][1]));
	}

	return 0;
}