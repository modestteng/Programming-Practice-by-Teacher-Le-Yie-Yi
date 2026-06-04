// 题目4：二分查找（分治法）
// 在已经升序排好的整型数组中查找目标值 target，返回下标；找不到返回 -1。
// 算法思路：每次把搜索区间一分为二，比较中点元素与目标，决定下一轮搜索左半还是右半。
//           每次问题规模减半 —— 典型的分治思想。
#include <stdio.h>

#define N 10

int main(void)
{
    // 已升序排序的数组
    int a[N] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target = 23;     // 待查找值
    int low = 0;
    int high = N - 1;
    int mid;
    int found = -1;      // -1 表示未找到

    while (low <= high) {
        mid = (low + high) / 2;       // 取中点下标
        if (a[mid] == target) {
            found = mid;              // 找到了
            break;
        } else if (a[mid] < target) {
            low = mid + 1;            // 在右半部分继续
        } else {
            high = mid - 1;           // 在左半部分继续
        }
    }

    if (found != -1) {
        printf("Target %d found at index %d\n", target, found);
    } else {
        printf("Target %d not found\n", target);
    }
    return 0;
}
