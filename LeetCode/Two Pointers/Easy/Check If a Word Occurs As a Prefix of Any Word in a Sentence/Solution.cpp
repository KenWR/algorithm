class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int index = (searchWord.front() != ' ');
        for (int i = 0; i < sentence.size(); ++i) {
            if (sentence[i] == ' ') {
                while (i < sentence.size() && sentence[i] == ' ') i += 1;
                index += 1;
            }
            if (sentence[i] == searchWord.front()) {
                if (!sentence.compare(i, searchWord.size(), searchWord)) return index;
            }
            else {
                while (i < sentence.size() && sentence[i] != ' ') i += 1;
                i -= 1;
            }
        }

        return -1;
    }
};