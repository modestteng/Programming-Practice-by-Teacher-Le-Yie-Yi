/*
 * maze.h —— 迷宫数据结构与生成算法接口
 * 项目：走迷宫游戏 程序设计综合实践
 * 作者：崔家腾（24115248）
 */
#ifndef MAZE_H
#define MAZE_H

#define MAX_N 35

/* 迷宫格值约定：0=通路 1=墙 2=起点 3=终点 4=路径标记 */
extern int maze[MAX_N][MAX_N];
extern int N;                  /* 当前迷宫边长（11/21/31）*/
extern int sr, sc;             /* 起点坐标 */
extern int tr, tc;             /* 终点坐标 */

void init_maze(int n);         /* 设置 N 与起终点 */
void reset_path(void);         /* 把所有 4(路径标记) 改回 0(通路) */
void generate_maze(void);      /* 递归回溯生成 */

#endif
