// problem link: https://practice.geeksforgeeks.org/problems/vertical-sum/1
  // make a map and store horizontal dist from root as key and their sum as value
  
  void solve(Node* root, int horizontalDist, map<int, int> &mp){
      
      if(root == NULL) return;
      
      solve(root->left, horizontalDist-1, mp);
      mp[horizontalDist] += root->data;
      solve(root->right, horizontalDist+1, mp);
      
  }
      
  
    vector <int> verticalSum(Node *root) {
        map<int, int> mp;
        solve(root, 0, mp);
        
        vector <int> ans;
        for(auto i: mp){
            ans.push_back(i.second);
        }
        return ans;
    }
