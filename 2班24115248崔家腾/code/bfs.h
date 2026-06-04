/*
 * bfs.h —— BFS 广度优先求最短路径接口
 * 项目：走迷宫游戏 程序设计综合实践
 * 作者：崔家腾（24115248）
 */
#ifndef BFS_H
#define BFS_H

extern int bfs_expanded;       /* BFS 扩展节点数 */

/* 求最短路径：返回最短步数；-1 表示不可达 */
int bfs_solve(void);

#endif
