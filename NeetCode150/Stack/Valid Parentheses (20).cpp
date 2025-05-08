class Solution {
    public:
        bool isValid(string s) {
            // Should never have more open than closed brackets (push open, pop closed)
            stack<char> order;
            for(char c: s){
                switch(c){  // Return false if a) there is no matching open bracket for the current closing bracket to close (stack is empty)
                    // or b) there's a mismatch between the current bracket and last (unclosed) open bracket (wrong type)
                    case ')':
                        if(order.empty() || order.top() != '(')    return false;
                        order.pop();
                        break;
                    case '}':
                        if(order.empty() || order.top() != '{')    return false;
                        order.pop();
                        break;
                    case ']':
                        if(order.empty() || order.top() != '[')    return false;
                        order.pop();
                        break;
                    default:    // Push any of the closing type of bracket
                        order.push(c);
                        break;
                }
            }
            return order.empty();
        }
    };