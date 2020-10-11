/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/unique-binary-search-trees/description/

#include <cstdio>
#include <vector>

// recursive way
// O(N) O(N)
// 0ms 100.00%
// class Solution {
//  public:
//   std::vector<int> m_C;
//   int solve(int n) {
//     // base condition
//     if (n <= 1)
//       return 1;

//     // memoization
//     int& r = m_C[n];
//     if (r != -1)
//       return r;

//     r = 0;
//     // recursion
//     for (int i = 1; i <= n; ++i) {
//       r += solve(i-1) * solve(n-i);
//     }

//     return r;
//   }
//   int numTrees(int n) {
//     m_C.resize(n+1, -1);
//     m_C[0] = m_C[1] = 1;
//     return solve(n);
//   }
// };

// iterative way
//
//
class Solution {
 public:
  int numTrees(int n) {
    std::vector<int> C(n+1);
    C[0] = C[1] = 1;
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j <= i; ++j) {
        C[i] += C[j-1] * C[i-j];
      }
    }
    return C[n];
  }
};

int main() {
  int n = 3;
  Solution s;
  
  printf("%d\n", s.numTrees(n));
  return 0;
}
