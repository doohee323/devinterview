
public class Solution {
  public int uniquePathsWithObstacles(int[][] obstacleGrid) {
    int Y = obstacleGrid.length;
    int X = obstacleGrid[0].length;
    int[] dp = new int[X];
    dp[0] = 1;
    for (int i=0;i<Y; i++) {
      for (int j = 0; j < X; j++) {
        if (obstacleGrid[i][j] == 1)
          dp[j] = 0;
        else if (j > 0)
          dp[j] += dp[j - 1];
      }
    }
    return dp[X - 1];
  }

  public int uniquePathsWithObstacles2(int[][] obstacleGrid) {
    int Y = obstacleGrid.length;
    int X = obstacleGrid[0].length;
    int[][] dp = new int[Y][X];
    dp[0][0] = obstacleGrid[0][0]==0 ? 1:0;
    if(dp[0][0] == 0) return 0;

    for(int i=0;i<Y;i++) {
      for(int j=0;j<X;j++) {
        if (obstacleGrid[i][j] == 1) {
          dp[i][j] = 0;
        } else if(i==0) {
          if(j>0) {
            dp[i][j] = dp[i][j-1];
          }
        } else if(j==0) {
          if(i>0) {
            dp[i][j] = dp[i-1][j];
          }
        } else {
          dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
      }
    }
    return dp[Y-1][X-1];
  }
}


