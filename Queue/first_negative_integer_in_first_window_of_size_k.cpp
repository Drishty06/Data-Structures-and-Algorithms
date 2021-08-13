// problem link: https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
// idea:
// deque using window sliding technique
// here we store indices of only negative numbers into the deque
// 1. we run a loop for first k elements
// 2. for rest of the elements, we check we current index has negative elements, if yes we push it back
// 3. along with this we remove the elements whose indices are smaller than i-k

vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k)
{
     deque<long long> dq;
     vector<long long> vec;
     for(int i=0; i<k; i++)
     {
         if(arr[i] < 0) dq.push_back(i);
     }
     if(dq.empty()) vec.push_back(0);
     else vec.push_back(arr[dq.front()]);
     
     for(int i=k; i<n; i++)
     {
         if(dq.empty() == false && dq.front() <= i-k) dq.pop_front();
         if(arr[i] < 0) dq.push_back(i);
         if(dq.empty()) vec.push_back(0);
         else vec.push_back(arr[dq.front()]);
     }
     return vec;
}
