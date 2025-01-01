class Solution {
public:
    int maxScore(string s) {
        int leftScore = s[0] == '0', rightScore = 0;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '1') rightScore += 1;
        }

        int maxScore = leftScore + rightScore;
        for (int i = 1; i < s.size() - 1; i++) {
            if (s[i] == '0') leftScore++;
            if (s[i] == '1') rightScore--;
            maxScore = max(maxScore, leftScore + rightScore);
        }

        return maxScore;
    }
};