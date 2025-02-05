class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        pair<char, char> s1_diff(0, 0), s2_diff(0, 0);

        int diff_count = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                diff_count++;
                if (s1_diff.first == 0) {
                    s1_diff.first = s1[i];
                    s2_diff.first = s2[i];
                }
                else {
                    s1_diff.second = s1[i];
                    s2_diff.second = s2[i];
                }
            }
        }

        if (diff_count == 0) return true;
        if (diff_count != 2) return false;
        if (s1_diff.first == s2_diff.second && s1_diff.second == s2_diff.first) return true;

        return false;
    }
};