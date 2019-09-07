
// a large circular street with N consulates along it
// The consulates are numbered 1, 2, ..., N in clockwise order.
//  G guests, numbered 1, 2, ..., G will drive along the circular street for M minutes. 顺时针或者逆时针
//  The i-th guest starts at the consulate numbered Hi and at the end of each minute will drive to an adjacent consulate.
//  Each consulate will only remember the guest that visited them last. If there are multiple guests who visited last, then the consulate will remember all of those guests.
//  For each guest, determine how many consulates will remember them.


//模拟解决
//1. 优化点，取余
//2. 用一个数组，记录到达的最新人员的编号，以及时间
//3. 对于每一个个人，循环的去更新这个数组

//3. 只要遇到的第一个点不是最新，那么接下来（指定长度）就都不是最新了，但是，在那之后的
//添加一个长度相关的记录，用于快速跳过不是我的，还有持续的长度, 
//每个客人会有一个长度, 沿着长度去覆盖，中间的跳过 

// clockwise guest, they will drive to the (j+1)-th 
// The i-th line contains the integer Hi followed by a single character; C if the i-th guest is a clockwise guest or A if the i-th guest is an anti-clockwise guest.

#include<iostream>
#include<vector>
using namespace std;
int times[100000];
vector<int> guests[100000];
int count[100000];

inline int add(int a, int b, int n) {
    return (a + b + n) % n;
}

void update(int h, int t, int i) {
     vector<int>& guest = guests[h];
     if(t >= times[h]) {
        if(t > times[h])
            guest.erase(guest.begin(), guest.end());
        times[h] = t;
        guest.push_back(i);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    cin >> T;
    int n, g, m;
    int h;
    char d;
    for(int t = 0; t < T; t++)
    {
        cin >> n >> g >> m;
        for(int i = 0; i < n; i++) {
            times[i] = -1;
            vector<int>& guest = guests[i];
            guest.erase(guest.begin(), guest.end());
        }
        for(int i = 0; i < g; i++)
            count[i] = 0;


        for(int i = 0; i < g; i++) {
            cin >> h >> d;
            h = h -1;
            int flag = (d == 'C' ? 1 : -1);

            int tm = m % n;
            int st = m - tm;
            int p = h;
            for(int j = 0; j <= tm; j++, p = add(p, flag, n), st++)
                update(p, st, i);
            if(m - n >= 0) {
                st = st - n;
                for(; p != h; p = add(p, flag, n), st++) {
                    update(p, st, i);
                }
            }
        }

        for(int i = 0; i < n; i++) 
            for(int j : guests[i]) 
                count[j]++;

        cout << "Case #" << t + 1 << ": ";//4 3 4
        for(int i = 0; i < g; i++) {
            cout << count[i];
            if(i == g - 1)
                cout << endl;
            else
                cout << " ";

        }
    }
}