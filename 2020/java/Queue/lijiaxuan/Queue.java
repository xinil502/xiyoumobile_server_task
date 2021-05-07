import java.util.Arrays;
import java.util.Scanner;

public class Queue<T> {
    Node head = new Node();
    Node last = head;
    int size = 0;

    public class Node {
        T data;
        Node next;

        public Node() {
            this.data = null;
            this.next = null;
        }

        public Node(T data) {
            this.data = data;
            this.next = null;
        }
    }

    public void offer(T data) {
        Node cur = last;
        Node temp = new Node(data);
        last.next = temp;
        last = temp;
        size++;
    }

    public void poll() {
        Node cur = head.next;
        if (size == 1)
            last = head;
        head.next = cur.next;
        size--;
    }

    public T peek() {
        if (size == 0)
            return null;
        T i = head.next.data;
        return i;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int size() {
        return size;
    }

    public static void main(String[] args) {
        int[] dx = {1, 0, -1, 0};//x方向
        int[] dy = {0, 1, 0, -1};//y方向
        char[][] mg = new char[100][100];//存储迷宫地形
        boolean[][] vis = new boolean[100][100];//判断该点是否走过
        int[][] map = new int[100][100];//走到该坐标最少步数
        String[] str = new String[100];
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();//迷宫大小

        for (int i = 0; i < n; i++) {
            Arrays.fill(vis[i], false);//将迷宫初始化为没有走过
        }
        for (int i = 0; i < n; i++) {
            str[i] = sc.next();
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mg[i][j] = str[i].charAt(j);
            }
        }

        Queue<int[]> qu = new Queue<>();
        qu.offer(new int[]{0, 0});//从左上角开始，将该点入队
        vis[0][0] = true;//起点设为走过
        map[0][0] = 1;//到起点位置算一步

        while (!qu.isEmpty()) {
            int[] cur = qu.peek();
            int xx = cur[0];//当前位置
            int yy = cur[1];
            for (int i = 0; i < 4; i++) {
                int x = xx + dx[i];//下一步位置
                int y = yy + dy[i];
                if (x >= 0 && y >= 0 && x < n && y < n && mg[x][y] == '-' && !vis[x][y]) {
                    //如果没有超出边界，且此处有路，且此处没被走过
                    vis[x][y] = true;
                    map[x][y] = map[xx][yy] + 1;//走到该点步数为上一点+1
                    if (x == n - 1 && y == n - 1) {//如果到了终点，直接返回，此时最早到达即为最小值
                        System.out.println(map[n - 1][n - 1]);
                        return;
                    }
                    qu.offer(new int[]{x, y});//若没到终点，则将该点入队
                }
            }
            qu.poll();//该点走完，出队，进行下一步
        }

    }
}