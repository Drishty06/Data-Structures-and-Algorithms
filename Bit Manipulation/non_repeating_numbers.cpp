// problem link: https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1
// intuition behind this approach: 
// https://www.youtube.com/watch?v=pnx5JA9LNM4 - pepcoding explanation
// * xor of same numbers will be zero so xor of all such 2*n+2 numbers will actually be equivalent to xor of the two distinct elements
// * if we select any set bit of all xor numbers, one thing is for sure that bit at that position in the two distinct numbers will be different
// * therefore we make two groups, one group is of the elements have 0 at the position which is rightmost set bit in xor of all numbers
// * in another group we keep all the elements which have 1 at the position which is rightmost set bit in xor of all numbers
// let x and y be distinct elements
    vector<int> singleNumber(vector<int> nums) 
    {
        vector <int> ans;
        int XxorY = 0, n = nums.size();
        for(int i=0; i<n; i++)
        {
            XxorY = XxorY ^ nums[i];
        }
        // xor of all numbers is equivalent is equal to xor of two distinct elementa. since sor of same elements is 0
        // getting rightmost bit of XxorY
        
        int x = 0, y = 0;
        int rightBit = XxorY & -XxorY;
        for(int i=0; i<n; i++)
        {
            if((nums[i] & rightBit) == 0)
            {
                x = x ^ nums[i];   
            }
            else
            {
                y = y ^ nums[i];
            }
        }
        ans.push_back(x);
        ans.push_back(y);
        sort(ans.begin(), ans.end());
        return ans;
    }
