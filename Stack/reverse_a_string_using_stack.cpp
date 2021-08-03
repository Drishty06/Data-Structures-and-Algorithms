// problem link: https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1
char* reverse(char *str, int len)
{
    stack<char> s;
    for(int i=0; i<len; i++)
    {
        s.push(str[i]);
    }
    for(int i=0; i<len; i++)
    {
        str[i] = s.top();
        s.pop();
    }
    return str;
}
