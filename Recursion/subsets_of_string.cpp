// print all the subsets of given string:
// input: ABC
// output: " ", "A", "B", "C", "AB", "BC", "AC", "ABC"  

// recursive solution
// we have two possiblities either to add the new character to string or not to add

void subset(string str, string current, int index)
{
    if(index == str.length())
    {
        cout<<current<<" ";
    }
    subset(str, current, index+1); // not adding new character to the string 
    subset(str, current+str[index], index+1); // adding new character to the string
}
int main()
{
    subset("ABC", "", 0);
}
