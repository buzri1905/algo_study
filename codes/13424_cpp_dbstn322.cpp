#include <cstdio>
#include <algorithm>

#define INF 10000

using namespace std;

int main(void)
{   
    int testCase;
    scanf("%d", &testCase);
    while (testCase--)
    {
        int numOfRooms, numOfPaths;
        scanf("%d %d", &numOfRooms, &numOfPaths);
        
        int edges[102][102];
        int sumOfDists[102];

        for(int i=1; i<=101; i++)
        {
            for(int j=1; j<=101; j++)
            {
                if(i==j) 
                    edges[i][j] = 0;
                else 
                    edges[i][j]= INF;
            }
        }

        for (int i = 1; i <= 101; i++) 
            sumOfDists[i] = 0;

        for (int i = 0; i < numOfPaths; i++)
        {
            int from, to, cost;
            scanf("%d %d %d", &from, &to, &cost);
            edges[from][to] = cost;
            edges[to][from] = cost;
        }

        for(int k=1; k<=numOfRooms; k++)
        {
            for(int i=1; i<=numOfRooms; i++)
            {
                for(int j=1; j<=numOfRooms; j++)
                {
                    edges[i][j] = min(edges[i][k]+edges[k][j], edges[i][j]);
                }
            }
        }

        int numOfFriends;
        scanf("%d", &numOfFriends);

        for (int i = 0; i < numOfFriends; i++)
        {
            int startVertex;
            scanf("%d", &startVertex);
           
            for (int j = 1; j <= numOfRooms; j++)
            {
                sumOfDists[j] += edges[startVertex][j];
            }
        }

        int result = sumOfDists[1];
        int roomNum = 1;

        for (int i = 2; i <= numOfRooms; i++)
        {
            if (sumOfDists[i] < result)
            {
                result = sumOfDists[i];
                roomNum = i;
            }
        }

        printf("%d\n", roomNum);
    }

     return 0;
}
