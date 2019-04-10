
// Prim算法流程：
// 对图G（V,E）设置集合S，存放已经被访问的顶点，然后执行n次下面的两个步骤（n为顶点个数）：
// 每次从集合V-S中选择与集合S的最短距离最小的一个顶点（记为u），访问并加入集合S，同时把这条离集合最近的边加入到最小生成树中。
// 令顶点u为中介点，优化所有从u能到达的未访问的顶点v与集合S之间的最短距离。


const int INF = 1000000000;
 
/*Prim算法求无向图的最小生成树，返回最小生成树的边权之和*/
int Prim(int n, int s, vector<vector<int>> G, vector<bool>& vis, vector<int>& d)
{
       /*
       param
       n:                                     顶点个数
       s:                                     初始点
       G:                                     图的邻接矩阵
       vis:                                   标记顶点是否已被访问
       d:                                     存储顶点与集合S的最短距离
       return:                                最小生成树的边权之和
       */
       fill(d.begin(), d.end(), INF);                                        //初始化最短距离，全部为INF
       d[s] = 0;                                                             //初始点与集合S的距离为0
       int sum = 0;                                                          //记录最小生成树的边权之和
       for (int i = 0; i < n; ++i)
       {
              int u = -1;                                                    //u使得d[u]最小
              int MIN = INF;                                                 //记录最小的d[u]
              for (int j = 0; j < n; ++j)                                    //开始寻找最小的d[u]
              {
                     if (vis[j] == false && d[j] < MIN)
                     {
                           MIN = d[j];
                           u = j;
                     }
              }
              //找不到小于INF的d[u]，则剩下的顶点与集合S不连通
              if (u == -1)
                     return -1;
              vis[u] = true;                                                  //标记u为已访问
              sum += d[u];                                                    //将与集合S距离最小的边加入到最小生成树
              for (int v = 0; v < n; ++v)
              {
                     //v未访问 && u能够到达v && 以u为中介点可以使v离集合S更近
                     if (vis[v] == false && G[u][v] != INF && G[u][v] < d[v])
                           d[v] = G[u][v];                                    //更新d[v]
              }
       }
       return sum;                                                            //返回最小生成树的边权之和
}
