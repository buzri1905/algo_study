#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
int dists[101];
int sumOfdists[101];

int main(void)
{   
    int testCase;
    scanf("%d", &testCase);
    while (testCase--)
    {
        int numOfRooms, numOfPaths;
        scanf("%d %d", &numOfRooms, &numOfPaths);
        vector<pair<int, int> > edges[10001];
        for (int i = 0; i < 101; i++)
            sumOfdists[i] = 0;

        for (int i = 0; i < numOfPaths; i++)
        {
            int from, to, cost;
            scanf("%d %d %d", &from, &to, &cost);
            edges[from].push_back(make_pair(to, cost));
            edges[to].push_back(make_pair(from, cost)); // 양방향
        }

        int numOfFriends;
        scanf("%d", &numOfFriends);

        for (int i = 0; i < numOfFriends; i++)
        {
            int startVertex;
            for(int j=0; j<101; j++)
                dists[j]=-1;
            scanf("%d", &startVertex);
            priority_queue<pair<int, int> > shortDist;
            shortDist.push(make_pair(0, startVertex));
            while (!shortDist.empty())
            {
                int dist = -shortDist.top().first, node = shortDist.top().second;
                shortDist.pop();
                if (dists[node] != -1)
                    continue;
                dists[node] = dist;
                for (vector<pair<int, int> >::iterator iter = edges[node].begin(); iter != edges[node].end(); iter++)
                {
                    if (dists[iter->first] == -1)
                        shortDist.push(make_pair(-(dist + iter->second), iter->first));
                }
            }
            for (int j = 1; j <= numOfRooms; j++)
            {
                sumOfdists[j] += dists[j];
            }
        }

        int result = -1;
        int num;
        for (int i = 1; i <= numOfRooms; i++)
        {
            if (result == -1 || sumOfdists[i] < result)
            {
                result = sumOfdists[i];
                num = i;
            }
        }

        printf("%d\n", num);
    }

     return 0;
}

