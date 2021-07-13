// problem link: https://www.pepcoding.com/resources/online-java-foundation/recursion-on-the-way-up/print-maze-paths-official/ojquestion#!
// idea: use the pepcoding method of srawing start to destination with intermediate states diagram
// draw the recursion tree for the same 
#include <iostream>
using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string str)
{
    if(sc == dc && sr == dr)
    {
        cout<<str<<endl;
        return;
    }
    if(sc > dc || sr > dr)
    {
        return;
    }
    printMazePaths(sr, sc+1, dr, dc, str+"h");
    printMazePaths(sr+1, sc, dr, dc, str+"v");
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    printMazePaths(0, 0, n - 1, m - 1, "");
}
