class Solution {
public:
    /**
     * The gray code is a binary numeral system where two successive values 
     * differ in only one bit.
     * Given a non-negative integer n representing the total number of bits 
     * in the code, print the sequence of gray code. A gray code sequence 
     * must begin with 0.
     */
    vector<int> grayCode(int n) {
        if (n == 0) return vector<int>({0});
        vector<int> gray_code({0,1});
        // given the gray numbers for n-1, take and add 2^(n-1) to each of them
        // and append them in reverse order. This works, because we know they
        // differ by only one bit and adding 2^(n-1) only changes one bit as well.
        for (int i = 1; i < n; i++) {
            int gray_code_size = gray_code.size();
            int offset = 1<<i; // 2^i
            for (int j = gray_code_size - 1; j >= 0; j--) {
                gray_code.emplace_back(gray_code[j] + offset);
            }
        }
        return gray_code;
    }
};
