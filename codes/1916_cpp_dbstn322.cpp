#include <cstdio>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

vector<pair<int, int>> edges[100001];
priority_queue<pair<int, int>> shortDist;
int dists[1001];

int main(void)
{
    int numOfVertexes, numOfEdges;
    scanf("%d", &numOfVertexes);
    scanf("%d", &numOfEdges);

    for (int i = 1; i <= numOfVertexes; i++)
        dists[i] = -1;

    for (int i = 0; i < numOfEdges; i++)
    {
        int from, to, cost;
        scanf("%d %d %d", &from, &to, &cost);
        edges[from].push_back(make_pair(to, cost));
    }

    int startVertex, lastVertex;
    scanf("%d %d", &startVertex, &lastVertex);

    shortDist.push(make_pair(0, startVertex));
    while (!shortDist.empty())
    {
        int dist = -shortDist.top().first, node = shortDist.top().second;
        shortDist.pop();
        if (dists[node] != -1)
            continue;
        dists[node] = dist;
        for (vector<pair<int, int>>::iterator iter = edges[node].begin(); iter != edges[node].end(); iter++)
            if (dists[iter->first] == -1)
                shortDist.push(make_pair(-(dist + iter->second), iter->first));
    }

    printf("%d", dists[lastVertex]);
}