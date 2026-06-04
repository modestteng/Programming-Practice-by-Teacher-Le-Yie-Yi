/*
 * render.c —— 控制台字符画渲染
 * 项目：走迷宫游戏 程序设计综合实践
 * 作者：崔家腾（24115248）
 *
 * 把迷宫用 ASCII 字符画到控制台窗口，每格占 2 个字符宽，
 * 让视觉上呈正方形：
 *   通路 0 → "  "（两空格）
 *   墙   1 → "##"
 *   起点 2 → "S "
 *   终点 3 → "E "
 *   路径 4 → ". "
 *   玩家 5 → "P "
 * 渲染前调用 system("cls") 整屏清空再重绘。
 */
#include <stdio.h>
#include <stdlib.h>
#include "render.h"
#include "maze.h"

void render_init(void)
{
    /* 切换到 UTF-8 代码页，让中文字符能正常显示 */
    system("chcp 65001 > nul");
}

void render_close(void)
{
    /* 控制台版无需特殊清理 */
}

/* 把迷宫格值映射到两字符宽的显示字符串 */
static const char* cell_str(int v)
{
    if (v == 0) return "  ";   /* 通路 */
    if (v == 1) return "##";   /* 墙 */
    if (v == 2) return "S ";   /* 起点 */
    if (v == 3) return "E ";   /* 终点 */
    if (v == 4) return ". ";   /* 路径标记 */
    if (v == 5) return "P ";   /* 玩家临时位置 */
    return "??";
}

void render_maze(void)
{
    int r, c;
    system("cls");
    if (N == 0) return;

    /* 顶部边框 */
    putchar(' ');
    for (c = 0; c < N; c++) printf("==");
    putchar('\n');

    /* 迷宫主体 */
    for (r = 0; r < N; r++) {
        putchar('|');
        for (c = 0; c < N; c++) {
            printf("%s", cell_str(maze[r][c]));
        }
        printf("|\n");
    }

    /* 底部边框 */
    putchar(' ');
    for (c = 0; c < N; c++) printf("==");
    putchar('\n');

    /* 图例 */
    printf("\n图例： S=起点  E=终点  ##=墙  .=路径  P=玩家\n");
}

void render_player(int r, int c)
{
    /* 控制台版：玩家位置由 main.c 通过 maze[pr][pc]=5 临时标记后调用 render_maze 实现，
     * 此函数保留接口签名但不做绘制，保证主调用方代码无须区分渲染后端。*/
    (void)r;
    (void)c;
}

void render_status(const char* algo, int expanded, int length)
{
    printf("\n=== 算法统计 ===\n");
    printf("  当前算法: %s\n", algo);
    printf("  扩展节点: %d\n", expanded);
    printf("  路径步数: %d\n", length);
    printf("\n按任意键返回主菜单...\n");
}

void render_menu_main(const char* opts[], int n, int sel)
{
    int i;
    system("cls");
    printf("==================================\n");
    printf("           走迷宫游戏\n");
    printf("       C 语言 / 控制台版本\n");
    printf("==================================\n\n");
    for (i = 0; i < n; i++) {
        if (i == sel) printf("  > %s\n", opts[i]);
        else          printf("    %s\n", opts[i]);
    }
    printf("\n  上下方向键选择，回车确认，Q 退出\n");
}

void render_menu_level(const char* opts[], int n, int sel)
{
    int i;
    system("cls");
    printf("==================================\n");
    printf("           选择难度\n");
    printf("==================================\n\n");
    for (i = 0; i < n; i++) {
        if (i == sel) printf("  > %s\n", opts[i]);
        else          printf("    %s\n", opts[i]);
    }
    printf("\n  上下方向键选择，回车确认，Esc 返回\n");
}

void render_msg(const char* msg)
{
    printf("\n%s\n", msg);
}
