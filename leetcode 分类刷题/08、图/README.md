# 图论 Graph Theory

## 图的基本概念

1. 节点 vertex、边 edge

2. 无向图 undirected graph、有向图 directed graph
无权图 unweighted graph、带权图 weighted graph

3. 图的连通性
简单图(simple graph)：自环边 self-loop、平行边 parallel-edges

4. 邻接矩阵 adjacency matrix、邻接表 adjacency lists
邻接表适合表示稀疏图(sparse graph)，邻接矩阵适合表示稠密图(dense graph)

5. 完全图是一种特殊的稠密图

6. 邻接表比邻接矩阵更常用的主要原因有两个，所处理的大部分都是**稀疏图**，而且**遍历邻边**是图算法中最常见的操作。邻接矩阵除了适合处理稠密图外，还具有自动去除平行边的优势。

7. 深度优先遍历DFS deep first search：求连通分量、获得两点之间的一条路径

广度优先遍历BFS breadth first search：求最短路径

DFS、BFS的时间复杂度：邻接表O(V+E)，邻接矩阵O(V^2)

## 应用

交通运输、社交网络、互联网、工作安排、脑区活动、程序状态执行(自动机)

## 最小生成树问题 Minimum Span Tree

针对带权无向连通图，找 V-1 条边，连接V个顶点的总权值最小。

* 电缆布线设计
* 网络设计
* 电路设计

### 切分定理 Cut Property

* 把图中的结点分为两部分，称为一个切分(Cut)。
* 如果一个边的两个端点，属于切分(Cut)不同的两边，这个边称为横切边(Crossing Edge)。
* 给定任意切分，横切边中权值最小的边必然属于最小生成树。

### Lazy Prim

Lazy Prim 的时间复杂度是 O(ElogE)，Prim 的时间复杂度是 O(ElogV)。

### Kruskal 算法

Kruskal算法的时间复杂度 O(ElogE)。

### Vyssotsky’s Algorithm

将边逐渐地添加到生成树中，一旦形成环，删除环中权值最大的边。

## 最短路径问题 Shortest Path

广度优先遍历。
松弛操作 Relaxation 是最短路径求解的核心。

	最短路径树	Shortest Path Tree
	单源最短路径	Single Source Shortest Path

* 路径规划
* 工作任务规划

### dijkstra 单源最短路径算法

前提：图中不能有负权边，时间复杂度 O(Elog(V))。

### Bellman-Ford 单源最短路径算法

前提：有向图中不能有负权环，Bellman-Ford可以判断图中是否有负权环，时间复杂度 O(EV)。

### 拓扑排序

前提：有向无环图 DAG，时间复杂度 O(V+E)

## 最长路径算法

* 最长路径问题不能有正权环。
* 无权图的最长路径问题是指数级难度的。
* 对于有权图，不能使用Dijkstra求最长路径问题。
* 可以使用 Bellman-Ford算法。

## TODO：

* 迷宫生成
* 欧拉路径
* 哈密尔顿路径
* 二分图
* 地图填色问题

## 参考资料

1. 《剑指offer》
2. 慕课网-刘宇波老师相关课程
3. leetcode官网
4. 牛客网