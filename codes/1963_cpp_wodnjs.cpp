#include<iostream>
#include<queue>
#include<utility>

using namespace std;
bool not_prime[10000];
int vis[10000];
void prime_checker();
void bfs(int, int);
void clear_vis();
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t_case;
	cin >> t_case;
	prime_checker();
	for (int t = 0; t < t_case; t++)
	{
		int from, to;
		cin >> from >> to;
		bfs(from, to);
		clear_vis();
	}
	return 0;
}
void prime_checker() {
	for (int i = 2; i *i < 10000; i++)
	{
		if (not_prime[i] == false) 
		{
			for (int j = 2 * i; j < 10000; j += i)
			{
				not_prime[j] = true;
			}
		}
	}
}
void clear_vis() {
	for (int i = 1000; i < 10000; i++)
	{
		vis[i] = 0;
	}
}
void bfs(int from, int to) {
	int from_arr[4];
	queue<int> q;
	vis[from] = 1;
	q.push(from);
	while (!q.empty())
	{
		int front_num = q.front();
		from_arr[0] = q.front()/ 1000;
		from_arr[1] = (q.front()% 1000) / 100;
		from_arr[2] = ((q.front() % 1000) % 100) / 10;
		from_arr[3] = q.front() % 10;
		q.pop();
	
		if (front_num== to) 
		{
			cout << vis[front_num]-1<<'\n';
			return;
		}
		for (int i = 1; i < 10; i++)//맨 앞자리 수는 0이 올 수 없다.
		{
			if (from_arr[0] == i) continue;
			int cmp = i * 1000 + from_arr[1] * 100 + from_arr[2] * 10 + from_arr[3];
			if (!not_prime[cmp]&&vis[cmp]==0)
			{
				q.push(cmp);
				vis[cmp] = vis[front_num] + 1;
			}
		}
		for (int i = 0; i < 10; i++)
		{
			if (from_arr[1] == i) continue;
			int cmp = from_arr[0] * 1000 + i * 100 + from_arr[2] * 10 + from_arr[3];
			if (!not_prime[cmp] && vis[cmp] == 0)
			{
				q.push(cmp);
				vis[cmp] = vis[front_num] + 1;
			}
		}
		for (int i = 0; i < 10; i++)
		{
			if (from_arr[2] == i) continue;
			int cmp = from_arr[0] * 1000 + from_arr[1] * 100 + i * 10 + from_arr[3];
			if (!not_prime[cmp] && vis[cmp] == 0)
			{
				q.push(cmp);
				vis[cmp] = vis[front_num] + 1;
			}
		}
		for (int i = 0; i < 10; i++)
		{
			if (from_arr[3] == i) continue;
			int cmp = from_arr[0] * 1000 + from_arr[1] * 100 + from_arr[2] * 10 + i;
			if (!not_prime[cmp] && vis[cmp] == 0)
			{
				q.push(cmp);
				vis[cmp] = vis[front_num] + 1;
			}
		}
	}
	cout << "Impossible\n";
	return;
}
