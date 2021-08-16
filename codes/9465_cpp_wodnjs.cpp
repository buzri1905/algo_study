#include<iostream>
#include<algorithm>
using namespace std;
int score[100000][2];
int res[3][3];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t_case;
	cin >> t_case;
	for (int i = 0; i < t_case; i++)
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
		res[0][0] = 0;//둘다 빈상태
		res[0][1] = score[0][0];//위에거
		res[0][2] = score[0][1];//아래거
		res[1][0] = max(res[0][1], res[0][2]);
		res[1][1] = res[0][2] + score[1][0];
		res[1][2] = res[0][1] + score[1][1];
		for (int i = 2; i < col; i++)
		{
			res[2][0] = max(max(res[1][0], res[1][
				1]), res[1][2]);
			res[2][1] = max(res[1][2], res[1][0]) + score[i][0];
			res[2][2] = max(res[1][1], res[1][0]) + score[i][1];
			for (int j = 0; j < 3; j++)
			{
				res[0][j] = res[1][j];
				res[1][j] = res[2][j];
			}
		}
		cout << max(max(res[1][0], res[1][1]), res[1][2])<<'\n';
	}
	return 0;
}
