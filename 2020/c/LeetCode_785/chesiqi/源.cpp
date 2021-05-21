class Solution {
    private boolean isTwoColorable = true;//��Ա����
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;//��ʾ���������
        boolean[] book = new boolean[n];//������ǽ���Ƿ񱻷��ʹ�
        boolean[] color = new boolean[n];//��¼������ɫ
        for (int i = 0; i < n; i++) {
            //���û�з��ʹ�i��㣬�ʹ�����ʼ����
            if (!book[i])
                dfs(graph, book, color, i);
        }
        return isTwoColorable;
    }
    //public ���κ��඼���Է�������private��ֻ�з�װ�������������Է�����
    private void dfs(int[][] graph, boolean[] book, boolean[] color, int start) {
        //�ȱ��Ϊ�Ѿ����ʹ�
        book[start] = true;
        //�����������������ڽ��
        for (int i : graph[start]) {//��Ϊ��֪��һά������±꣬��������ǿforѭ��������ͱ�ʾ������start������
            if (!book[i]) {//����������ڵ�û�б���ǹ�
                color[i] = !color[start];//�Ͱ�������ɫ���Ϊ�붥�㲻��ͬ����ɫ
                dfs(graph, book, color, i);//�����ٶ���������������
            }
            else if (color[i] == color[start])//������ڵ�����������ɫһ������˵�����Ƕ���ͼ
                isTwoColorable = false;
        }
    }
}