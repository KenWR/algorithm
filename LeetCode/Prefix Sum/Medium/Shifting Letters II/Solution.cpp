// Prefix Sum

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> prefixSum(s.size() + 1, 0);

        for (const auto& shift : shifts) {
            int start = shift[0], end = shift[1], move = 0;
            if (shift[2]) move = 1;
            else move = -1;

            prefixSum[start] += move;
            prefixSum[end + 1] -= move;
        }

        vector<int> shifted(s.size(), 0);
        int sum = 0;
        for (int i = 0; i < prefixSum.size() - 1; i++) {
            sum += prefixSum[i];
            shifted[i] = sum;
        }

        string newString = "";
        for (int i = 0; i < shifted.size(); i++) {
            int alphaNumber = (s[i] - 'a' + shifted[i]) % 26;

            if (alphaNumber < 0) alphaNumber += 26;
            newString += static_cast<char>(alphaNumber + 'a');
        }

        return newString;
    }
};