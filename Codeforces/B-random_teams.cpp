// problem link: 
// we don't have to count the permutations, we have to count only the combinations
 
#include <bits/stdc++.h>
using namespace std;
 
int main() 
{ 
	long long int n, m, kmin, kmax, remaining, min_each; // minimum people in each team;
	cin>>n>>m;
	// for k max only one group will have all rest members after divding equally
	kmax = ((n-m+1) * (n-m))/2;
	// for kmin
	// equally divided in each team
	min_each = (n/m);
	remaining = n - (min_each * m);
	long long int group1; // more people
	long long int group2; // less people
	group1 = remaining;
	group2 = m-remaining;
	kmin = group1 * (((min_each+1) * (min_each))/2) + group2 * (((min_each) * (min_each-1))/2);
	cout<<kmin<<" "<<kmax<<endl;
	return 0;
}
