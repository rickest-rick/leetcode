class Solution {
public:
    /**
     * Given a 32-bit signed integer, reverse digits of an integer.
     * Return 0 if the integer overflows.
     */
    int reverse(int x) {
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
