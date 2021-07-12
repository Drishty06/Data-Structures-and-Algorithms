// problem link: https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1#
 void word_generator (int arr[], int n, string keypad[], vector <string> &res, int index, string str)
    {
        // idea is whatever is returned by "faith" part of recursion is appended with each of the first character and that results in all possible outcomes
        if(index == n)
        {
            res.push_back(str);
            return;
        }
        string helper=keypad[arr[index]];
        for(int i=0; i<helper.length(); i++)
        {
            word_generator(arr, n, keypad, res, index+1, str+helper[i]);
        }
    }
    
    vector<string> possibleWords(int arr[], int n)
    {
        string keypad[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; // to define the values as respective numbers
        vector <string> res;
        string str="";
        word_generator(arr, n, keypad, res, 0, str);
        sort(res.begin(), res.end());
        return res;
    }
