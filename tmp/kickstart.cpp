#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int get(char c) {
	if(c == 'N')
		return 0;
	if(c == 'S')
		return 1;
	if(c == 'E')
		return 2;
	if(c == 'W')
		return 3;
	return -1;
}
int main()
{
    // freopen("A-large-practice.in", "r", stdin);
	int T, N, R, C, SR, SC;
	char tmp;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cin >> N >> R >> C >> SR >> SC;
		// unordered_set<pair<int, int>> visit;
		unordered_set<string> visit;
		string str = to_string(SR) + " " + to_string(SC);
		visit.insert(str);
		for(int n = 0; n < N; n++) {
			cin >> tmp;
			int dir = get(tmp);
			while(true) {
				SR += dx[dir]; SC += dy[dir];
				string str = to_string(SR) + " " + to_string(SC);
				if(visit.find(str) == visit.end()) {
					visit.insert(str);
					break;
				}
			}
		}
		printf("Case #%d: %d %d\n", t, SR, SC);
	}
    return 0;
}
// moving in the same direction until it reaches a square that it has not been in before. Banny will never give the robot an instruction that will cause it to move out of the grid
// R rows (numbered 1 to R from north to south) and C columns
// give the robot N instructions. 
// test case starts with a line containing the five integers N, R, C, SR and SC
//  N, S, E or W
//  上下右左