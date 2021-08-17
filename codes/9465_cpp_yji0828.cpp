#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int sticker[2][100001];
int DP[2][100001];

int main() {

	int test_case;
	cin >> test_case;

	while (test_case--) {
		int columns;
		cin >> columns;

		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= columns; j++) {
				scanf("%d", &sticker[i][j]);
			}
		}

		DP[0][1] = sticker[0][1];
		DP[1][1] = sticker[1][1];

		for (int t = 2; t <= columns; t++) {
			DP[0][t] = max(DP[1][t - 1], DP[1][t - 2]) + sticker[0][t];
			DP[1][t] = max(DP[0][t - 1], DP[0][t - 2]) + sticker[1][t];
		}

		printf("%d\n", max(DP[0][columns], DP[1][columns]));
	}

	return 0;
	

}