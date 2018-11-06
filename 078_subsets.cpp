class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // start with the empty set
        vector<vector<int>> subsets({vector<int>()});
        // for every number in numbs, attach this number to a copy 
        // of every subset that exists so far
        for (auto& number : nums) {
            int n = subsets.size();
            for (int i = 0; i < n; i++) {
                vector<int> enlarged_subset = subsets[i];
                enlarged_subset.emplace_back(number);
                subsets.emplace_back(enlarged_subset);
            }
        }
        return subsets;
    }
};
