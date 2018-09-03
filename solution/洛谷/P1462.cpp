//
// Created by mhj on 18-8-28.
//

//这是一道二分答案
//二分答案的本质就是枚举，在已知解范围的情况下用二分的手段从解的范围中寻找出解
//
//题目："他所经过的所有城市中最多的一次收取的费用的最小值是多少？"
//这句话的意思实际上是指：
//         对于一条路径 a ， 定义函数f(a)。
//         对于路径上的所有点权构成的集合s， 满足f(a)=max(s)
//         而对于一张图，从起点到终点存在多条路径a1,a2,a3...
//         对于所有可能的路径a1,a2,a3...，均存在对应的f(a1),f(a2),f(a3)...
//         求f(a1),f(a2),f(a3)...中的最小值
//基本的思想就是二分，二分什么呢？
//         被二分的一定是一个包含解的集合
//         首先，你的f(a)是等于max(s)的，f(a)一定是一个点权，即我们所求的解为一个点权
//         而你走过的每一个路径中的最小点权f(a)一定在一个区间内:即整张图的最低点权与最高点权之间
//         通过对整张图的点权进行排序，然后做二分，在整张图的点权集合中找出一个点权，这个点权是min(  f(a1)  f(a2)  f(a3) ... ) 就是本题答案了
//我们已经找到了解的集合：点权集合。
//二分点权集合，每一次都会得到一手点权，这个点权将是路径上所有点点权的天花板
//在整张图上寻找路径，但是因为我们得到了一个天花板，所以点权大于这个天花板的点就不能选
//寻找路径也应该是最短路，因为你会扣血，所以需要找到扣血最少的路径
//要是找到的这个路径上的扣血总和依然致死，那么我们找到的点权就是无效的，继续向上二分，扩大点权范围
//要是不致死，那么分出的点权就是有效的，继续向下二分，缩小点权范围
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;
const int mx=10010;
const int mm=100010;
const int inf=0x3f3f3f3f;
//边储存
struct e{
    int t,nxt,w;
}edge[mm];
int cnt;
int head[mx];
int n,m,hp;
int f[mx];
//点权集合
int u[mx];
int dist[mx];
bool v[mx];
bool check(int top)
{
    //标准spfa
    memset(dist,inf,sizeof(dist));
    memset(v,0,sizeof(v));
    queue<int> q;
    v[1]=true;dist[1]=0;
    q.push(1);
    while(!q.empty())
    {
        int temp=q.front();q.pop();
        v[temp]=false;
        for(int i=head[temp];i!=0;i=edge[i].nxt)
        {
            int to=edge[i].t;
            int wr=edge[i].w;
            if(dist[to]>dist[temp]+wr&&f[to]<=top/*过滤掉点权过大的点*/)
            {
                dist[to]=dist[temp]+wr;
                if(v[to]==false)
                {
                    v[to]=true;
                    q.push(to);
                }
            }
        }
    }
    //此时的dist[n]即为从暴风城到奥格瑞玛的最小损血
    if(dist[n]<=hp)
    {
        return true;
    }else{
        return false;
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&hp);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&f[i]);
        u[i]=f[i];
    }
    for(int i=1;i<=m;i++)
    {
        static int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        cnt++;
        edge[cnt].t=b;
        edge[cnt].w=c;
        edge[cnt].nxt=head[a];
        head[a]=cnt;
        cnt++;
        edge[cnt].t=a;
        edge[cnt].w=c;
        edge[cnt].nxt=head[b];
        head[b]=cnt;
    }
    //开始二分
    sort(u+1,u+n+1);
    //这里做一个判断：如果点权大小在不受限制的情况下，依然无法出现损血量小于hp的路径，直接结束程序
    if(check(inf)==false)
    {
        printf("AFK\n");
        return 0;
    }
    int l=1,r=n;//得到点权集合的区间
    int mid;
    int ans=0;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(check(u[mid])==true)
        {
            ans=u[mid];
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    //二分完成后所得的就是我们需要的min(  f(a1)  f(a2)  f(a3) ... )
    printf("%d\n",ans);
    return 0;
}
