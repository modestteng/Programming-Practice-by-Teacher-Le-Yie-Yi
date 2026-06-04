/*
 * bfs.c —— BFS 广度优先求最短路径
 * 项目：走迷宫游戏 程序设计综合实践
 * 作者：崔家腾（24115248）
 *
 * 算法思路：用队列保存待扩展的格子。从起点入队，每次取出队头，
 * 把四个邻居（若是通路且未访问）入队，并记录每个邻居的父节点。
 * 找到终点时，从终点沿父节点表倒推回起点即得最短路径。
 *
 * 队列实现：用数组模拟（queue_r/queue_c + front/rear 双指针）。
 * 容量 N*N 足够：每格最多入队一次。
 */
#include "maze.h"
#include "bfs.h"

#define QSIZE (MAX_N * MAX_N)

int bfs_expanded = 0;

static int visited[MAX_N][MAX_N];
static int prev_r[MAX_N][MAX_N];     /* 父节点：行 */
static int prev_c[MAX_N][MAX_N];     /* 父节点：列 */
static int queue_r[QSIZE];
static int queue_c[QSIZE];

static int dr[4] = {-1, 1, 0, 0};
static int dc[4] = {0, 0, -1, 1};

int bfs_solve(void)
{
    int r, c, d, nr, nc;
    int front, rear, found;
    int len, pr, pc;

    bfs_expanded = 0;
    for (r = 0; r < N; r++)
        for (c = 0; c < N; c++) {
            visited[r][c] = 0;
            prev_r[r][c] = -1;
            prev_c[r][c] = -1;
        }

    front = 0; rear = 0;
    queue_r[rear] = sr;
    queue_c[rear] = sc;
    rear++;
    visited[sr][sc] = 1;

    found = 0;
    while (front < rear) {
        r = queue_r[front];
        c = queue_c[front];
        front++;
        bfs_expanded++;
        if (r == tr && c == tc) { found = 1; break; }
        for (d = 0; d < 4; d++) {
            nr = r + dr[d];
            nc = c + dc[d];
            if (nr < 0 || nr >= N) continue;
            if (nc < 0 || nc >= N) continue;
            if (visited[nr][nc]) continue;
            if (maze[nr][nc] == 1) continue;
            visited[nr][nc] = 1;
            prev_r[nr][nc] = r;
            prev_c[nr][nc] = c;
            queue_r[rear] = nr;
            queue_c[rear] = nc;
            rear++;
        }
    }

    if (!found) return -1;

    /* 沿 prev 倒推回起点，标记路径 */
    r = tr; c = tc;
    len = 0;
    while (!(r == sr && c == sc)) {
        if (!(r == tr && c == tc) && !(r == sr && c == sc))
            maze[r][c] = 4;
        pr = prev_r[r][c];
        pc = prev_c[r][c];
        r = pr; c = pc;
        len++;
    }
    /* 还原起终点 */
    maze[sr][sc] = 2;
    maze[tr][tc] = 3;
    return len;
}
