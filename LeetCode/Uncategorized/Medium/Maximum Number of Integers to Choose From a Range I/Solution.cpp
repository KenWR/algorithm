class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int sum = 0;
        int count = 0;
        
        sort(banned.begin(), banned.end());

        for(int i = 1, bannedIndex = 0; i <= n; ++i) {
            if (bannedIndex < banned.size() && i == banned[bannedIndex]) {
                while(bannedIndex < banned.size() && i == banned[bannedIndex]) bannedIndex += 1;
                continue;
            }
            sum += i;
            if (sum > maxSum) {
                break;
            }
            count += 1;
        }
        return count;
    }
};