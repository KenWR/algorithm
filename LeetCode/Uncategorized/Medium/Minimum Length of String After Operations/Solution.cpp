class Solution {
public:
    int minimumLength(string s) {
        vector<int> alphabetIndex(26);

        for(int i = 0; i < s.size(); i++) {
            alphabetIndex[s[i] - 'a']++;
        }

        int minLength = 0;
        for(int i = 0; i < alphabetIndex.size(); i++) {
            if (alphabetIndex[i]) {
                if (alphabetIndex[i] % 2) minLength += 1;
                else if (alphabetIndex[i] % 2 == 0) minLength += 2;
            }
        }

        return minLength;
    }
};