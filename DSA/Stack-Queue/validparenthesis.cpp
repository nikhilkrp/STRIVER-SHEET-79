class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else
            {
                if (!st.empty())
                {
                    if (st.top() == '{' && s[i] == '}')
                    {
                        st.pop();
                    }
                    else if (st.top() == '[' && s[i] == ']')
                    {
                        st.pop();
                    }
                    else if (st.top() == '(' && s[i] == ')')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        if (st.empty())
        {
            return true;
        }

        return false;
    }
};

// here i have maintained a stack to keep track of opening brackets and later
//  when i encounter a closing bracket i check if the top of the stack has the
// corresponding opening bracket if yes i pop it else return false if at the end
// stack is empty return true else false