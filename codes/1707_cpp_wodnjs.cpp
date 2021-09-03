#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int vis[20001];
void init_vis(int vtx);
bool bip_graph(int vtx,vector<int> v[]);
int main() {

	int tcase;
	cin >> tcase;
	for (int i = 0; i < tcase; i++)
	{
		int vtx, edge;
		vector<int> v[20001];
		cin >> vtx >> edge;
		init_vis(vtx);
		for (int j = 0; j < edge; j++)
		{
			int from, to;
			cin >> from >> to;
			v[from].push_back(to);
			v[to].push_back(from);
		}
		bool pass=true;
		for (int k = 1; k <=vtx ; k++)
		{
			if (!bip_graph(k, v)) {
				cout << "NO\n";
				pass = false;
				break;
			}
		}
		if(pass)
			cout<<"YES\n";
	}
	return 0;
}
void init_vis(int vtx) {
	for (int i = 1; i <=vtx; i++)
	{ 
		vis[i] = 0;
	}
}
bool bip_graph(int vtx, vector<int> v[]) {
	if (vis[vtx] != 0)
		return true;
	queue<int> q;
	q.push(vtx);
	vis[vtx] = 1;
	while (!q.empty()) {
		int cur_vtx = q.front();
		q.pop();
		for (int i = 0; i < v[cur_vtx].size(); i++)
		{
			if (vis[v[cur_vtx][i]]!=0)
			{
				if (vis[cur_vtx] == vis[v[cur_vtx][i]])
					return false;
				continue;
			}
			q.push(v[cur_vtx][i]);
			vis[v[cur_vtx][i]] = vis[cur_vtx] * (-1);
		}
	}
	return true;
}

