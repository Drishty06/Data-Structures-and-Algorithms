// problem link: https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
    // use a map and store horizontal distance from root as keys and elements as value(array)
    // idea is similar to that of vertical sum of binary tree
    // the difference here is that we have to do level order traversal
    // learnt about how to traverse through vector of maps
    
    void levelOrder(Node* root, map<int, vector<int>> &mp)
    {
        queue<pair<Node *, int>> q; // node as key and horizontal dist from root as value
        q.push({root, 0});
        
        while(q.size() != 0)
        {
            int count = q.size();
            for(int i=0; i<count; i++)
            {
                auto top = q.front();
                Node *curr = top.first;
                int horizontalDist = top.second;
                mp[horizontalDist].push_back(curr->data);
                q.pop();
                
                if(curr -> left) q.push({curr->left, horizontalDist - 1});
                if(curr -> right) q.push({curr->right, horizontalDist + 1});
            }
            
        }
    }
    
    vector<int> verticalOrder(Node *root)
    {
        map<int, vector<int>> mp;
        levelOrder(root, mp);
       
        vector<int> ans;
        for(auto i: mp)
        {
            for(auto j : i.second)
            {
                ans.push_back(j);
            }
        }
        
        return ans;
    }
