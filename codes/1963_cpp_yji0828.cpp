#include <cstdio>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
queue<int> q;
bool prime[10001];
int bfs(int start, int dest);
void eratos();


int main() {
	int T;
	int start, dest;
	int ret_bfs;
	eratos();
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &start, &dest);
		ret_bfs = bfs(start, dest);
		if (ret_bfs != -1)
			printf("%d\n", ret_bfs);
		else
			printf("Impossible\n");
	}

}

void eratos() {
	memset(prime, true, sizeof(prime));
	for (int i = 2; i * i < 10000; i++) {
		for (int j = i * i; j < 10000; j += i)
			prime[j] = false;
	}
}

int bfs(int start, int dest) {
	int cur;
	int next;
	int check[10001];
	memset(check, -1, sizeof(check));
	q.push(start);
	check[start] = 0;
	int cur_q;

	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int i = 1000; i >= 1; i = i / 10) { //100
			for (int j = 0; j <= 9; j++) {
				if (j == (cur / i) % 10)
					continue;
				next = cur + (j * i) - ((cur % (i * 10)) / i) * i;
				if (next >= 1000 && prime[next] == true && check[next] == -1) {
					check[next] = check[cur] + 1;
					q.push(next);
				}
			}
		}
	}

	return check[dest];


}