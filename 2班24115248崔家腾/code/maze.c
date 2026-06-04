/*
 * maze.c —— 迷宫数据结构 + 递归回溯生成算法
 * 项目：走迷宫游戏 程序设计综合实践
 * 作者：崔家腾（24115248）
 *
 * 核心思想：把整个迷宫先填满墙(1)，从起点 (1,1) 出发，
 * 随机化四个方向的顺序，每次往「两步远」的格子打通，
 * 中间那格也变为通路。走不通时回溯。
 */
#include "maze.h"
#include <stdlib.h>

int maze[MAX_N][MAX_N];
int N = 0;
int sr = 1, sc = 1;
int tr = 0, tc = 0;

/* 跳两步：方向向量（行偏移、列偏移）*/
static int dr[4] = {-2, 2, 0, 0};
static int dc[4] = {0, 0, -2, 2};

void init_maze(int n)
{
    N = n;
    sr = 1; sc = 1;
    tr = N - 2; tc = N - 2;
}

void reset_path(void)
{
    int r, c;
    for (r = 0; r < N; r++)
        for (c = 0; c < N; c++)
            if (maze[r][c] == 4) maze[r][c] = 0;
    maze[sr][sc] = 2;
    maze[tr][tc] = 3;
}

/* Fisher-Yates 洗牌：把方向数组随机打乱 */
static void shuffle4(int a[4])
{
    int i, j, t;
    for (i = 3; i > 0; i--) {
        j = rand() % (i + 1);
        t = a[i]; a[i] = a[j]; a[j] = t;
    }
}

/* 递归回溯打通迷宫 */
static void carve(int r, int c)
{
    int order[4] = {0, 1, 2, 3};
    int i, d, nr, nc;
    maze[r][c] = 0;            /* 当前格打通 */
    shuffle4(order);
    for (i = 0; i < 4; i++) {
        d = order[i];
        nr = r + dr[d];
        nc = c + dc[d];
        /* 边界：保证 nr/nc 不超过 [1, N-2] 区间 */
        if (nr <= 0 || nr >= N - 1) continue;
        if (nc <= 0 || nc >= N - 1) continue;
        if (maze[nr][nc] == 1) {
            maze[r + dr[d] / 2][c + dc[d] / 2] = 0;   /* 打通中间格 */
            carve(nr, nc);
        }
    }
}

void generate_maze(void)
{
    int r, c;
    /* 全部回填为墙 */
    for (r = 0; r < N; r++)
        for (c = 0; c < N; c++)
            maze[r][c] = 1;
    carve(1, 1);
    /* 标记起终点（覆盖 carve 留下的 0）*/
    maze[sr][sc] = 2;
    maze[tr][tc] = 3;
}
