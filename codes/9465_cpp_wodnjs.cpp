#include<iostream>
#include<algorithm>
using namespace std;
int score[100000][2];
int res[2][3];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t_case;
	cin >> t_case;
	for (int t = 0; t < t_case; t++)
	{
		int col;
		cin >> col;
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < col; k++)
			{
				cin >> score[k][j];
			}
		}
		res[1][0] = 0;//둘다 빈상태
		res[1][1] = score[0][0];//위에거
		res[1][2] = score[0][1];//아래거
		for (int i = 1; i < col; i++)
		{
			res[0][0] = max(max(res[1][0], res[1][1]), res[1][2]);
			res[0][1] = max(res[1][2], res[1][0]) + score[i][0];
			res[0][2] = max(res[1][1], res[1][0]) + score[i][1];
			for (int j = 0; j < 3; j++)
			{
				res[1][j] = res[0][j];
			}
		}
		cout << max(max(res[1][0], res[1][1]), res[1][2])<<'\n';
	}
	return 0;
}
