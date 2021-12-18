// search space min(a, b) -> n* min(a,b)
        // 2->8
        // mid = 5 5/2 = 2 (2 divisors pehle aa chuke hai) 5/3 = 1 
        // 3 divisors before this number and this number is not divisible 3 <n
        // remove the left search space
        // search space
        long long int start = min(a, b);
        long long int end = n*(long long int)min(a, b);
        long long int mid;
        long long int mod = 1e9+7, ans;
        long long int lcm = (a*b)/(__gcd(a, b));
        while(start <= end)
        {
            mid = start + (end-start)/2;
            int total_divisors = mid/a + mid/b -mid/lcm;
            
            if(total_divisors < n)
            {
                start = mid+1;
            }
            else
            {
                ans = mid%mod;
                end = mid-1;
            }
        }
        return ans%mod;
    }
