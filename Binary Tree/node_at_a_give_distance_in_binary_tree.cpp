// problem link: https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1
    // issue: we can travel toeards left and right of a node but we cannot travel upwards
    // solution: make a collection of parent pointers by doing a level order traversal. and then from every node, we can go towards its left, right, and upwards
    // idea of the approach:
    // 1. we have 3 directions: left, right, up. to traverse upwards, we collect parent pointers list.
    //    to do so, we will traverse the tree in level order traversal and will have a hash which will be stroing parent pointers of current nodes.
    // 2. we go to the target node.and establish a queue.
    //    in this queue, our first step will be to add left node, right node, and node present upwards into the queue.
    //    and along with this we will keep on decrementing the "k".
    // 3. along with this we need to check whether any of the element is already visited. 
    //    so we will form a "visited array" along with step no.2.
    
    void parent_pointer(unordered_map<Node*, Node*> &mp, Node *node) // to have the parent pointers of every node
    {
        queue<Node *> q;
        q.push(node);
        
        int idx=0;
        while(q.size() != 0)
        {
            int count = q.size();
            for(int i=0; i<count; i++)
            {
                Node *top = q.front();
                q.pop();
                if(top != NULL) 
                {
                    
                    if(top -> left) 
                    {
                        mp[top->left] = top;
                        q.push(top->left);
                    }
                    if(top -> right) 
                    {
                        mp[top->right] = top;
                        q.push(top->right);
                    }
                }
            }
            
        }
    }
    
    Node* target_node(int Target, Node* node)
    {
        if (node == NULL) return NULL;
        if (node->data == Target) return node;
        Node* res1 = target_node(Target, node->left);
        if(res1) return res1;
        Node* res2 = target_node(Target, node->right);
        return res2;
    }

    vector <int> KDistanceNodes(Node* root, int Target , int k)
    {
        unordered_map <Node*, Node*> mp;
        parent_pointer(mp, root);
        Node* target = target_node(Target, root);
        unordered_map <Node*, bool> visited; // visited hash
        queue <Node*> q;
        q.push(target);
        visited[target] = 1;
        int curr_level = 0;
        while(q.size() != 0)
        {
            int count = q.size();
            if(curr_level++ == k) break;
            for(int i=0; i<count; i++)
            {
                Node* top = q.front();
                q.pop();
                if(top != NULL) 
                {
                    
                    if(top -> left && !visited[top->left]) 
                    {
                        q.push(top->left);
                        visited[top->left] = 1;
                    }
                    
                    if(top -> right && !visited[top->right]) 
                    {
                        q.push(top->right);
                        visited[top->right] = 1;
                    }
                    
                    if(mp[top] && !visited[mp[top]])
                    {
                        q.push(mp[top]);
                        visited[mp[top]] = 1;
                    }
                }
            }
        }
        vector <int> ans;
        while(q.size() != 0)
        {
            Node *top = q.front();  
            q.pop();
            ans.push_back(top->data); 
        }
        sort(ans.begin(), ans.end());
       return ans;
    }
