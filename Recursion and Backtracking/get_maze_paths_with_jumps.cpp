// problem link: https://www.pepcoding.com/resources/online-java-foundation/recursion-with-arraylists/get-maze-path-with-jumps-official/ojquestion#
#include<bits/stdc++.h>
using namespace std;
vector<string> res;

void MazePathsWithJumps(int sr, int sc, int dr, int dc, string str)
{
    if(sr == dr && sc == dc)
    {
        res.push_back(str);
        return;
    }
    
    if(sc > dc || sr > dr)
    {
        return;
    }
    
    // horizontal moves
    for(int i=0; i<dc-sc; i++)
    {
        MazePathsWithJumps(sr, sc+i+1, dr, dc, str + "h" + to_string(i+1));
    }
    
    // vertical moves
    for(int i=0; i<dr-sr; i++)
    {
        MazePathsWithJumps(sr+i+1, sc, dr, dc, str + "v" + to_string(i+1));
    }
    
    // diagonal moves
    for(int i=0; i<dr-sr && i<dc-sc; i++)
    {
        MazePathsWithJumps(sr+i+1, sc+i+1, dr, dc, str + "d" + to_string(i+1));
    }
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    res.clear();
    if(n != 0 && m != 0)
    { 
        MazePathsWithJumps(0, 0, n-1, m-1, "");
        cout << "[";
        
        for(int i=0; i < res.size()-1; i++)
        {
            cout<<res[i]<<", ";
        }
        if(res.size()>0) cout<<res[res.size()-1];
        cout<<"]"<<endl;
    }
    else
    {
        cout<<"[]"<<endl;
    }
    return 0;
}
