# [139. Word Break - Immutable](https://leetcode.com/problems/word-break/)

- source:https://leetcode.com/problems/word-break/

## Problem
```
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
```
## Approach
```
    uses memization with unordered_map
    unordered_map<string, bool> dp;

    using every word in wordDict,  seperate string.

    eg)
    s = "applepenapple", wordDict = ["apple", "pen"]

    applepenapple => apple, dp[penapple] ==> apple, pen, apple => true
```
## Implementation
```
    * [c++11](WorkBreak.cpp)        
```

## Complexity
```
    Let's say S is the length of input string s ans W is the length of largest word in wordDict.
    Time Complexity - O(SW)
    Space Complexity - O(n^2)
    
```

