class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<bool> alphabets(32, false);
        int ans = 0;

        for (char c = 'a'; c <= 'z'; c++) {
            int left = s.find(c) + 1;
            int right = s.rfind(c);
            int count = 0;

            while (left < right) {
                if (alphabets[s[left] - 'a'] == false) {
                    alphabets[s[left] - 'a'] = true;
                    count++;
                }
                left++;
            }

            ans += count;
            std::fill(alphabets.begin(), alphabets.end(), false);
        }
        return ans;
    }
};