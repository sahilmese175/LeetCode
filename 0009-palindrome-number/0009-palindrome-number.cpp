class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        int original = x;
        long long rev_num = 0;

        while (x > 0) {
            int remainder = x % 10;
            rev_num = rev_num * 10 + remainder;
            x = x / 10;
        }

        return rev_num == original;
    }
};