// Minimum Path Sum - Incomplete implementation
function minPathSum(grid) {
    if (grid.length === 0 || grid[0].length === 0) return 0;

    const m = grid.length;
    const n = grid[0].length;
    let dp = Array.from({ length: m }, () => Array(n).fill(0));

    dp[0][0] = grid[0][0];

    for (let i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (let j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (let i = 1; i < m; i++) {
        for (let j = 1; j < n; j++) {
            dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }

    return dp[m - 1][n - 1]; // Complete from scratch
}
