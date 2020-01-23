# 图论 Graph Theory

## 图的基本概念

节点 vertex、边 edge

无向图 undirected graph、有向图 directed graph

无权图 unweighted graph、带权图 weighted graph

图的连通性

简单图(simple graph)：自环边 self-loop、平行边 parallel-edges

邻接矩阵 adjacency matrix、邻接表 adjacency lists
邻接表适合表示稀疏图(sparse graph)，邻接矩阵适合表示稠密图(dense graph)

完全图是一种特殊的稠密图

邻接表比邻接矩阵更常用的主要原因有两个，所处理的大部分都是**稀疏图**，而且**遍历邻边**是图算法中最常见的操作。邻接矩阵除了适合处理稠密图外，还具有自动去除平行边的优势。

深度优先遍历DFS deep first search：求连通分量、获得两点之间的一条路径

广度优先遍历BFS breadth first search：求最短路径

DFS、BFS的时间复杂度：邻接表O(V+E)，邻接矩阵O(V^2)

## 应用

交通运输、社交网络、互联网、工作安排、脑区活动、程序状态执行(自动机)

## TODO：

* 

## 参考资料

1. 《剑指offer》
2. 慕课网-刘宇波老师相关课程
3. leetcode官网
4. 牛客网