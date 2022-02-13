
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val:int = x
        self.left = None
        self.right = None


class Solution_Serialize:

    def serialize_dfs(self, node: TreeNode, index: int):
        if not node:
            self.reStr = self.reStr + "#" + ","
            index = index + 2
            return
        strVal = str(node.val)
        index = index + len(strVal) + 1
        self.reStr = self.reStr + strVal + ","

        self.serialize_dfs(node.left, index)
        self.serialize_dfs(node.right, index)

    def serialize(self, root: TreeNode):
        self.reStr = ""
        index = 0
        self.serialize_dfs(root, index)
        return self.reStr

    def des_defs(self, data:str, index:int)->TreeNode:
        if index >= len(data):
            return None
        if data[index] == "#":
            self.des_index = self.des_index +2
            return None

        end_index = data[index:].index(",")
        value = int(data[index:index+end_index])
        self.des_index = self.des_index + len(str(value)) + 1

        root = TreeNode(value)
        root.left  = self.des_defs(data,self.des_index)
        root.right = self.des_defs(data,self.des_index)
        return root

    def deserialize(self, data:str):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        self.des_index =0
        return self.des_defs(data,self.des_index)

def t_1():
    '''
              1
        2         3
      null  4   5  null

    :return:
    '''



    t4 = TreeNode(4)
    t5 = TreeNode(5)

    t2 = TreeNode(2)
    t2.right= t4

    t3 = TreeNode(3)
    t3.left = t5

    t1 = TreeNode(1)
    t1.left = t2
    t1.right = t3
    abcd = Solution_Serialize()
    reStr = abcd.serialize(t1)
    print(reStr)
    reNode = abcd.deserialize(reStr)
    print("aa:"+ abcd.serialize(reNode))




if __name__ == "__main__":
    t_1()
