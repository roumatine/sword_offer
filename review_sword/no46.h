/*
no.46 圆圈中最后剩下的数

*/

int lastRemaining(int n, int m) {
    if (n <= 0 || m <= 0)
        return -1;
    int ans = 0;
    for (int i = 2; i <= n; ++i) {
        ans = (ans + m) % i;
    }
    return ans;
}

int lastRemaining_Solution(int n, int m) {
    if (n == 0)
        return -1;
    if (n == 1) 
        return 0;
    else 
        return (lastRemaining_Solution(n - 1, m) + m) % n;
}