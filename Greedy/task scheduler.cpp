int leastInterval(vector<char>& tasks, int n) {
    int highestFreq = 0, numberOfMostFreq = 0;
    
    unordered_map<char, int> freq;
    for(auto i: tasks)
    {
        freq[i]++;
        highestFreq = max(highestFreq , freq[i]);
    }
    for(auto i: freq)
    {
        if(i.second == highestFreq) 
        {
            numberOfMostFreq++;
        }
    }
        return max((highestFreq - 1) * (n+1) + numberOfMostFreq , (int)tasks.size());

    }
