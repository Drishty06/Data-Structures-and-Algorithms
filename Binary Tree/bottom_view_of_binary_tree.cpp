
  // problem link: https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
  // this is almost similar to top view of binary tree
  // just one change: we overwrite value in map when they are seen again since we want the last such value
  // to do that i used this article : https://stackoverflow.com/questions/4527686/how-to-update-stdmap-after-using-the-find-method
  
  void verticalTraversal(Node* root, map<int, int> &mp)
    {
        queue<pair<Node *, int>> q; // node as key and horizontal dist from root as value
        q.push({root, 0});
        int idx=0;
        
        while(q.size() != 0)
        {
            int count = q.size();
            
            for(int i=0; i<count; i++)
            {
                auto top = q.front();
                Node* curr = top.first;
                int horizontalDist = top.second;
                
                map<int, int>::iterator it = mp.find(horizontalDist); // to overwrite values in maps
                if (it != mp.end()) it->second = curr->data;
                else
                {
                    mp[horizontalDist] = curr->data;
                }
                q.pop();
                
                if(curr -> left) q.push({curr->left, horizontalDist - 1});
                if(curr -> right) q.push({curr->right, horizontalDist + 1});
            }
        }
    }
  
  
    vector <int> bottomView(Node *root) {
        map<int, int> mp;
        vector <int> ans;
        verticalTraversal(root, mp);
        for(auto i: mp){
            ans.push_back(i.second);
        }
        return ans;
    }
