// THE EXPONENTIAL DIVISOR IS INCREASED ONLY ONCE AND DECREASED AFTERWARDS BY SHIFTING
// // TO THE LEFT. THIS MEANS WE DON'T HAVE TO RIGHT SHIFT FROM 1 ONWARDS MULTIPLE TIMES.
// // SOLUTION CAN BE IMPROVED BY USING THE LOG INSTEAD OF A LOOP IN THE BEGINNING.
class Solution {
public:
	// THE EXPONENTIAL DIVISOR IS INCREASED ONLY ONCE AND DECREASED AFTERWARDS BY SHIFTING
	// // TO THE LEFT. THIS MEANS WE DON'T HAVE TO RIGHT SHIFT FROM 1 ONWARDS MULTIPLE TIMES.
	// // SOLUTION CAN BE IMPROVED BY USING THE LOG INSTEAD OF A LOOP IN THE BEGINNING.
    int divide(int dividend, int divisor) {
        // overflow
        if (divisor == -1 && dividend == INT_MIN) return INT_MAX; 
        bool sign = ((dividend > 0) ^ (divisor > 0)) ? true : false;
        unsigned int divRemaining = abs(dividend);
        unsigned int expDivisor = abs(divisor);
        unsigned int result = 0;
        unsigned int count = 1;
        if (divRemaining >= expDivisor) {
            // subtract largest (2^k) * divisor <= target, add (2^k) to result
            while (divRemaining > expDivisor << 1 && expDivisor <= INT_MAX) {
                expDivisor <<= 1;
                count <<= 1;
            }
            result += count;
            divRemaining -= expDivisor;
            while (divRemaining >= abs(divisor)) {
                // decrease expDivisor until it is smaller than divRemaining
                while (expDivisor > divRemaining) {
                    expDivisor >>= 1;
                    count >>= 1;
                }
                result += count;
                divRemaining -= expDivisor;
            }
        }
        return sign ? -result : result;
    }
};
