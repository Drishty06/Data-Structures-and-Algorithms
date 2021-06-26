// for more info visit: https://www.geeksforgeeks.org/find-recurring-sequence-fraction/
#include <bits/stdc++.h>
using namespace std;
 
// This function returns repeating sequence of
// a fraction.  If repeating sequence doesn't
// exits, then returns empty string
string fractionToDecimal(int numr, int denr)
{
    string res; // Initialize result
 
    // Create a map to store already
    // seen remainders remainder is used
    // as key and its position in
    // result is stored as value.
    // Note that we need
    // position for cases like 1/6.
    // In this case,the recurring sequence
    // doesn't start from first
    // remainder.
    map<int, int> mp;
    mp.clear();
 
    // Find first remainder
    int rem = numr % denr;
 
    // Keep finding remainder until either remainder
    // becomes 0 or repeats
    while ((rem != 0)
           && (mp.find(rem) == mp.end()))
    {
        // Store this remainder
        mp[rem] = res.length();
 
        // Multiply remainder with 10
        rem = rem * 10;
 
        // Append rem / denr to result
        int res_part = rem / denr;
        res += to_string(res_part);
 
        // Update remainder
        rem = rem % denr;
    }
 
    return (rem == 0) ? "" : res.substr(mp[rem]);
}
 
// Driver code
int main()
{
    int numr = 50, denr = 22;
    string res = fractionToDecimal(numr, denr);
    if (res == "")
        cout << "No recurring sequence";
    else
        cout << "Recurring sequence is " << res;
    return 0;
}
 
