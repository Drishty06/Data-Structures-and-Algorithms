// problem link:https://codeforces.com/problemset/problem/1558/A
// A B A B A B... or B A B A B A...
// total match = a+b
// if a+b = even - serves of alice = serves of borys
// if a+b = odd - case1: alice serves a+b/2 times and borys total - (a+b/2)
//                case2: borys serves a+b/2 times and alice total - (a+b/2)
// to handle both odd and even we separately run two loops for number of times breaks occur
// break will occur in 2 cases- case1: alice serving and borys wins
//                              case2: borys serving and alice wins
// case 1: wins required > total number of service - win in all of their service(ni breaks in all those cases) + win in opponent's service(breaks)
// case 2: wins required < total number of service - win only (a for alice | b for borys) number of services from total services(no breaks) and rest will be breaks since opponent wins(breaks) 
//         or else win (a for alice | b for borys) opponent's services(breaks) and loose all their own services(breaks)

#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		long int a, b;
		cin>>a>>b;
		set<int> breaks;
		long int total_match = a+b;
		long int first_serve = (total_match/2);
		long int second_serve = (total_match)-first_serve;
		// case 2: second serve given to alice
		// A B A B A B A......
		for(long int number_of_service_borys_wins=0; number_of_service_borys_wins<=min(second_serve, b); number_of_service_borys_wins++)
		{
			if(b - number_of_service_borys_wins <= first_serve )
				breaks.insert(second_serve - number_of_service_borys_wins + b - number_of_service_borys_wins);
		}
		// case 1: first serve given to borys
		// B A B A B A B......
		for(long int number_of_service_borys_wins=0; number_of_service_borys_wins<=min(first_serve, b); number_of_service_borys_wins++)
		{
		   if(b - number_of_service_borys_wins <= second_serve)
				breaks.insert(first_serve - number_of_service_borys_wins + b - number_of_service_borys_wins);
		}


		cout<<breaks.size()<<endl;
		for(auto i: breaks) 
		{
			cout<<i<<" ";
		}

		cout<<endl;
		
	}
	return 0;
}
