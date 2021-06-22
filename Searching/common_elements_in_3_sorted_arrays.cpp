// problem link: https://practice.geeksforgeeks.org/problems/common-elements1132/1#

vector <int> commonElements (int a[], int b[], int c[], int n1, int n2, int n3)
        {
            vector <int> ans;
            int i=0, j=0, k=0;
            // using three pointers
            while(i < n1 && j < n2 && k < n3)
            {
                int maximum = max(max(a[i], b[j]), c[k]); // searching for the maximum element from three of them
                
                while(a[i] <= maximum && i < n1) i++; // moving the first pointer until we reach a element either = or greater than maximum
                i--;
                while(b[j] <= maximum && j < n2) j++; // similarly moving second and third pointers
                j--;
                while(c[k] <= maximum && k < n3) k++;
                k--;
                
                if(a[i] == b[j] && b[j] == c[k]) ans.push_back(a[i]); // checking if they are same 
                i++;
                j++;
                k++;
            }
            return ans;
        }
