/*
 * render.h —— 控制台字符画绘制接口
 * 项目：走迷宫游戏 程序设计综合实践
 * 作者：崔家腾（24115248）
 */
#ifndef RENDER_H
#define RENDER_H

void render_init(void);                        /* 创建图形窗口 */
void render_close(void);                       /* 关闭图形窗口 */
void render_maze(void);                        /* 整屏绘制迷宫 */
void render_player(int r, int c);              /* 单格画玩家位置 */
void render_status(const char* algo, int expanded, int length);
void render_menu_main(const char* opts[], int n, int sel);
void render_menu_level(const char* opts[], int n, int sel);
void render_msg(const char* msg);

#endif
