// problem link: https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1#
// since large numbers' factorial cannot be stored in any data type and there will be an overflow rather
// so we store every element of factorial as a single element of array and later print it
vector<int> factorial(int n){
        // the solution is basically based on the multiplication which we used to do primary school
        vector<int> vec;
        vec.push_back(1);
        
        for(int i=n; i>1; i--)
        {
            int ans=1;
            int carry=0;
            int len=vec.size(),temp;
            for(int j=0; j<len; j++)
            {
                ans=i*vec[j];
                ans=ans+carry;
                vec[j]=ans%10;
                carry=ans/10;
            }
            while(carry != 0)
            {
                temp=carry%10;
                vec.push_back(temp);
                carry=carry/10;
            }
        }
        
        reverse(vec.begin(),vec.end());
        return vec;
    }
