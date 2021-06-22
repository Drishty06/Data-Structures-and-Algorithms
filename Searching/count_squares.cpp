#include <bits/stdc++.h>
using namespace std;
int countSquares(int a, int b)
{
    return (floor(sqrt(b)) - ceil(sqrt(a)) + 1);
}
int main()
{
    int a = 9, b = 25;
    cout << "Count of squares is "<< countSquares(a, b);
    return 0;
}
