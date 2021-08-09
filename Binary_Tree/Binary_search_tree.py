from collections import deque
class TreeNode:
    def __init__(self,val):
        self.val = val
        self.left = None
        self.right =None
    @staticmethod
    def tree():
        return None
        




class BST:
    
    root = TreeNode.tree()
    def __Insert_Node(self,root,val):
        if root == None:
            root = TreeNode(val)
        
            return root
        else:
            if root.val > val:
                root.left = self.__Insert_Node(root.left,val)
            elif root.val < val:
                root.right = self.__Insert_Node(root.right,val)
        return root


    def __Remove_Node(self,root,key):
        if root == None:
            return root
        if root.val>key:
            root.left = self.__Remove_Node(root.left,key)
        elif  root.val< key:
            root.right = self.__Remove_Node(root.right,key)
        else:
            if root.left == None:
                temp = root.right
                root = None
                return temp
            elif root.right == None:
                temp = root.left
                root = None
                return temp
            else:
                temp = self.Successor(root.right)
                root.val = temp.val
                root.right = self.__Remove_Node(root.right,temp.val)
        return root
                
                
    def Successor(self,root):
        current = root
        while(current.left is not None):
            current = current.left
        return current
    
    def __Inorder(self,root):
        if  root:

            self.__Inorder(root.left)
            print(root.val)
            self.__Inorder(root.right)
        

    
        
    def bfs(self,root):
        q = deque()
        q.append(root)
        while len(q)>0:
              c = len(q)
              while c>0:
                  curr = q.popleft()
                  print(curr.val,end=" ")
                  if curr.left:
                     q.append(curr.left)
                  if curr.right:
                      q.append(curr.right)
                  c = c-1

              print("")

    def __right_tree(self,root):
        if root is None:
            print(-1)
            return
        elif root.right is None:
             print(root.val)
             return
        else:
            self.__right_tree(root.right)
    

    def __Left_tree(self,root):
        
        if root is None:
           print(-1)
           return
        elif root.left is None:
            
            print(root.val)
            return
            
        else:
            self.__Left_tree(root.left)

    def __find(self,root,val):
        if root is None:
            print(False)
            return
        elif root.val>val:
             self.__find(self.left,val)
        elif root.val>val:
             self.__find(self.right,val)
        else:
            print (True)
            return
        

            
        


        

    def Level_Order_Print(self):
        self.bfs(self.root)
    def insert(self,val):
        self.root = self.__Insert_Node(self.root,val)
    def remove(self,val):
        self.root = self.__Remove_Node(self.root,val)
    def max(self):
        
        self.__right_tree(self.root)
        
    def min(self):
        self.__Left_tree(self.root)
        
    def search(self,val):
        self.__find(self.root,val)
    def display(self):
        self.__Inorder(self.root)






r = BST()
r.insert(6)
r.insert(10)
r.insert(4)
r.insert(2)
r.insert(5)

r.insert(9)
r.insert(12)
r.display()
r.Level_Order_Print()
r.max()
r.min()
r.search(12)
r.remove(12)
r.remove(6)
r.remove(4)
print("")
r.Level_Order_Print()



