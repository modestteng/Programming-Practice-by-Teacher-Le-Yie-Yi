/*
 * input.c —— 控制台键盘输入
 * 项目：走迷宫游戏 程序设计综合实践
 * 作者：崔家腾（24115248）
 *
 * 用 Windows 的 conio.h 提供的 _getch / _kbhit 读键盘事件。
 * 方向键的特殊处理：_getch() 先返回前缀字节 0 或 0xE0，再返回方向码——
 *   72=Up, 80=Down, 75=Left, 77=Right。
 */
#include <conio.h>
#include "input.h"

int wait_key(void)
{
    int c = _getch();

    /* 方向键的扩展按键前缀 */
    if (c == 0 || c == 0xE0) {
        c = _getch();
        if (c == 72) return K_UP;
        if (c == 80) return K_DOWN;
        if (c == 75) return K_LEFT;
        if (c == 77) return K_RIGHT;
        return K_NONE;
    }

    if (c == '\r' || c == '\n') return K_ENTER;
    if (c == 27)  return K_ESC;     /* Escape ASCII */
    if (c == ' ') return K_SPACE;
    if (c == 'R' || c == 'r') return K_R;
    if (c == 'Q' || c == 'q') return K_Q;
    return K_NONE;
}

int get_key(void)
{
    if (_kbhit()) {
        return wait_key();
    }
    return K_NONE;
}
