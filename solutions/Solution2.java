//2. 给定一个20x20的迷宫矩阵，每个格子上有数字 1、2，机器人只能以"12121212"这样的步伐前进，找出从开始坐标(x1, y1)和结束坐标(x2, y2)的最短路径长度。
//说明：时间1小时。要求逻辑清楚，代码规范、简洁、高效。推荐使用多线程编程。不要求代码可以直接执行。
class Solution2 {
    //map代表20 * 20的迷宫，每个数字要么是1， 要么是2
    public int shortestPath(int[][] map, int x1, int y1, int x2, int y2) {
        return bfs(map, x1, y1, x2, y2);
    }

    static class Pair {
        public int x, y;
        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    int dx[] = { 1,0,-1,0 };
    int dy[] = { 0,1,0,-1 };//4个方向移动的向量
    int bfs(int[][] map, int x1, int y1, int x2, int y2) {
        int n = map.length;
        if(n == 0)
            return 0;
        int m = map[0].length;
        int distance[][] = new int[n];
        for(int i = 0; i < n; i++) {
            distance[i] = new int[m];
            Arrays.fill(distance[i], -1);
        }

        Queue<Pair> queue = new LinkedList<Pair>();
        queue.offer(new Pair(x1, y1));
        distance[x1][y1] = 0;
        while(!queue.empty()) {
            Pair pos = queue.poll();
            int number = map[pos.x][pos.y];
            for (int i = 0; i < 4; i++)//四个方向的循环
            {
                int nx = pos.x + dx[i], ny = pos.y + dy[i];//移动后的位置标记为(nx,ny)
                if (0 <= nx && nx < n && 0 <= ny && ny < m //边界检查
                    && distance[nx][ny] == -1 && number + map[nx][ny] == 3)//检查是否访问过，且步子是1212
                {
                    distance[nx][ny] = distance[pos.x][pos.y] + 1;//到该位置的距离为到前一个点的距离+1
                    if(pos.x == x2 && pos.y == y2)
                        break;
                    queue.offer(new Pair(nx, ny));
                }
            }
        }
        return distance[x2][y2];
    }
}


