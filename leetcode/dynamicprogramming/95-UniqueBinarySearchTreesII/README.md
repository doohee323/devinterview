# [95. Unique Binary Search Trees II](https://leetcode.com/problems/unique-binary-search-trees-ii/)

## Basic idea
```

쌍을 이루는 것들을 나열하는 모든 경우의 수를 카탈란 수라고 한다.
https://bit.ly/3mkrD5g

- time: O(catalan(n))
- space: O(log(n)), tree space is log(n) with total node n

    1,        2          3
   / \       / \        / \
  0  (2,3)  1   3    (1,2) 0
 C0 * C2 + C1 * C1 + C2 * C0 = 2+1+2 = 5


    1,        2,        3,        4
   /\        / \       / \      /  \
  0 (2,3,4) 1 (3,4) (1,2) 4 (1,2,3) 0
 C0 * C3 + C1 * C2 + C2 * C1 + C3 * C0 = 5+2+2+5 = 14
 
 (Ci - 1) * (Cn - 1) => count of Unique Binary Search Trees

```

## Another catalan case
22. Generate Parentheses
https://leetcode.com/problems/generate-parentheses/

## Rerevant question
96. Unique Binary Search Trees
https://leetcode.com/problems/unique-binary-search-trees/
```
class Solution {

  List<String> ans = new ArrayList<>();
  
  public List<String> generateParenthesis(int n) {

    helper(new char[n*2], 0);
    return ans;
  }
  
  void helper(char[] cs, int idx) {
    if (idx > cs.length) return;
    if (idx == cs.length) {
      if (valid(cs)) {
        ans.add(new String(cs));
      }
    } else {
      cs[idx]='(';
      helper(cs, idx+1);
      cs[idx]=')';
      helper(cs, idx+1);
    }
  }
  
  boolean valid(char[] cs) {
    int cnt = 0;
    for(int i=0;i<cs.length;i++) {
      if (cs[i] == '(') {
        cnt++;
      } else if (cs[i] == ')') {
        cnt--;
      }
      if (cnt < 0) return false;
    }
    return cnt == 0;
  }
    
}

```
