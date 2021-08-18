#include<iostream>

using namespace std;
int arrange[10];
char inequ[9];
bool used[10];
long long minr = 9876543211;
int min_arr[10];
long long maxr = 0;
int max_arr[10];
void make_arr(int idx,int total);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int _num;
	cin >> _num;
	for (int n = 0; n < _num; n++)
	{
		cin >> inequ[n];
	}
	make_arr(0,_num);
	for (int i = 0; i < _num + 1; i++)
	{
		cout << max_arr[i];
	}
	cout << '\n';
	for (int i = 0; i < _num + 1; i++)
	{
		cout << min_arr[i];
	}
	cout << '\n';
	return 0;
}
void make_arr(int idx,int _num) {
	if (idx == _num+1)
	{
		for (int i = 0; i < _num; i++)
		{
			if (inequ[i] == '>' && arrange[i] < arrange[i + 1])
					return;
			if (inequ[i] == '<')
			{
				if (arrange[i] > arrange[i + 1])
					return;
			}
		}
		long long val=0;
		for (int i = 0; i < _num+1; i++)
		{
			val *= 10;
			val += arrange[i];
		}
		if (minr > val)
		{
			minr = val;
			for (int i = 0; i < _num + 1; i++)
			{
				min_arr[i] = arrange[i];
			}
		}
		if (maxr < val)
		{
			maxr = val;
			for (int i = 0; i < _num + 1; i++)
			{
				max_arr[i] = arrange[i];
			}
		}
	}
	for (int i = 0; i <= 9; i++)
	{
		if (used[i]) continue;
		used[i] = true;
		arrange[idx] = i;
		make_arr(idx + 1,_num);
		used[i] = false;
	}
	return;
}
