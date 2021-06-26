// problem link: https://www.codechef.com/LTIME97C/problems/HTMLTAGS/
#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t ; i++)
	{
		string str;
		cin>>str;
		long int n=str.length();
		if(n <= 3) cout<<"Error"<<endl; // to check for the edge case when the string length is smaller than 3 and empty body isn't allowed as well
    
		if(str[0] == '<' && str[1] == '/' && str[n-1] == '>') // to check for the basic syntax </>
		{
		    for(int j=2; j<n-1; j++)
		    {
		        if((str[j] >= 'a' && str[j] <= 'z' ) || str[j] >= '0' && str[j] <= '9') // to check if body is aplha numeric
		        {
		            if(j == n-2) cout<<"Success"<<endl;
		        }
		        else 
		        {
		            cout<<"Error"<<endl;
		            break;
		        }
		        
		    }
		    
		}
		else 
		{
		    cout<<"Error"<<endl;
		}
	}
	return 0;
}
