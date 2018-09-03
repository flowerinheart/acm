#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<climits>
#include<queue>
#include <list>
#include<vector>
#include <cstring>
#include<utility>
using namespace std;
vector<pair<int, int>> edges[2501];
int dis[2501];
struct Node {
    int v, w;
    bool operator <(const Node& b) const {
        return w > b.w;
    }
    Node(int v, int w):v(v), w(w){};

};
priority_queue<Node> q;
int dij(int ts, int te) {
    dis[ts] = 0;
    q.push(Node(ts, 0));
    while(!q.empty()) {
        int v = q.top().v;
        int w = q.top().w;
        //cout << "node: " << v << endl;
        q.pop();
        if(v == te)
            return w;
        if(w > dis[v])
            continue;
        for(int i = 0; i < edges[v].size(); i++) {
            int tv = edges[v][i].first, tw = edges[v][i].second;
            //cout << "compare " << w + tw << " " << dis[tv] << " " << INT_MAX << endl;
            if(w + tw < dis[tv]) {
                dis[tv] = w + tw;
                q.push(Node(tv, w + tw));
            }
        }
    }
    return -1;
}

/*
 *
1 4 3
2 4 2
2 4 3
3 4 3
5 7 5
5 6 3
6 1 1
6 3 4
7 2 2
7 3 3
7 2 1
 */
int main() {
    int T, C, ts, te;
    cin >> T >>  C >> ts >> te;
    int s, e, c;
    for(int i = 0; i < C; i++) {
        cin >> s >> e >> c;
        edges[s].push_back(make_pair(e, c));
    }
    for(int i = 1; i <= T; i++)
        dis[i] = INT_MAX;
    //memset(&dis[0], INT_MAX, sizeof(int) * 2501);
    cout << dij(ts, te) << endl;
}


