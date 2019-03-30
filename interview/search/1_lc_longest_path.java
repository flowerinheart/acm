class Solution {
    //time: O(m*n) space:O(m * n) : backtracking 一次就有一次stack来存储迭代的结果，
    int[] t1 = {0 , 1, 0, -1};
    int[] t2 = {1, 0, -1, 0};
    public int longestIncreasingPath(int[][] matrix) {
        if (matrix == null || matrix.length == 0) return 0;
        int m = matrix.length, n = matrix[0].length;
        int res = 0;
        int[][] cache = new int[m][n];
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) 
                    res = Math.max(res, dfs(matrix, Integer.MIN_VALUE, i, j, m, n, cache));
        return res;
    }
        
    public int dfs(int[][] matrix, int min, int i, int j, int m, int n, int[][] cache) {
        if (i < 0 || j < 0 || i >= m || j >= n || matrix[i][j] <= min) 
            return 0;
        if (cache[i][j] != 0) 
            return cache[i][j];
        min = matrix[i][j];
        int max = -1;
        for(int k = 0; k < 4; k++)
            max = Math.max(max, dfs(matrix, min, i + t1[k], j + t2[k], m, n, cache) + 1);
        cache[i][j] = max;
        return max;
        
    }

}