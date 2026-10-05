class Solution {
public:
    int calculate(string s) {

        stack<long long> st;

        long long result = 0;
        long long number = 0;
        int sign = 1;

        for (int i = 0; i < s.length(); i++) {

            if (isdigit(s[i])) {
                number = number * 10 + (s[i] - '0');
            }

            else if (s[i] == '+') {
                result += sign * number;
                number = 0;
                sign = 1;
            }

            else if (s[i] == '-') {
                result += sign * number;
                number = 0;
                sign = -1;
            }

            else if (s[i] == '(') {
                st.push(result);
                st.push(sign);

                result = 0;
                sign = 1;
            }

            else if (s[i] == ')') {

                result += sign * number;
                number = 0;

                int previousSign = st.top();
                st.pop();

                long long previousResult = st.top();
                st.pop();

                result = previousResult + previousSign * result;
            }
        }

        result += sign * number;

        return (int)result;
    }
};