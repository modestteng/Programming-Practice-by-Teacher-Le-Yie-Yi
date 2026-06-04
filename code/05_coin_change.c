// 题目5：找零钱（贪心法）
// 现有面值 25、10、5、1（分）的硬币若干，要找零 amount 分钱，求最少硬币数。
// 算法思路：每次贪心地选择不超过剩余金额的最大面值硬币。
//           这种「每一步取局部最优」即贪心策略；对于本题面值集合是有效的。
#include <stdio.h>

#define KIND 4   // 4 种硬币

int main(void)
{
    // 硬币面值，按从大到小排好序，便于贪心
    int coin[KIND] = {25, 10, 5, 1};
    int count[KIND] = {0, 0, 0, 0};   // 每种硬币用了几个
    int amount = 63;                  // 待找的零钱
    int total = 0;                    // 总硬币数
    int i;

    int remain = amount;              // 剩余未找的钱

    for (i = 0; i < KIND; i++) {
        count[i] = remain / coin[i];  // 当前面值最多用几个
        remain   = remain % coin[i];  // 更新剩余
        total   += count[i];
    }

    printf("Change %d cents:\n", amount);
    for (i = 0; i < KIND; i++) {
        printf("  coin %2d: %d\n", coin[i], count[i]);
    }
    printf("Total coins used: %d\n", total);
    return 0;
}
