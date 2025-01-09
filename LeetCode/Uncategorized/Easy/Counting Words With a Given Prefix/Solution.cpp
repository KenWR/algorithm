class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        
        for(const auto& word : words) {
            bool flag = true;
            if (pref.size() > word.size()) flag = false;
            else {
                for(int i = 0; i < pref.size(); i++) {
                    if (word[i] != pref[i]) flag = false;
                }
            }
            if (flag) count++;
        }

        return count;
    }
};