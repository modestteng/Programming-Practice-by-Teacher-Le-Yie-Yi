// 题目3：汉诺塔（递归法）
// 三根柱子 A、B、C，A 上有 n 个从大到小的盘子，目标是把所有盘子从 A 借助 B 移到 C。
// 规则：每次只能移动一个盘子，大盘不能压在小盘上。
// 算法思路：递归——把上面 n-1 个盘子从 A 经 C 移到 B，
//           把第 n 个盘子从 A 移到 C，
//           再把 n-1 个盘子从 B 经 A 移到 C。
#include <stdio.h>

int step = 0;   // 步数计数器

// 把 n 个盘子从 from 经 via 移到 to
void hanoi(int n, char from, char via, char to)
{
    if (n == 1) {
        // 递归基：只有 1 个盘子，直接移动
        step++;
        printf("Step %d: move disk 1 from %c to %c\n", step, from, to);
        return;
    }
    hanoi(n - 1, from, to, via);   // 第 1 步：n-1 个从 from 到 via
    step++;
    printf("Step %d: move disk %d from %c to %c\n", step, n, from, to);
    hanoi(n - 1, via, from, to);   // 第 3 步：n-1 个从 via 到 to
}

int main(void)
{
    int n = 3;   // 盘子数量，可改
    printf("Hanoi Tower with %d disks:\n", n);
    hanoi(n, 'A', 'B', 'C');
    printf("Total steps: %d\n", step);
    return 0;
}
