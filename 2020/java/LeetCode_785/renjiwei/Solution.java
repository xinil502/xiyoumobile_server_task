public class Solution {

    private boolean[] visited;
    private int[] colors;
    private int[][] graph;

    public boolean isBipartite(int[][] graph) {
        this.graph = graph;
        int V = graph.length;
        visited = new boolean[V];
        colors = new int[V];
        for(int v = 0; v < V; v ++){
            if(!visited[v] && !dfs(v, 1)){
                return false;
            }
        }
        return true;
    }

    private boolean dfs(int v, int color){
        visited[v] = true; //已遍历
        colors[v] = color; //染色

        for(int w: graph[v]){ //遍历相邻结点
            if(!visited[w]){  //相邻结点未访问过，
                if(!dfs(w, -color)) { //染相反的颜色。
                    return false;
                }
            }else if(colors[v] == colors[w]){ //相邻颜色相同，返回false。
                return false;
            }
        }
        return true;
    }
}

