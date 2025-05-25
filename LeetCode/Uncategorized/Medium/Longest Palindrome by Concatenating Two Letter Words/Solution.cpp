class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        vector<vector<int>> alphabets(26, vector<int>(26));
        int answer = 0;
        for (int i = 0; i < words.size(); ++i) {
            int row = words[i][0] - 'a';
            int col = words[i][1] - 'a';
            if (alphabets[col][row]) {
                alphabets[col][row]--;
                answer += 4;
            } else {
                alphabets[row][col]++;
            }
        }
        for (int i = 0, j = 0; i < 26; ++i, ++j) {
            if (alphabets[i][j]) {
                answer += 2;
                break;
            }
        }
        return answer;
    }
};