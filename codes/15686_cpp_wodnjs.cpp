#include<cstdio>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int> > home;
vector<pair<int,int> > bbq;
int row, max_bbq;
int map[51][51];
int min_dist=1000;
int arr[14];
int find_chi_dist()
{
    int sum=0;
    
    for (int i = 0; i < home.size(); i++)
    {
        int dis=1000;
        int home_x=home[i].first;
        int home_y=home[i].second;
        for (int j = 0; j < max_bbq; j++)
        {
            int temp=min(dis,abs(bbq[arr[j]].first-home_x)+abs(bbq[arr[j]].second-home_y));
            if(dis>temp)
                dis = temp;
        }
        sum+=dis;
    }
    return sum;
}
void urban_cki_dist(int idx, int m){
    if(idx==max_bbq)
        return;
    if(arr[idx]==(bbq.size()-1) && m!=max_bbq)
        return;
    if(m==max_bbq)
    {
        int x=find_chi_dist();
        if(min_dist>x)
            min_dist=x;
    }
    for (int i = idx+1; i < bbq.size(); i++)
    {
        arr[idx+1]=i;
        urban_cki_dist(idx+1,m+1);
    }
}
int main(){
   
   scanf("%d %d",&row,&max_bbq);
   // cin>>row>>max_bbq;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < row; j++){
            //cin>>map[i][j];
            scanf("%d",&map[i][j]);
            if(map[i][j]==1)
                home.push_back(make_pair(i,j));
            if(map[i][j]==2)
                bbq.push_back(make_pair(i,j));
        }
    }
    for (int i = 0; i < bbq.size(); i++)
    {
        arr[0]=i;
        urban_cki_dist(0, 1);
    }
    //cout<<min_dist<<'\n';
    printf("%d\n",min_dist);
}
