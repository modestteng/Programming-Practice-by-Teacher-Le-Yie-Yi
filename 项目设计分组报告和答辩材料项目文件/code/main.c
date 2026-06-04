/*
 * main.c —— 走迷宫游戏 程序入口
 * 项目：走迷宫游戏 程序设计综合实践
 * 作者：崔家腾（24115248）
 *
 * 功能：主菜单、难度选择、游戏循环、模块调度。
 *
 * 程序流程：
 *   1. render_init 初始化控制台输出
 *   2. 显示主菜单：(1) 生成新迷宫 (2) DFS 求解 (3) BFS 求解
 *                  (4) 手动玩 (5) 退出
 *   3. 根据选择进入对应流程
 *   4. closegraph 退出
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "maze.h"
#include "dfs.h"
#include "bfs.h"
#include "render.h"
#include "input.h"

/* 玩家手动走迷宫
 * 渲染玩家位置的策略（控制台版）：先把当前格临时改为 5（玩家标记），
 * render_maze 渲染后立即恢复原值，避免污染 maze 数组。*/
static void play_manual(void)
{
    int pr = sr, pc = sc;
    int nr, nc, k, saved;
    char msg[64];
    strcpy(msg, "方向键移动 / Esc 返回主菜单");
    while (1) {
        saved = maze[pr][pc];
        maze[pr][pc] = 5;            /* 临时标记玩家位置 */
        render_maze();
        render_msg(msg);
        maze[pr][pc] = saved;        /* 立即恢复原值 */

        k = wait_key();
        nr = pr; nc = pc;
        if      (k == K_UP)    nr--;
        else if (k == K_DOWN)  nr++;
        else if (k == K_LEFT)  nc--;
        else if (k == K_RIGHT) nc++;
        else if (k == K_ESC)   return;
        else continue;

        if (nr < 0 || nr >= N) continue;
        if (nc < 0 || nc >= N) continue;
        if (maze[nr][nc] == 1) continue;        /* 撞墙不动 */
        pr = nr; pc = nc;

        if (pr == tr && pc == tc) {
            strcpy(msg, "到达终点！按任意键返回主菜单");
            saved = maze[pr][pc];
            maze[pr][pc] = 5;
            render_maze();
            render_msg(msg);
            maze[pr][pc] = saved;
            wait_key();
            return;
        }
    }
}

/* 选难度并生成迷宫 */
static int choose_level(void)
{
    const char* opts[] = {"小 (11x11)", "中 (21x21)", "大 (31x31)", "返回"};
    int sizes[] = {11, 21, 31, 0};
    int sel = 0, k;
    while (1) {
        render_menu_level(opts, 4, sel);
        k = wait_key();
        if      (k == K_UP)    sel = (sel + 3) % 4;
        else if (k == K_DOWN)  sel = (sel + 1) % 4;
        else if (k == K_ESC)   return 0;
        else if (k == K_ENTER) {
            if (sizes[sel] == 0) return 0;
            init_maze(sizes[sel]);
            generate_maze();
            render_maze();
            render_msg("迷宫已生成。按任意键返回主菜单...");
            wait_key();
            return 1;
        }
    }
}

/* 主菜单 */
static void main_menu(void)
{
    const char* opts[] = {
        "1. 生成新迷宫",
        "2. DFS 自动求解",
        "3. BFS 自动求解",
        "4. 手动玩",
        "5. 退出"
    };
    int sel = 0, k, len;
    while (1) {
        render_menu_main(opts, 5, sel);
        k = wait_key();
        if      (k == K_UP)    sel = (sel + 4) % 5;
        else if (k == K_DOWN)  sel = (sel + 1) % 5;
        else if (k == K_Q)     return;
        else if (k == K_ENTER) {
            if (sel == 0) { choose_level(); }
            else if (sel == 4) { return; }
            else {
                if (N == 0) continue;
                reset_path();
                if (sel == 1) {
                    len = dfs_solve();
                    render_maze();
                    render_status("DFS", dfs_expanded, len);
                    wait_key();
                } else if (sel == 2) {
                    len = bfs_solve();
                    render_maze();
                    render_status("BFS", bfs_expanded, len);
                    wait_key();
                } else if (sel == 3) {
                    play_manual();
                }
            }
        }
    }
}

int main(void)
{
    srand((unsigned)time(NULL));
    render_init();
    main_menu();
    render_close();
    return 0;
}
