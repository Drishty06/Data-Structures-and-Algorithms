// problem link: https://practice.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1

// using queue in O(n) time complexity
// idea: push 1 to the queue and push it into the vector,
// then append 0 as well as 1 making two variables and then appened both to the vector

vector<string> generate(int N)
{
    queue<string> q;
    vector<string> vec;
    q.push("1");
    for(int i=0; i<N; i++)
    {
        string s1 = q.front();
        vec.push_back(s1);
        q.pop();
        
        string s2 = s1;
        q.push(s1 + "0");
        q.push(s2 + "1");
    }
    return vec;
}
