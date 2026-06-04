// 题目6：0-1 背包问题（动态规划法）
// 有 n 件物品，每件有重量 w[i] 和价值 v[i]，背包容量为 W。
// 每件物品只能选 0 或 1 次，求装入背包的最大总价值。
// 算法思路：定义 dp[i][j] 为「前 i 件物品在容量 j 下的最大价值」。
//           状态转移：dp[i][j] = dp[i-1][j]                     （不选第 i 件）
//                    或       dp[i-1][j - w[i]] + v[i]          （选第 i 件，前提 j >= w[i]）
//           取两者较大值。
#include <stdio.h>

#define N 5            // 物品数量
#define W 10           // 背包容量

int main(void)
{
    // 物品下标从 1 开始；w[0]、v[0] 占位不用
    int w[N + 1] = {0, 2, 2, 6, 5, 4};   // 各物品重量
    int v[N + 1] = {0, 6, 3, 5, 4, 6};   // 各物品价值

    int dp[N + 1][W + 1];   // dp 表
    int i, j;

    // 初始化：物品数为 0 或容量为 0 时价值都为 0
    for (i = 0; i <= N; i++) dp[i][0] = 0;
    for (j = 0; j <= W; j++) dp[0][j] = 0;

    // 动态规划填表
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= W; j++) {
            if (j < w[i]) {
                // 容量不够，只能不选第 i 件
                dp[i][j] = dp[i - 1][j];
            } else {
                // 在「不选」和「选」两种方案中取较大者
                int notake = dp[i - 1][j];
                int take   = dp[i - 1][j - w[i]] + v[i];
                dp[i][j] = (notake > take) ? notake : take;
            }
        }
    }

    printf("0-1 Knapsack: N=%d items, capacity W=%d\n", N, W);
    printf("Items (weight,value): ");
    for (i = 1; i <= N; i++) printf("(%d,%d) ", w[i], v[i]);
    printf("\n");
    printf("Maximum total value: %d\n", dp[N][W]);
    return 0;
}
