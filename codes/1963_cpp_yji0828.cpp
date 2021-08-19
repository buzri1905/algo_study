#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
queue<int> q;
int check[10001];
bool prime[10001];
void bfs(int start, int dest);
void eratos();


int main() {
	int T;
	int start, dest;
	eratos();
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		memset(check, -1, sizeof(check));
		scanf("%d %d", &start, &dest);
		bfs(start, dest);
		if (check[dest] != -1)
			printf("%d\n", check[dest]);
		else
			printf("Impossible\n");
	}

}

void eratos() {
	memset(prime, true, sizeof(prime));
	for (int i = 2; i < sqrt(10000); i++) {
		for (int j = i + i; j < 10000; j += i)
			prime[j] = false;
	}
}

void bfs(int start, int dest) {
	int cur;
	int next;
	q.push(start);
	check[start] = 0;

	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			string cur_s = to_string(cur);
			for (int j = 0; j <= 9; j++) {
				cur_s[i] = j + '0';
				next = stoi(cur_s);
				if (next >= 1000 && prime[next] == true && check[next] == -1) {
					check[next] = check[cur] + 1;
					q.push(next);
				}
			}
		}
	}


}