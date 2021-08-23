#include<iostream>

using namespace std;
bool not_prime[100000000];
bool check_surprise(int x,int digit);
int main() {
	int digit;
	cin >> digit;
	not_prime[0] = not_prime[1] = true;
	for (int i = 2; i*i < 100000000; i++)
	{
		if (!not_prime[i]) {
			for (int j = i * i; j < 10000000; j += i)
			{
				not_prime[j] = true;
			}
		}
	}//소수는 false값 가지도록 함.
	int start = 1;
	int end = 10;
	for (int i = 1; i < digit; i++)
	{
		start *= 10;
		end *= 10;
	}
	int cnt = 0;
	for (int i = start; i < end; i++)
	{
		if (check_surprise(i,digit))
			cout << i << '\n';
	}
	return 0;
}
bool check_surprise(int x,int digit) {
	if (digit == 0) {
		return true;
	}
	if (not_prime[x])
		return false;
	x /= 10;
	return check_surprise(x, digit - 1);
}

