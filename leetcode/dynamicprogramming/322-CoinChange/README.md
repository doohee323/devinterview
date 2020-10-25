# [322. Coin Change](https://leetcode.com/problems/coin-change/)

## Basic idea
```
- dfs 를 이용한 dp
    coins = [1,2,5], amount = 11
    
    각 코인으로 dp의 index값을 만드려면 필요한 코인의 갯수를 계산 
    => coin 1
        dp = [0,1,2,3,4,5,6,7,8,9,10,11]        
    => coin 2
        dp = [0,0,1,2,2,3,3,4,4,5,5,6]        
    => coin 5
        dp = [0,0,0,0,0,1,2,3,4,5,2,3]        

    1. 만들 수 있는 코인이 딱 떨어지면 해당 숫자를 기술
        ex)  
    => coin 2
              0,1,2,3,4,5,6,7,8,9,10,11
        dp = [ , ,1, ,2, ,3, ,4,  5, ]        
    2. 만들 수 없으면 그 현재 dp 값에서 코인을 뺀 값의 min에 +1한  
        ex)  
    => coin 2
              0,1,2,3,4,5,6,7,8,9,10,11
        dp = [ , ,1,2,2,3,3,3,4,5 5,5]        
        dp[i] = Math.min(dp[i], dp[i-coins[j]]+1);
```

## Code
```java
  
  
  public int coinChange(int[] coins, int amount) {

    int max=amount+1;
    int[] dp = new int[max+1];
    Arrays.fill(dp, max);   // 1로 계산했을 때 필요한 갯수 + 1
    dp[0] = 0;
    for(int i=1;i<dp.length;i++) {
      for(int j=0;j<coins.length;j++) {
        if (i >= coins[j]) {
          dp[i] = Math.min(dp[i], dp[i-coins[j]]+1);
        }
      }
    }
    return dp[amount] > amount ? -1 : dp[amount];   // 최소한 max보다는 작아야 함
  }  

```

## References
- [Ricky Cho's Youtube Korean](https://www.youtube.com/watch?v=-4HE682gz-w&t=1s)
