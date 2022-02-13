

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class TreeNode:
    def __init__(self, x):
        self.val:int = x
        self.left = None
        self.right = None

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


    def levelOrder(self, root: TreeNode) -> list:
        re = []
        if not root:
            return re

        cur_level  =[ root,]
        next_level = []
        while cur_level:
            val,cur_level= self.dfs(cur_level)
            print(f"cur leve: {val}")
            re.append(val)
        return re


    def dfs(self,cur_level: list, ) ->(list,list):
        val = []
        next_level =[]
        for i in cur_level:
            val.append(i.val)
            if i.left:
                next_level.append(i.left)
            if i.right:
                next_level.append(i.right)
        return val,next_level



def t1():

    '''


        1
    2      3
        4 5
    :return:
    '''
    t4 = TreeNode(4)
    t5 = TreeNode(5)

    t3 = TreeNode(3)
    t3.left= t4
    t3.right = t5

    t2 = TreeNode(2)
    t1 = TreeNode(1)

    t1.left =t3
    t1.right = t2

    a = Solution()
    a.minDepth(t1)
    re = a.levelOrder(t1)
    print(f"{re}")


if __name__ == "__main__":
    t1()
