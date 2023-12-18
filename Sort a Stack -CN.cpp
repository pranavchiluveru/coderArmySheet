#include <bits/stdc++.h> 
void sortInsert(int x,stack<int> &stack)
{
	if(stack.empty()||x>stack.top())
	{
		stack.push(x);
	}
	else
	{
		int y=stack.top();
		stack.pop();
		sortInsert(x,stack);
		stack.push(y);
	}
}
void sortStack(stack<int> &stack)
{
	// Write your code here
        if (!stack.empty()) {
                int ele = stack.top();
                stack.pop();
				sortStack(stack);
                sortst(ele, stack);
        }
}
