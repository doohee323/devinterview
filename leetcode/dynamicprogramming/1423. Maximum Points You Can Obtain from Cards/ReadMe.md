# [139. Word Break - Immutable](https://leetcode.com/problems/word-break/)

- source:https://leetcode.com/problems/word-break/

## Problem
```
Given the integer array cardPoints and the integer k, return the maximum score you can obtain
```
## Approach
``` 
    eg)cardPoints = [1,2,3,4,5,6,1], k = 3
    L[1,2,3] R[]
    L[1,2]  R[1]
    L[1]  R[6,1]
    L[] R[5,6,1]

    dp[0] = all sum of(cardPoints[0] ~ cardPoints[k-1]), [0, ... , k-1]
    dp[1] = d[0] - cardPoints[k-1]                       left[0, ... , k-1]  + right[0]
    dp[2] = d[1] - cardPoints[k-2]

    recurrence relation
    {
        if i==0, dp[0] = all sum of cardPoints from 0 to k-1
        else dp[i] = dp[i-1] - cardPoints[k-1]
    }
```
## Implementation
```
    * [c++11](MaximumPoints.cpp)        
```

## Complexity
```
    Time Complexity - O(k)
    Space Complexity - O(k)
    
```

