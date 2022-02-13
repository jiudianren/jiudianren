class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        if not (root.left or root.right):
            return 1
        min_len = 0xFFFFFFFF
        if root.left:
            min_len = min(self.minDepth(root.left),min_len)
            print(f"l:{min_len}")
        if root.right:
            min_len = min(self.minDepth(root.right),min_len)
            print(f"r:{min_len}")
        return min_len+1
