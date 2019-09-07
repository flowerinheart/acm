

// K food stalls and one warehouse
//  main street is a long horizontal line that is 109 metres long.
//  N spots that you are allowed to build stalls or a warehouse on  
//  The i-th spot is Xi meters from the left end of the street.
// costs Ci dollars

//  if the warehouse is in the j-th spot, then building a stall in the i-th spot costs an extra |Xj - Xi| dollars, 离得越远话费越多

//  Please find the minimum cost to build exactly K food stalls and one warehouse.


Input 
 	
Output 
 
3
2 4
1 2 3 10
100 70 80 20
1 5
150 300 301 400 700
8 35 26 5 2
6 7
22 21 20 23 26 25 24
10 10 10 10 10 10 10

  
Case #1: 178
Case #2: 62
Case #3: 82

  




#include<iostream>
using namespace std;
struct node{
    int cost;
    int x;
};
node stall[100000];
    int T;
    int k, n;


bool comp(node &a, node &b) {
    return a.cost < b.cost;
}
int cost[100000];
int x[100000];


int cal(int c) {
    int l = c - 1, r = c + 1;
    int cost = node[c].cost;
    for(int i = 0; i < k; i++){
        int costl = INT_MAX;
        int costr = INT_MAX;
        if(l >= 0) 
            costl = node[l].cost + abs(node[l].x - node[c].x);
        if(r < n) 
            costl = node[l].cost + abs(node[l].x - node[c].x);
        if(costl <= costr) {
            cost += costl;
            l--;
        }else {
            cost += costr;
            r++;
        }
    }
    return cost;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> k >> n;
        for(int i = 0; i < n; i++) {
            cin >> stall.x;
            cin >> stall.cost;
        }
    }
    sort(stall, stall+n, comp); 


    for(int c = 0; c < n; c++) {

    }
}