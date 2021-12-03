// method is known as DNF sort
        // using 3 pointers low, mid and high
        int n = arr.size();
        int low=0, mid=0, high=n-1;
        
        while(mid <= high)
        {
            switch(arr[mid])
            {
                case 0: swap(arr[mid], arr[low]);
                low++;
                mid++;
                break;
                
                case 1: 
                mid++;
                break;
                
                case 2: swap(arr[mid], arr[high]);
                high--;
                
            }
        }
    }
