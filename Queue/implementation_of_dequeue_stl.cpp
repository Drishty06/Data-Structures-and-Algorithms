#include <iostream> 
#include <deque> 
  
using namespace std; 
  
void display(deque <int> x) 
{ 
    deque <int> :: iterator it; 
    for (it = x.begin(); it != x.end(); ++it) 
        cout << ' ' << *it; 
    cout << '\n'; 
} 
  
int main() 
{ 
    deque<int> a; 
    a.push_back(10); 
    a.push_front(20); 
    a.push_back(30); 
    a.push_front(15); 
    cout << "The deque a is : "; 
    display(a); 
  
    cout << "a.size() : " << a.size()<<endl; 
    cout << "a.front() : " << a.front()<<endl; 
    cout << "a.back() : " << a.back()<<endl; 
  
    cout << "a.pop_front() : "<<endl; 
    a.pop_front(); 
    display(a); 
  
    cout << "a.pop_back() : "<<endl; 
    a.pop_back(); 
    display(a); 
  
    return 0; 
} 
