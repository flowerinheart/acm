#include <bits/stdc++.h>
using namespace std;

int N, M;
int m[601][601];
bool visited[601][601];

int t1[4] = {0 , 1, 0, -1};
int t2[4] = {1, 0, -1, 0};
int ax, ay, bx, by;
int res = 0;
void dfs(int i, int j, int height) {
        if (i < 0 || j < 0 || i >= N || j >= M || visited[i][j] || !(m[i][j] > height)) 
            return;
        if(i == bx && j == by) {
            res++;
            return;
        }
        visited[i][j] = true;
        for(int k = 0; k < 4; k++)
            dfs(i + t1[k], j + t2[k], m[i][j]);
}


int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++) {
            cin >> m[i][j];
            visited[i][j] = false;
        }
    cin >> ax >> ay >> bx >> by;
    dfs(ax, ay, -1);
    cout << res;
}