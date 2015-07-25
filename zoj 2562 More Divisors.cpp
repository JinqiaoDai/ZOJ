#include <iostream>
using namespace std;

/*
 * zoj 2562 More Divisors
 * http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemId=1562
 * Number Theory - Prime Number
 * DFS
 */

int prime[16] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
unsigned long long n, res, maxfacs;

void dfs(int step, int ed, int tmpnumoffacs, unsigned long long tmpnum) {
    if (step >= 16)
        return;
    if (tmpnumoffacs > maxfacs || (tmpnumoffacs == maxfacs && tmpnum < res)) {
        maxfacs = tmpnumoffacs;
        res = tmpnum;
    }
    for (int i = 1; i <= ed; ++i) {
        if (n / prime[step] < tmpnum)
            break;
        dfs(step + 1, i, tmpnumoffacs * (i + 1), tmpnum *= prime[step]);
    }
}

void run() {
    while (cin >> n) {
        res = n;
        maxfacs = 0;
        dfs(0, 64, 1, 1);
        cout << res << endl;
    }
}

int main() {
    run();
    return 0;
}
