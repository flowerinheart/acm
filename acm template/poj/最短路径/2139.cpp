#include<cstdio>
#include<functional>
#include<algorithm>
#include<utility>
#include<queue>
#include<climits>
#include<cstring>
#include<iostream>
using namespace std;
#define INF 0x3f3f3f
#define N 310
int map[N][N],dis[N];
int n;
int a[N];

typedef pair<int, int> Edge;
struct cmp {
    bool operator () (Edge &a, Edge &b)  {
        return a.second > b.second;
    }
};
void dijkstra(int edges[][N], int n, int start, int *res) {
    for(int i = 1; i <= n; i++)
        res[i] = INT_MAX;
    priority_queue<Edge, vector<Edge>, cmp> q;
    q.push(make_pair(start, 0));
    while(!q.empty()) {
        Edge edge = q.top(); q.pop();
        if(res[edge.first] != INT_MAX)
            continue;
        res[edge.first] = edge.second;
        //printf(" %d %d ", edge.first, res[edge.first]);
         //   cout << " ( ";
        for(int i = 1; i <= n; i++){
            if(edges[edge.first][i] != INT_MAX){
                q.push(make_pair(i, edges[edge.first][i] + edge.second)); //relax
         //       cout << " " << i << " ";
            }
        }
        //cout << " ) ";
    }
    //printf("\n");
}
int main()
{
    int m,i,num,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=n;++j)
            {
                if(i==j)
                    map[i][j]=0;
                else
                    map[i][j]=map[j][i]=INT_MAX;//初始化一定要为极大值
            }
        }
        while(m--) {
            scanf("%d",&num);
            for(i = 0; i < num; i++){
                cin >> a[i];
            }
            for(i=0;i<num;++i) {
                for(j=0;j<num;++j) {
                    if(a[i]!=a[j])
                        map[a[i]][a[j]]=map[a[j]][a[i]]=1;
                }
            }
        }
        double ans=INF;
        for(i=1;i<=n;++i)//枚举每一头牛
        {
            double sum=0;
            dijkstra(&map[0], n, i, &dis[0]);
            for(j=1;j<=n;++j)//记录到其他牛的度数之和
            {
                if(i!=j)
                    sum+=dis[j];
            }
            ans=min(ans,sum*1.0/(n-1));
        }
        printf("%d\n",(int)(ans*100));
    }
    return 0;
}
