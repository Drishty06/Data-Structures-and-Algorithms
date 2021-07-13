// problem link: https://www.pepcoding.com/resources/online-java-foundation/recursion-on-the-way-up/print-encodings-official/ojquestion
#include <bits/stdc++.h>
using namespace std;

void Encoding(string code, string helper)
{ // eg: input=654 
    
    if(code.length() == 0)
    {
        cout<<helper<<endl;
        return;
    }
    if(code.length() == 1)
    {
        int temp=code[0]-'0';
        if(temp != 0)
        {
            helper=helper+(char) (temp+'a'-1);
            cout<<helper<<endl;
            return;
        }
    }
    int digit1 = code[0]-'0'; // for first call -> digit1 = '6'-'0' = 54 - 48 
    int digit2 = (code[0]-'0')*10 + (code[1]-'0'); // for first call -> digit2 = ('6' - '0')*10 + ('5' - '0') = 60+5 = 65]

    char character1 = (char) (digit1+'a'-1); // for first call -> character1 = (char)(6 + 97 -1) = char(102) = f
    char character2 = (char) (digit2+'a'-1); // for first call -> character2 = (char)(65 + 97 -1) = char(161) 

    if(digit1 != 0) 
    {
        Encoding(code.substr(1), helper+character1);
    }
    if(digit2 >= 10 && digit2 <= 26) 
    {
        Encoding(code.substr(2), helper+character2);
    }
}

int main(){
    string code;
    cin>>code;
    Encoding(code,"");
    
}
