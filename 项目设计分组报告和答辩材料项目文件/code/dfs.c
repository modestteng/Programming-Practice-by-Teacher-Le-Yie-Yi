/*
 * dfs.c —— DFS 深度优先求解
 * 项目：走迷宫游戏 程序设计综合实践
 * 作者：崔家腾（24115248）
 *
 * 算法思路：从起点出发，沿一个方向走到底；走不通就回退一步换方向。
 * 用 visited[][] 防止走回头路。找到终点时通过递归返回值传出成功信号，
 * 并在回溯过程中把沿途格子标记为 4(路径)。
 *
 * 注意：本实现回溯时不重置 visited（只需找一条路）。如要找所有路径，
 * 必须在回溯时把当前格子的 visited 重置回 0。
 */
#include "maze.h"
#include "dfs.h"

int dfs_expanded = 0;

static int visited[MAX_N][MAX_N];

/* 四方向向量（上下左右）*/
static int dr[4] = {-1, 1, 0, 0};
static int dc[4] = {0, 0, -1, 1};

/* 递归 DFS：若能从 (r,c) 走到终点，返回 1；否则 0 */
static int dfs(int r, int c)
{
    int d, nr, nc;
    dfs_expanded++;
    if (r == tr && c == tc) return 1;
    visited[r][c] = 1;
    for (d = 0; d < 4; d++) {
        nr = r + dr[d];
        nc = c + dc[d];
        if (nr < 0 || nr >= N) continue;
        if (nc < 0 || nc >= N) continue;
        if (visited[nr][nc]) continue;
        if (maze[nr][nc] == 1) continue;       /* 墙不能走 */
        if (dfs(nr, nc)) {
            /* 找到了：回填路径（起终点除外）*/
            if (!(nr == tr && nc == tc) && !(nr == sr && nc == sc))
                maze[nr][nc] = 4;
            return 1;
        }
    }
    return 0;
}

int dfs_solve(void)
{
    int r, c, len;
    dfs_expanded = 0;
    for (r = 0; r < N; r++)
        for (c = 0; c < N; c++)
            visited[r][c] = 0;
    if (!dfs(sr, sc)) return -1;
    /* 还原起终点标记 */
    maze[sr][sc] = 2;
    maze[tr][tc] = 3;
    /* 统计路径长度（4 的数量 + 起点 + 终点）*/
    len = 0;
    for (r = 0; r < N; r++)
        for (c = 0; c < N; c++)
            if (maze[r][c] == 4) len++;
    return len + 2;
}
