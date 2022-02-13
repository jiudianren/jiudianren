# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root:TreeNode, p:TreeNode, q:TreeNode) ->TreeNode:
            self.ans = None
            self.dfs(root,p,q)
            return self.ans

    def dfs(self, root: TreeNode, p: TreeNode, q: TreeNode) -> bool:
        if not root :
            return False
        lv = self.dfs(root.left, p ,q)
        rv = self.dfs(root.right,p,q)
        if (lv and rv) or ( (root.val == p.val) or (root.val==q.val) and (lv or rv)):
            self.ans = root
        return lv or rv or (root.val ==p.val or root.val ==q.val)
