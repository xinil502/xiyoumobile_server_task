class Solution {
    private boolean isTwoColorable = true;//成员变量
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;//表示数组的行数
        boolean[] book = new boolean[n];//用来标记结点是否被访问过
        boolean[] color = new boolean[n];//记录结点的颜色
        for (int i = 0; i < n; i++) {
            //如果没有访问过i结点，就从它开始深搜
            if (!book[i])
                dfs(graph, book, color, i);
        }
        return isTwoColorable;
    }
    //public 是任何类都可以访问它，private是只有封装这个方法的类可以访问它
    private void dfs(int[][] graph, boolean[] book, boolean[] color, int start) {
        //先标记为已经访问过
        book[start] = true;
        //逐个遍历这个结点的相邻结点
        for (int i : graph[start]) {//因为不知道一维数组的下标，所以用增强for循环，这个就表示遍历第start整个行
            if (!book[i]) {//如果与他相邻的没有被标记过
                color[i] = !color[start];//就把他的颜色标记为与顶点不相同的颜色
                dfs(graph, book, color, i);//继续再对这个顶点进行深搜
            }
            else if (color[i] == color[start])//如果相邻的两个结点的颜色一样，就说明不是二分图
                isTwoColorable = false;
        }
    }
}