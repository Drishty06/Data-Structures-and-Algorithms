// problem link: https://www.pepcoding.com/resources/online-java-foundation/recursion-with-arraylists/get-stair-paths-official/ojquestion
// explanation video: https://www.youtube.com/watch?v=hMJAlbJIS7E&list=PL-Jc9J83PIiFxaBahjslhBD1LiJAV7nKs&index=29
#include <bits/stdc++.h>
using namespace std;
vector <string> res;

void printPath(int n, string path)
{
    if(n < 0) 
    {
        return;
    }
    if(n == 0)
    {
        res.push_back(path);
        
        return;
    }
	  printPath(n-1, path+"1");
          printPath(n-2, path+"2");
	  printPath(n-3, path+"3");

}

int main()
{
    int n;
    cin>>n;
    string path="";
    res.clear();
    printPath(n, path);

    if(res.size() == 0)
    {
        cout<<"[]";
    }
    else if(res.size() == 1)
    {
        cout<<"["<<res[0]<<"]";
    }
    else
    {
        cout<<"[";
        for (int i=0; i<res.size()-1; i++)
        {
            cout<<res[i]<<", ";
        }
        cout<<res[res.size()-1];
        cout<<"]";
    }
	return 0;
}
