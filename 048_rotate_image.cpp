class Solution {
public:
    /**
     * You are given an n x n 2D matrix representing an image. 
     * Rotate the image by 90 degrees (clockwise).
     */
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int no_loops = n / 2;
        // for every loop of the matrix
        for (int i = 0; i < no_loops; i++) {
            // for every quadruplet of this loop
            for (int j = 0; j < n - (2 * i + 1); j++) {
                // rotate the four points
                swap(matrix[i][i + j], matrix[i + j][n - i - 1]);
                // upper right is in upper left
                swap(matrix[i][i + j], matrix[n - i - 1][n - i - j - 1]);
                // lower right is in upper left
                swap(matrix[i][i + j], matrix[n - i - 1 - j][i]);
            }
        }
    }
};
