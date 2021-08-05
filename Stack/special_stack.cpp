stack<int> helper;

void push(stack<int>& s, int a){
    s.push(a);
    if(! helper.empty()) 
    {
        if(helper.top() >= s.top()) helper.push(a);
    }
    else 
    {
        helper.push(a);
    }
	
}

bool isFull(stack<int>& s,int n){
	if(s.size() == n) return true;
	return false;
}

bool isEmpty(stack<int>& s){
	return s.empty();
}

int pop(stack<int>& s){
    if(helper.top() == s.top()) helper.pop();
    int temp = s.top();
    s.pop();
	return temp;
}

int getMin(stack<int>& s){
    return helper.top();
	
}
