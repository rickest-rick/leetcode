// SOLUTION USING THE REVERSE FUNCTION OF 007. CAN BE IMPROVED BY ONLY CHECKING HALF 
// OF THE DIGITS
class Solution {
public:
    bool isPalindrome(int x) {
        // negative can't be palindrome
        if (x < 0) return false;
        
        // reverse digits and check if equal
        int reverse = reverseInt(x);
        return reverse == x;
    }

private:
    /**
     * Given a 32-bit signed integer, reverse digits of an integer.
     * Return 0 if the integer overflows.
     */
    int reverseInt(int x) {
        long output = 0;
        while (x) {
            // append smallest digit to output; since x % 10 returns negative 
            // digits for negative x, we don't have to consider sign separately
            output = (10 * output) + x % 10;
            // delete smallest remaining digit
            x /= 10;
        }
        // return value with check for overflows
        return (output < INT_MIN || output > INT_MAX) ? 0 : output;
    }
};
