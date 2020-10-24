class Solution {
  public List<TreeNode> generateTrees(int n) {
    if (n==0) return new ArrayList<TreeNode>();;
    return helper(1,n);
  }

  List<TreeNode> helper (int start, int end) {
    List<TreeNode> ans = new ArrayList<>();
    if (start > end) ans.add(null);

    for(int i = start; i <= end; i++) {
      List<TreeNode> ll = helper(start, i - 1);
      List<TreeNode> rl = helper(i + 1, end);

      for (TreeNode l : ll) {
        for(TreeNode r: rl) {
          TreeNode n = new TreeNode(i);
          n.left = l;
          n.right = r;
          ans.add(n);
        }
      }
    }
    return ans;
  }
}