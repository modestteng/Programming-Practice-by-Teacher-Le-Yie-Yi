/*
 * dfs.h —— DFS 深度优先求解接口
 * 项目：走迷宫游戏 程序设计综合实践
 * 作者：崔家腾（24115248）
 */
#ifndef DFS_H
#define DFS_H

extern int dfs_expanded;       /* DFS 扩展节点数（统计用）*/

/* 求解：找到一条从起点到终点的可行路径，标记到 maze 中(值=4)
 * 返回：找到的路径步数；-1 表示不可达 */
int dfs_solve(void);

#endif
