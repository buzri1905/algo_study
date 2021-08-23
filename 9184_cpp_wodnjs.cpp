#include<iostream>

using namespace std;
int d[101][101][101];
bool vis[101][101][101];
int get_w(int a, int b, int c );
int main() {
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			for (int k = 0; k < 101; k++)
			{
				if (i <= 50 || j <= 50 || k <= 50)
				{
					d[i][j][k] = 1;
					vis[i][j][k] = true;
				}
			}
		}
	}
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			for (int k = 0; k < 101; k++)
			{
				get_w(i, j, k);
			}
		}
	}
	while (1) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			return 0;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << d[a+50][b+50][c+50] << '\n';
	}
	return 0;
}
int get_w(int a, int b, int c) {

	if (vis[a][b][c])
		return d[a][b][c];
	if (a > 70 || b > 70 || c > 70)
	{
		d[a][b][c] = get_w(70, 70, 70);
		vis[a][b][c] = true;
		return d[a][b][c];
	}
	if (a < b && b < c) {
		d[a][b][c] = get_w(a,b,c-1)+get_w(a,b-1,c-1)-get_w(a,b-1,c);
		vis[a][b][c] = true;
		return d[a][b][c];

	}
	d[a][b][c] = get_w(a - 1, b, c) + get_w(a - 1, b - 1, c) + get_w(a - 1, b, c - 1) - get_w(a - 1, b - 1, c - 1);
	vis[a][b][c] = true;
	return d[a][b][c];
}
