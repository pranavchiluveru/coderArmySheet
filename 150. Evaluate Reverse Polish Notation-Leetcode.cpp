class Solution {
public:

    int evalRPN(vector<string>& tokens) {
        /*
        unordered_set<string> ops({"+", "-", "*", "/"});
        stack<int> stack;
        for (auto t : tokens) {
            if (ops.find(t) == ops.end()) stack.push(stoi(t));
            else {
                int b = stack.top(); stack.pop();
                int a = stack.top(); stack.pop();
                if (t == "+") stack.push(a + b);
                else if (t == "-") stack.push(a - b);
                else if (t == "*") stack.push(a * b);
                else stack.push(a / b);
            }
        }
        return stack.top();
        */
        //TC=O(n) SC=O(n)
        stack<int> numbers;
        for (auto token : tokens) {
            //The isdigit() function takes the character to be tested as the argument.
            if (token.size() > 1 || isdigit(token[0])) {
                numbers.push(stoi(token));
            } else { 
                int operand2 = numbers.top();
                numbers.pop();
                int operand1 = numbers.top();
                numbers.pop();
                switch (token[0]) {
                    case '+': // Addition
                        numbers.push(operand1 + operand2);
                        break;
                    case '-': // Subtraction
                        numbers.push(operand1 - operand2);
                        break;
                    case '*': // Multiplication
                        numbers.push(operand1 * operand2);
                        break;
                    case '/': // Division
                        numbers.push(operand1 / operand2);
                        break;
                }                
            }
        }

        // The final result is the only number remaining on the stack
        return numbers.top();
    }
};
