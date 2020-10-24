# [63. Unique Paths II](https://leetcode.com/problems/unique-paths-ii/)

## Basic idea
- dfs 를 이용한 dp
  - 각각의 경우에 수에 따라 목적지에 도착하는 경우의 수를 dfs 로 처리
  - 중복 도착의 경우에 수를 재계산하는 것을 막기 위해 memorize 를 이용
  - 중간에 1이 있으면 0으로 초기화해야 함

## Code
```java
만약에 장애물(1)이 없다면, 
  public int uniquePaths(int m, int n) {
    int Y = m;
    int X = n;
    int[][] dp = new int[Y][X];
    for(int i=0;i<Y;i++) {
      for(int j=0;j<X;j++) {
        if (i== 0 || j == 0) {
          dp[i][j] = 1;
        } else {
          dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
      }
    }
    return dp[Y-1][X-1];
  }

장애물이 있을 경우 같은 방식으로 아래와 같이 계산 가능,
  public int uniquePathsWithObstacles2(int[][] obstacleGrid) {
    int Y = obstacleGrid.length;
    int X = obstacleGrid[0].length;
    int[][] dp = new int[Y][X];
    dp[0][0] = obstacleGrid[0][0]==0 ? 1:0;
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

더 쉬운 접근으로,
  public int uniquePathsWithObstacles2(int[][] obstacleGrid) {
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

```
