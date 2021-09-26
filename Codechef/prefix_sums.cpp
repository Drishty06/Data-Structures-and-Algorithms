// problem link: codechef.com/LTIME100B/problems/UNQEQ/
#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		long int n;
		cin>>n;
		if(((n/2) % 2) != 0 || n==2) cout<<"NO"<<endl;
		else
		{
		    cout<<"YES"<<endl;
		    long int num=1;
		    bool check = false;
		    while(num <= n)
		    {
		        if(num > (n/2) && check == false)
		        {
		            num++;
		            check =true;
		        }
		        
		        cout<<num<<" ";
		        num+=2;
		        
		    }
		    cout<<endl;
		    num = 2;
		    check = false;
		    while(num <= n)
		    {
		        if(num > (n/2) && check == false)
		        {
		            num--;
		            check =true;
		        }
		        
		        cout<<num<<" ";
		        num+=2;
		        
		    }
		    cout<<endl;
		}
	}
	return 0;
}
