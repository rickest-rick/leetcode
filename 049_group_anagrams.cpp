class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> string_buckets;
        for (auto& value : strs) {
            // sort characters of string as key for anagrams
            string key = value;
            sort(key.begin(), key.end());
            // key not yet mapped -> start new bucket
            if (string_buckets.count(key) == 0) {
                string_buckets[key] = vector<string>({value});
            } else { // key is already present -> append to bucket
                string_buckets[key].emplace_back(value);   
            }
        }
        // copy all buckets to a vector of vectors of strings
        vector<vector<string>> output_buckets(string_buckets.size());
        int i = 0;
        for (auto& bucket : string_buckets) {
            output_buckets[i++] = bucket.second;
        }
        return output_buckets;
    }
};
