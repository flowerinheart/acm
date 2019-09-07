
//1. ugly number1 


    bool isUgly(int num) {
        if(num <= 0) return false;
        while(num != 1){
            if(num % 2 == 0) num /= 2;
            else if(num % 3 == 0) num /= 3;
            else if(num % 5 == 0) num /= 5;
            else return false;
        }
        return true;
    }



//2. ugly number 2, 这是最高效的实现, 但是算是有点耍赖了


class Solution {
public:
    int nthUglyNumber(int n) {
        static vector<int> tem;     
        long long p2, p3, p5, m = INT_MAX;
        if(n==1) return 1;
        if (tem.empty()){
        for (p2=1; p2<=m; p2*=2){
            for (p3 = p2; p3<=m; p3*=3){
                for (p5 = p3; p5<=m; p5*=5){
                    tem.push_back(p5);
                }
            }
        }
        sort(begin(tem),end(tem));
        }
        

    return tem[n-1];
    }
};


//下面这个算是最合理的方法, 思路就是将数字分成三个数列，分别代表以2, 3, 5结尾的数字的
//这两个数组都是递增的，每次只需要取其中最小的，然后更新，更新方法是取总序列中的下一个数字
class Solution {
public:
    int nthUglyNumber(int n) {
        int arr[1691] = {1};
        int a1 = 0, a2 = 0, a3 = 0;
        for (int i = 1; i < n; ++i) {
            arr[i] = min(min(2 * arr[a1], 3 * arr[a2]), 5 * arr[a3]);
            if (arr[i] == 2 * arr[a1]) ++a1;
            if (arr[i] == 3 * arr[a2]) ++a2;
            if (arr[i] == 5 * arr[a3]) ++a3;
        }
        return arr[n - 1];
    }
};

//super urgly
//基本思路一致，不过是变成了多个, 这里用两个数组是为了避免重复计算(否则每次取最小值都要做k次乘法)

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int ugly[n], k=primes.size();
        long long factor[k], smallest;
        int idx[k], j;
        for(int i = 0; i < k; ++i){
            factor[i]=primes[i];
            idx[i]=0;
        }
        ugly[0]=1;
        for(int i = 1; i <n; ++i){
            smallest=factor[0];
            j=0;
            for(int i = 1; i < k; ++i){
                if(factor[i]<smallest){
                    smallest=factor[i];
                    j=i;
                }
            }
            ugly[i] = smallest;
            for(int i = j; i < k; ++i){
                if(smallest==factor[i]) factor[i] = primes[i]*ugly[++idx[i]];
            }
        }
        return ugly[n-1];
    }
};
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int const m = primes.size();
        int candidate_uglies[m];
        for (auto i = 0; i < m; ++i)
            candidate_uglies[i] = primes[i];
        
        int uglies[n] = {1};
        int affected_uglies_n[m];
        memset(affected_uglies_n, 0, sizeof(affected_uglies_n));
        
        auto uglies_n = 1;  // the first ugly always be 1
        while (uglies_n != n) {
            auto ugly = candidate_uglies[0];
            for (auto candidate : candidate_uglies)
                ugly = min(candidate, ugly);
            
            uglies[uglies_n++] = ugly;
            
            for (auto i = 0; i < m; ++i) {
                if (candidate_uglies[i] == ugly) {
                    auto const nxt_affected_ugly_idx = ++affected_uglies_n[i];
                    candidate_uglies[i] = uglies[nxt_affected_ugly_idx] * primes[i];
                }
            }
        }
        return uglies[n-1];
    }
