// problem link: https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1
int doUnion(int a[], int n, int b[], int m)  {
        sort(a, a+n);
        sort(b, b+m);
        long int i=0, j=0,count=0;
        while(i < n && j < m)
        {
            if(i > 0 && a[i] == a[i-1])
            {
                i++;
                continue;
            }
            if(j > 0 && b[j] == b[j-1])
            {
                j++;
                continue;
            }
            if(a[i] < b[j])
            {
                count++;
                i++;
            }
            else if(b[j] < a[i])
            {
                count++;
                j++;
            }
            else
            {
                count++;
                i++;
                j++;
            }
        }
        while(i < n)
        {
            if( a[i] != a[i-1])
            {
                count++;
            }
            i++;
        }
        
        while(j < m)
        {
            if( b[j] != b[j-1])
            {
                count++;
            }
            j++;
        }
        return count;
    }
