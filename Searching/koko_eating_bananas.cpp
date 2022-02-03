// intuition: I realized that if we don't consider piles wise, we will require total bananas/h amount of k(minimum) if piles' constraint was not there.
    // for eg: piles = [30,11,23,4,20], h = 6 
    // total bananas = 88 => minimum k = 88/6 = 17... = 18
    // minimmum to minimum, koko has to eat 18 bananas in an hour
    // maximum k will be when h = piles.length
    // so in that case every pile should take 1 hr only
    // so in this case k = max(piles[i])
    // in this example maximum k = 30
    // so in this example, k => [18, 30]
    // so from this I got the idea that this is a binary search question, since I have a range and every time I can compare hours of mid k with h and eliminate the search space
    
    int binarySearchKoko(vector<int> &piles, int mid, int h, int n)
    {
        int hours = 0;
        for(int i=0; i<n; i++)
        {
            if(piles[i] % mid != 0)
            {
                hours = hours + piles[i]/mid + 1;
            }
            else
            {
                hours = hours + piles[i]/mid;
            }
        }
        return hours;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low, high=0;
        long int sum=0;
        int n = piles.size();
        for(int i=0; i<n; i++)
        {
            high = max(high, piles[i]);
            sum += piles[i];
        }
       
        if(sum % h != 0)
        {
            low = sum/h + 1;
        }
        else 
        {
            low = sum/h;
        }
        while(low < high)
        {
            int mid = low + (high-low)/2;
            int hours = binarySearchKoko(piles, mid, h, n);
            if(hours > h)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }
