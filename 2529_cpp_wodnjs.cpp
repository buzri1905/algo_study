#include<iostream>

using namespace std;
int arrange[10];
char inequ[9];
bool used[10];

int min_arr[10];
int max_arr[10];
void make_arr(int idx,int total);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int num;
	cin >> num;
	for (int n = 0; n < num; n++)
	{
		cin >> inequ[n];
	}
	
	make_arr(0,num);
	for (int i = 0; i < num + 1; i++)
	{
		cout << max_arr[i];
	}
	cout << '\n';
	for (int i = 0; i < num + 1; i++)
	{
		cout << min_arr[i];
	}
	cout << '\n';
	return 0;
}
void make_arr(int idx,int num) {
	static long long minr = 9876543211;
	static long long maxr = 0;
	if (idx == num+1)
	{
		for (int i = 0; i < num; i++)
		{
			if ((inequ[i] == '>' && arrange[i] < arrange[i + 1]) || (inequ[i] == '<' && arrange[i] > arrange[i + 1]))
				return;
		}
		long long val=0;
		for (int i = 0; i <= num; i++)
		{
			val *= 10;
			val += arrange[i];
		}
		if (minr > val)
		{
			minr = val;
			for (int i = 0; i < num + 1; i++)
			{
				min_arr[i] = arrange[i];
			}
		}
		if (maxr < val)
		{
			maxr = val;
			for (int i = 0; i < num + 1; i++)
			{
				max_arr[i] = arrange[i];
			}
		}
		return;
	}
	for (int i = 0; i <= 9; i++)
	{
		if (used[i]) 
			continue;
		used[i] = true;
		arrange[idx] = i;
		make_arr(idx + 1,num);
		used[i] = false;
	}
	return;
}
