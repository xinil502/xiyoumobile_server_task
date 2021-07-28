class Solution {
    public boolean isBipartite(int[][] graph) {
        int l=graph.length;
        int[] vis = new int[l];
        for (int i=0;i<l;i++) {
            if (vis[i]==0&&!dfs(graph,i,vis,1)) {
                return false;
            }
        }
        return true;
    }

    public boolean dfs(int[][] graph,int i,int[] vis,int flag) {
        if (vis[i]!=0) {
            return vis[i]==flag;
        }
        
        vis[i] = flag;
        int x=graph[i].length;
        for (int j=0;j<x;j++) {
            if (!dfs(graph,graph[i][j],vis,-1*flag)) {
                return false;
            }
        }
        return true;
    }
}