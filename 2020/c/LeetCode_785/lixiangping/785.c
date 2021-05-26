//深度优先遍历
bool dfs(int node, int c, int* color, int** graph, int* graphColSize) {
    color[node] = c;
    int cNei = (c == 1 ? 2 : 1);
    for (int i = 0; i < graphColSize[node]; ++i) {
        int neighbor = graph[node][i];
        if (color[neighbor] == 0) {
            if (!dfs(neighbor, cNei, color, graph, graphColSize)) {
                return false;
            }
        } else if (color[neighbor] != cNei) {
            return false;
        }
    }
    return true;
}

 bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int* color = (int*)malloc(sizeof(int) * graphSize);
    memset(color, 0, sizeof(int) * graphSize);
    for (int i = 0; i < graphSize; ++i) {
        if (color[i] == 0) {
            if (!dfs(i, 1, color, graph, graphColSize)) {
                free(color);
                return false;
            }
        }
    }
    free(color);
    return true;
}
