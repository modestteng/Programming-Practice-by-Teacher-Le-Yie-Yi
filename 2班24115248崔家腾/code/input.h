/*
 * input.h —— 键盘输入接口
 * 项目：走迷宫游戏 程序设计综合实践
 * 作者：崔家腾（24115248）
 */
#ifndef INPUT_H
#define INPUT_H

#define K_NONE  0
#define K_UP    1
#define K_DOWN  2
#define K_LEFT  3
#define K_RIGHT 4
#define K_ENTER 5
#define K_ESC   6
#define K_R     7
#define K_Q     8
#define K_SPACE 9

int wait_key(void);            /* 阻塞等待一个按键 */
int get_key(void);             /* 非阻塞读取一个按键，无键时返回 K_NONE */

#endif
