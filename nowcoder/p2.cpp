#include<iostream>
#include<cstring>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
string target, s1;
deque<char> buffer;
vector<char> op;
vector<string> res;


bool comp() {
    if(buffer.size() != target.size())
        return false;
    int i = 0;
    for (auto c : buffer) 
        if(c != target[i++])
            return false;
    return true;
}

string toStr() {
    string s;
    for (auto it = op.begin(); it != op.end(); it++) {
        //if(it != op.begin()) 
            
        s.push_back(*it);
        s.push_back(' ');
    }
    return s;
}
char ops[3] = {'d', 'l', 'r'};

void backtrace(int left) {
    if(comp()) {
        res.push_back(toStr());
        return;
    }
    if(left > (int)s1.size()) 
        return;
    for(int i = 0; i < 3; i++) {
        char c = s1[left];
        op.push_back(ops[i]);
        if(i == 1)
            buffer.push_front(c);
        else if(i == 2)
            buffer.push_back(c);
        backtrace(left+1);
        if(i == 1)
            buffer.pop_front();
        else if(i == 2)
            buffer.pop_back();
        op.pop_back();
    }
}
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s1 >> target;
        buffer.clear();
        op.clear();
        res.clear();
        backtrace(0);
        sort(res.begin(), res.end());
        cout << "{" << endl;
        for(auto s : res)
            cout << s << endl;
        cout << "}" << endl;
    }
}