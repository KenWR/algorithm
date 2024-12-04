class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int len1 = str1.size(), len2 = str2.size();
        if (len1 < len2) return false;

        int idx2 = 0;
        for (int idx1 = 0; idx1 < len1 && idx2 < len2; idx1++) {
            if (str1[idx1] == str2[idx2] ||
                str1[idx1] + 1 == str2[idx2] ||
                str1[idx1] - 25 == str2[idx2]) {
                idx2++;
            }
        }

        return idx2 == len2;
    }
};