
// 一个袋子里面有n个球，每个球上面都有一个号码(拥有相同号码的球是无区别的)。如果一个袋子是幸运的当且仅当所有球的号码的和大于所有球的号码的积。
// 例如：如果袋子里面的球的号码是{1, 1, 2, 3}，这个袋子就是幸运的，因为1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
// 你可以适当从袋子里移除一些球(可以移除0个,但是别移除完)，要使移除后的袋子是幸运的。现在让你编程计算一下你可以获得的多少种不同的幸运的袋子。

// 可以看作是combination sum 2的变种，需要多考虑有1的特殊情况， 有两种backtrace的写法
// 一种是基于步骤的bfs, 决策树节点是每一步选择添加哪个数字（按顺序），如下所示
//  dfs中通过一个for循环来选择这一步骤选择哪个数字，这里去重复的思想就很简单，for循环中遇到和之前相同的就跳过
#include<cstdio>
#include<algorithm>
using namespace std;
int buf[1000];
int n;
int dfs(int pos, long long sum, long long m) {
    int temp = 0;
    for(int i = pos; i < n; i++) {
        sum += buf[i];
        m *= buf[i];
        if(sum > m)
            temp = temp + 1 + dfs(i + 1, sum, m);
        else if(buf[i] == 1)
            temp = temp + dfs(i + 1, sum, m);
        else
            break;
        sum -= buf[i];
        m /= buf[i];
        for(; i < n - 1 && buf[i] == buf[i + 1]; i++);
    }
    return temp;
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", buf + i);
    sort(buf, buf + n);
    printf("%d\n", dfs(0, 0, 1));
}



// 第二种写法，是基于数字的，决策时每个节点选择是否要加入这个数字，如下所示，这里去除重复，需要一些特殊处理，就是在不选这个数字的分支下，需要将后续所有等于当前数字的都抛弃点，如下面代码中的while循环。
// #include<cstdio>
#include<algorithm>
using namespace std;
int buf[1000];
int n;
int dfs(int pos, long long sum, long long m) {
    if(pos == n)
        return 0;
    long long tsum = sum + buf[pos];
    long long tm = m * buf[pos];
    if(buf[pos] != 1 && tsum <= tm)
          return 0;
    int count = tsum > tm ? 1 : 0;
    count += dfs(pos + 1, tsum, tm);
    while(pos + 1 < n && buf[pos] == buf[pos + 1])
        pos++;
    count += dfs(pos + 1, sum, m);
    return count;
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", buf + i);
    sort(buf, buf + n);
    printf("%d\n", dfs(0, 0, 1));
}


//选择数量少的时候用第二种，否则用第一种