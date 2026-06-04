// 题目1：百钱买百鸡（枚举法）
// 公鸡 5 元一只，母鸡 3 元一只，小鸡 1 元 3 只。
// 用 100 元买 100 只鸡，问公鸡、母鸡、小鸡各买多少只？
// 算法思路：三层枚举（也可减少到两层），逐一验证条件。
#include <stdio.h>

int main(void)
{
    int cock, hen, chick;   // 公鸡、母鸡、小鸡的数量
    int count = 0;          // 解的个数

    // 公鸡最多 100/5 = 20 只
    for (cock = 0; cock <= 20; cock++) {
        // 母鸡最多 100/3 = 33 只
        for (hen = 0; hen <= 33; hen++) {
            // 小鸡数量由总数 100 决定
            chick = 100 - cock - hen;
            // 小鸡数必须是 3 的倍数（1 元 3 只）
            if (chick >= 0 && chick % 3 == 0) {
                // 验证总钱数：公鸡 5 元 + 母鸡 3 元 + 小鸡 1/3 元
                if (5 * cock + 3 * hen + chick / 3 == 100) {
                    count++;
                    printf("Solution %d: cock=%d, hen=%d, chick=%d\n",
                           count, cock, hen, chick);
                }
            }
        }
    }
    printf("Total solutions: %d\n", count);
    return 0;
}
