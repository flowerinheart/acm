

6 2 3
2 1
3 4 5 6 1
样例输出
2
//请你求出树上距离这m个特殊点距离均不超过d的点的数量，包含特殊点本身
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
    for(int i = 0; i < n; i++)
        dis[i][i] = 0;
    vector<int> p(n, 0);
    vector<bool> visited(n, false);
    vector<int> s(m, 0);
    for(int i = 0; i < m; i++) 
        cin >> s[i];
    for(int i = 1; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    for(int i = 1; i < n; i++) {
        int cur = i;
        while(!visited[cur] && cur != 0) {
            dis[cur][p[cur]] = 1;
            dis[p[cur]][cur] = 1;
            visited[cur] = true;
            cur = p[cur];
        }
    }


    for(int k=0;k<n;k++)   
        for(int i=0;i<n;i++)   
            for(int j=0;j<n;j++)   {
                if(dis[i][k] != INT_MAX && dis[k][j] != INT_MAX && 
                    dis[i][j]>dis[i][k]+dis[k][j] )   
                    dis[i][j]=dis[i][k]+dis[k][j];   
            }
    int res = 0;
    for(int i = 0; i < n; i++) {
        bool flag = true;
        for(int j = 0; j < m && flag; j++) 
            if(dis[i][j] > d) 
                flag = false;
        if(flag)
            res += 1;
    }
    cout << res;
    return 0;
}