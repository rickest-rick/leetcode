// SOLUTION CAN BE IMPROVED BY INCREASING expDivisor ONLY ONCE AND DECREASING IT AFTERWARDS
class Solution {
public:
    int divide(int dividend, int divisor) {
        // overflow
        if (divisor == -1 && dividend == INT_MIN) return INT_MAX; 
        bool sign = ((dividend > 0) ^ (divisor > 0)) ? true : false;
        unsigned int divRemaining = abs(dividend);
        unsigned int divsAbs = abs(divisor);
        unsigned int result = 0;
        while (divRemaining >= divsAbs) {
            unsigned int expDivisor = divsAbs;
            unsigned int count = 1;
            // subtract largest (2^k) * divisor <= target, add (2^k) to result
            while (divRemaining > expDivisor << 1 && expDivisor <= INT_MAX) {
                expDivisor <<= 1;
                count <<=1;
            }
            result += count;
            divRemaining -= expDivisor;
        }
        return sign ? -result : result;
    }
};
