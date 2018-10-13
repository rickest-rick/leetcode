class Solution {
public:
    /**
     * The count-and-say sequence is the sequence of integers with the first five terms as following:
     * 1.     1
     * 2.     11
     * 3.     21
     * 4.     1211
     * 5.     111221
     *
     * 1 is read off as "one 1" or 11.
     * 11 is read off as "two 1s" or 21.
     * 21 is read off as "one 2, then one 1" or 1211.
     * Given an integer n where 1 = n = 30, generate the nth term of the count-and-say sequence.
     */
    string countAndSay(int n) {
        string output = "1";
        for (int i = 2; i <= n; i++) {
            unsigned short count = 1;
            string nextOutput = "";
            for (int j = 0; j < output.size() - 1; j++) {
                // same digit, increase count
                if (output[j] == output[j + 1]) {
                    count++;
                } else { // end reached, write count and digit to next output
                    nextOutput += to_string(count);
                    nextOutput += output[j];
                    count = 1;
                }
            }
            // write last count and digit as well
            nextOutput += to_string(count);
            nextOutput += output[output.size() - 1];
            output = nextOutput;
        }
        return output;
    }
};
