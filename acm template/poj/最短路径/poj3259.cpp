#include<iostream>
#include<cstdio>
#include<utility>
#include<climits>
using namespace std;
#include<stdio.h>
#include<limits.h>
struct stu
{
    int a,b,c;
}edge[6000];
int dis[550],n,m;
const int INF = INT_MAX;
int bellmanford(int source, int E, int N)
{
    int i, j;
    for(i=1; i<=N; i++)
        dis[i]=INF;
    dis[source]=0;
    for(i=1; i<=N; i++)
        for(j=1; j<=m; j++)
            if(dis[edge[j].a] != INT_MAX && dis[edge[j].a] + edge[j].c < dis[edge[j].b]){
                if(i == N)
                    return true;
                dis[edge[j].b]=dis[edge[j].a]+edge[j].c;
            }
    return false;
}
int main()
{
    int T,i,j,k,flag;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&k);
        j=1;
        for(i=1;i<=m;i++){
            scanf("%d%d%d",&edge[j].a,&edge[j].b,&edge[j].c);
            j++;
            edge[j].a=edge[j-1].b;                           //路是双向的
            edge[j].b=edge[j-1].a;
            edge[j].c=edge[j-1].c;
            j++;
        }
        for(i=1;i<=k;i++){
            scanf("%d%d%d",&edge[j].a,&edge[j].b,&edge[j].c);
            edge[j].c=-edge[j].c;                                  //虫洞是单向的，时间为负
            j++;
        }
        m=j-1;
        flag=bellmanford(1, m, n);
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
/*
pair<int, int> edges[2501];
int t[501][501];
int dis[550],n,m;
typedef int ELE;
const ELE INF = INT_MAX;
bool bellFord(int start, int E, int N){
    for(int i = 1; i <= N; i++)
        dis[i] = INF;
    dis[start] = 0;
    for (int i = 1; i <= N; i++) { //cycle the num of vertex, 要循环N次是为了求update，一般来说N-1就已经求出最短路径了
        for(int j = 1; j <= E; j++) {
            pair<int, int> e = edges[j];
            ELE w = t[e.first][e.second];
            if(dis[e.first] != INF && dis[e.first] + w < dis[e.second]) {
                if(i == N)
                    return true;
                else
                    dis[e.second] = dis[e.first] + w;
            }
        }
    }
    return false;
}
int main()
{
    int T,i,j,k,flag;
    cin >> T;
    while(T--){
        cin >> n >> m >> k;
        j=0;
        int a, b, c;
        for(i=1;i<=m;i++){
            cin >> a >> b >> c;
            j++;
            edges[j].first = a; edges[j].second = b; t[a][b] = c;
            j++;
            edges[j].first = b; edges[j].second = a; t[b][a] = c; //路是双向的
        }
        for(i=1;i<=k;i++){
            cin >> a >> b >> c;
            j++;
            edges[j].first = a; edges[j].second = b; t[a][b] = -c;
        }
        if(bellFord(1, j, n))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
*/
