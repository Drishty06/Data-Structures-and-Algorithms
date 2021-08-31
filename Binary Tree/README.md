use light mode to refer these notes to get clear idea
### 1. Types of Binary trees:
*       Full Binary Tree: Either have 0 or 2 childern. 
*       Complete Binary Tree: 1. All levels are completely filled except the last level.
                              2. the last level has nodes filled from left 
*       Perfect Binary Tree: all leaf nodes are at same level.
*       Balanced Binary Tree: height of binary tree is at max log2 (N) 
                                               OR 
                              Binary tree in which height of the left and the right sub-trees of every node may differ by at most 1
*       Degenerate Binary Tree: A Tree where every internal node has one child. Such trees are performance-wise same as linked list. 
*       Diagram representing all types of binary trees
![image](https://miro.medium.com/max/6300/1*CMGFtehu01ZEBgzHG71sMg.png) 
*       Full Binary Tree              Valid                    |              Invalid
![image](https://user-images.githubusercontent.com/77919644/131466141-4b1b6ee4-aabd-49ed-8fa5-eb70e84969a6.png)
*       Complete Binary Tree          Valid                    |              Invalid
![image](https://user-images.githubusercontent.com/77919644/131466491-284ae394-317c-4a80-9251-c09eac8b9712.png)
*       Perfect Binary Tree           Valid                    |              Invalid
![image](https://user-images.githubusercontent.com/77919644/131467335-e341bd0e-1296-4726-a3cf-8b3d33873679.png)
*       Balanced Binary Tree          Valid                    |              Invalid
![image](https://user-images.githubusercontent.com/77919644/131468495-070bc59b-ca16-46cd-b88e-84f8ab6308ef.png)
*       Degenerate Binary Tree        Valid                    |              Invalid
![image](https://user-images.githubusercontent.com/77919644/131468712-b981393e-7682-438f-a7bf-60cb15be2c88.png)

### 2. traversal techniques:
* DFS (Depth First Search): depth wise traversal
*       Inorder traversal: LEFT ROOT RIGHT
*       Preorder traversal: ROOT LEFT RIGHT
*       Postorder traversal: LEFT RIGHT ROOT   
