### 1. Types of Binary trees:
*       Full Binary Tree: Either have 0 or 2 childern. 
*       Complete Binary Tree: 1. All levels are completely filled except the last level.
                              2. the last level has nodes filled from left 
*       Perfect Binary Tree: all leaf nodes are at same level.
*       Balanced Binary Tree: height of binary tree is at max log2 (N)
*       Degenerate Binary Tree: A Tree where every internal node has one child. Such trees are performance-wise same as linked list. 
![image](https://miro.medium.com/max/6300/1*CMGFtehu01ZEBgzHG71sMg.png) 
*       Full Binary Tree          Valid                        |              Invalid
![image](https://user-images.githubusercontent.com/77919644/131466141-4b1b6ee4-aabd-49ed-8fa5-eb70e84969a6.png)
*       Complete Binary Tree          Valid                    |              Invalid
![image](https://user-images.githubusercontent.com/77919644/131466491-284ae394-317c-4a80-9251-c09eac8b9712.png)

### 2. traversal techniques:
* DFS (Depth First Search): depth wise traversal
*       Inorder traversal: LEFT ROOT RIGHT
*       Preorder traversal: ROOT LEFT RIGHT
*       Postorder traversal: LEFT RIGHT ROOT   
