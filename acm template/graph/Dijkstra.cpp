#include<bits/std++>
//输入是邻接表， edges[i]表示i到first的cost是second
/*
* 使用注意点
* 1. 优先级队列是最小堆
* 2. N是edges数组的最大值，而不是n, 需要定义为宏
* 3. 代码编号是按照从1 - n, 而不包括0， 需要在标示为number的地方修改
*/

typedef pair<int, int> Edge;
struct cmp {
    bool operator () (Edge &a, Edge &b)  {
        return a.second > b.second;
    }
};
void dijkstra(int edges[][N], int n, int start, int *res) {
    for(int i = 1; i <= n; i++)//number
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
        for(int i = 1; i <= n; i++){//number
            if(edges[edge.first][i] != INT_MAX){
                q.push(make_pair(i, edges[edge.first][i] + edge.second)); //relax
         //       cout << " " << i << " ";
            }
        }
        //cout << " ) ";
    }
    //printf("\n");
}


void dijkstra(int** edges, int n, int start, int *res) {
    priority_queue<Edge&> q;
    q.push(make_pair(start, 0));
    while(!q.empty()) {
        Edge& edge = q.top(); q.pop();
        if(res[edge.first] != INT_MAX)
            continue;
        res[edge.first] = edge.second;
        for(int i = 0; i < n; i++)
            if(edges[next][i] != INT_MAX)
                q.push(make_pair(i, edges[next][i] + edge.second)); //relax
    }
}
//不使用优先级队列
int map[310][310],dis[310];
int a[310];
int n;

void dijkstra(int x)
{
    int visit[310];
    int i,j,min,next=0;
    memset(visit,0,sizeof(visit));
    for(i=1;i<=n;++i)
    {
        dis[i]=map[x][i];
    }
    visit[x]=1;
    for(i=2;i<=n;++i)
    {
        min=INF;
        for(j=1;j<=n;++j)
        {
            if(!visit[j]&&min>dis[j])
            {
                next=j;
                min=dis[j];
            }
        }
        visit[next]=1;
        for(j=1;j<=n;++j)
        {
            if(!visit[j]&&dis[j]>dis[next]+map[next][j])
                dis[j]=dis[next]+map[next][j];
        }
    }
}




void floyd(int n)//warshall-floyd 最短路径算法（每对顶点之间的最短路径）
{
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
}



// Dijkstra 算法要求图 G 中边的权值均为非负，而 Bellman-Ford 算法能适应一般的情况（即存在负权边的情况）。一个实现的很好的 Dijkstra 算法比 Bellman-Ford 算法的运行时间要低。Bellman-Ford 算法采用动态规划（Dynamic Programming）进行设计，实现的时间复杂度为 O(V*E)，其中 V 为顶点数量，E 为边的数量。Dijkstra 算法采用贪心算法（Greedy Algorithm）范式进行设计，普通实现的时间复杂度为 O(V2)，若基于 Fibonacci heap 的最小优先队列实现版本则时间复杂度为 O(E + VlogV)。

/*：

对于图中的每条边：如果起点 u 的距离 d 加上边的权值 w 小于终点 v 的距离 d，则更新终点 v 的距离值 d；
检测图中是否有负权边形成了环，遍历图中的所有边，计算 u 至 v 的距离，如果对于 v 存在更小的距离，则说明存在环；
distSet表示距离数组
缺点就是虽然能检测负权值回路，但是解决不了有负权值回路的最短路径问题。 还有就是时间复杂度比较高。 O(|V| * |E|).
其实实现的原理就是：每次对当前整个图进行一次松弛操作。一共进行|V|次。 每次的松弛操作都是|V|-1次的松弛判断
需要坐下面的修改
1. N设置为节点个数, E表示边的个数，m表示的是邻接表， edges设置为边的向量，需要对所有边做relax，所以这样效率高
2. 注意这里下标用的是[1, n]
3. 可以是int或者double类型， 需要定义INF宏
*/
typedef ELE int;
bool BellFord(int start, int E, int N){
    for(int i = 0; i < n; i++)
        dis[i] = INF;
    dis[start] = 0;
    bool update = false;
    for (int i = 1; i <= N - 1; i++) { //cycle the num of vertex
        for(int j = 1; j <= E; j++) {
            pair<int, int> e = edges[j];
            ELE w = t[e.first][e.second];
            if(dis[e.first] != INF && dis[e.first] + m < dis[e.second]) {
                dis[e.second] = dis[e.first] + m;
                if(i == N - 1)
                    update = true;
            }
        }
    }
    return update;
}


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
