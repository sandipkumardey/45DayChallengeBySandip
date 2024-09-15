// Unique Paths II - Inefficient for large grids
function uniquePathsWithObstacles(obstacleGrid) {
    const m = obstacleGrid.length;
    const n = obstacleGrid[0].length;

    let dp = Array.from({ length: m }, () => Array(n).fill(0));

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (obstacleGrid[i][j] === 1) {
                dp[i][j] = 0;
            } else if (i === 0 && j === 0) {
                dp[i][j] = 1;
            } else {
                let fromTop = i > 0 ? dp[i - 1][j] : 0;
                let fromLeft = j > 0 ? dp[i][j - 1] : 0;
                dp[i][j] = fromTop + fromLeft;
            }
        }
    }

    return dp[m - 1][n - 1]; // Refactor to use dynamic programming efficiently
}
