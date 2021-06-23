int maxProduct(vector<int>& arr) {
        // modified kadane's algorithm
        // issue is when we encounter a negative number
        // so used two variables to store min and max of the products so that if upcoming number is negative, it can pair up with negative product to give the maximum
        int best=arr[0];
        int max_product=arr[0], min_product=arr[0];
        int n=arr.size();
        for(int j=1; j<n; j++)
        {
            if(arr[j] < 0) swap(max_product, min_product);
            max_product=max(arr[j],arr[j]*max_product);
            min_product=min(arr[j],arr[j]*min_product);
            best=max(max_product,best);
        }
        return best;
    }
};
