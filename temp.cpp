#include<iostream>
using namespace std;


bool isOk(string str) {
    for(int b = 0, e = str.size() - 1; b < e; b++, e--) {
        if(str[b] != str[e])
            return false;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        int x;
        cin >> x;
        int len = 0;
        string s = "";
        for(;x != 0; x = x >> 1) 
            s.push_back((x & 1 ? '1' : '0'));
        cout << (isOk(s) ? "YES" : "NO") << endl;
    }
}



#include<iostream>
#include<queue>
using namespace std;
class Node {
    public:
    int v;
    int l, r;
    Node() {
    }
};
Node nodes[1000];
bool isRoot[1000];
int N;
bool bfs() {
    int root = 0;
    while(!isRoot[root])
        root++;
    queue<int> q;
    q.push(root);
    q.push(-1);
    int pre = -1, cur = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        if(node == -1) {
            if(pre >= cur)
                return false;
            if(!q.empty())
                q.push(-1);
            pre = cur;
            cur = 0;
        } else {
            Node& temp = nodes[node];
            cur += temp.v;
            if(temp.l != -1)
                q.push(temp.l);
            if(temp.r != -1)
                q.push(temp.r);
        }
    }
    return true;
}
int main() {
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> N;
        for(int n = 0; n < N; n++)
            isRoot[n] = true;
        for(int n = 0; n < N; n++) {
            int v, l , r;
            cin >> v >> l >> r;
            nodes[n].v = v;
            if(l != -1) 
                isRoot[l] = false;
            nodes[n].l = l;
            if(r != -1)
                isRoot[r] = false;
            nodes[n].r = r;
        }
        cout << (bfs() ? "YES" : "NO") << endl;
        
    }
}




#include<iostream>
#include<vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        int k, m;
        cin >> k >> m;
        if(m == 0) {
            cout << (1 + 29 / (k + 1)) << endl;
            continue;
        }  
        vector<int> fix(m);
        for(int i = 0; i < m; i++)
            cin >> fix[i];
        //e - b - 1 >= k, e - b - 1 - k >= n * (k + 1), n <= (e - b - 1 - k) / (k + 1)
        int res = m;
        for(int b = -1, e = 0; b < m; b++, e++) //30 - 1 = 29 /  
        {
            if(b == -1) 
                res += (fix[e] - 1) / (k + 1);       
            else if(e == m)
                res += (30 - fix[b]) / (k + 1);
            else
                res += (fix[e] - fix[b] - 1 - k) / (k + 1);
        }
        cout << res << endl;
    }
}