#include <iostream>
#include <algorithm>
using namespace std;

int num_of_items;
int weight_limit;
int weights_of_items[100001];
int value_of_items[1001];
int dp[100001];

int main() {

	cin >> num_of_items;
	cin >> weight_limit;

	for (int i = 1; i <= num_of_items; i++) {
		cin >> weights_of_items[i];
		cin >> value_of_items[i];
		for (int j = weight_limit; j >= weights_of_items[i]; j--) {
			dp[j] = max(dp[j - weights_of_items[i]] + value_of_items[i], dp[j]);
		}
	}
	cout << dp[weight_limit];
	return 0;
}