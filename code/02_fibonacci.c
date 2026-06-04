// 题目2：斐波那契数列（递推法）
// 定义：F(1)=1, F(2)=1, F(n)=F(n-1)+F(n-2)  (n>=3)
// 输出前 N 项斐波那契数。
// 算法思路：用一维数组保存前 n 项，从前往后递推填充。
#include <stdio.h>

#define N 20  // 输出前 N 项

int main(void)
{
    long fib[N + 1];   // fib[1..N]，下标从 1 开始更直观
    int i;

    // 初始条件
    fib[1] = 1;
    fib[2] = 1;

    // 递推填充
    for (i = 3; i <= N; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // 输出
    printf("First %d Fibonacci numbers:\n", N);
    for (i = 1; i <= N; i++) {
        printf("%ld ", fib[i]);
        if (i % 5 == 0) printf("\n");   // 每 5 个换一行
    }
    return 0;
}
