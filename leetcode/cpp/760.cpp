/*
 * Hash Table
 *
 */

class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> res;
        unordered_map<int, int> m;
        for (int i = 0; i < B.size(); ++i) m[B[i]] = i;
        for (int num : A) res.push_back(m[num]);
        return res;
    }
};