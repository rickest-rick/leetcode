class Solution {
public:
    /** 
     * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
     *
     * Symbol       Value
        I             1
        V             5
        X             10
        L             50
        C             100
        D             500
        M             1000

     * Roman numerals are usually written largest to smallest from left to right. 
     * However, the numeral for four is not IIII. Instead, the number four is written 
     * as IV. Because the one is before the five we subtract it making four. The same 
     * principle applies to the number nine, which is written as IX. There are six 
     * instances where subtraction is used:

     * I can be placed before V (5) and X (10) to make 4 and 9. 
     * X can be placed before L (50) and C (100) to make 40 and 90. 
     * C can be placed before D (500) and M (1000) to make 400 and 900.

     * Given a roman numeral, convert it to an integer. Input is guaranteed to be within 
     * the range from 1 to 3999.
     */
    int romanToInt(string s) {
        unsigned int intSol = 0;
        unsigned int currentDigit = 0, prevDigit = 0;
        for(int i = 0; i < s.size(); i++) {
            // if the current digit is larger than the previous, subtract prev value twice
            currentDigit = getValueOfRoman(s.at(i));
            if (currentDigit > prevDigit) {
                intSol -= (2 * prevDigit);
            }
            intSol += currentDigit;
            prevDigit = currentDigit;
        }
        return intSol;
    }
    
private: 
    unsigned int getValueOfRoman(char c) {
        switch(c) {
            case 'I' : return 1; break;
            case 'V' : return 5; break;
            case 'X' : return 10; break;
            case 'L' : return 50; break;
            case 'C' : return 100; break;
            case 'D' : return 500; break;
            case 'M' : return 1000; break;
        }
    }
}; 
