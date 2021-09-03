#include <iostream>
#include <algorithm>
using namespace std;

int num_of_items;
int weight_limit;
int weights_of_items[100001];
int value_of_items[1001];
int dp[101][100001];

int dp_set(int items, int Weight_limit, int* w, int* v);

int main(){
	
	cin >> num_of_items;
	cin >> weight_limit;

	for (int i = 1; i <= num_of_items; i++) {
		cin >> weights_of_items[i];
		cin >> value_of_items[i];
	}
	cout << dp_set(num_of_items, weight_limit,weights_of_items,value_of_items);
	return 0;
}

int dp_set(int items, int Weight_limit, int * w, int* v) {

	for (int j = 1; j <= items; j++) {
		for (int k = 1; k <= Weight_limit; k++) {
			if (w[j] >k)
				dp[j][k] = dp[j - 1][k];
			else {
				dp[j][k] = max(dp[j - 1][k], v[j] + dp[j - 1][k - w[j]]);
			}
		}
	}

	return dp[items][Weight_limit];
}
