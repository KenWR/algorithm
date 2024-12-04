class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string addedSpacesStr(s.size() + spaces.size(), ' ');

        int spacesIndex = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (spacesIndex < spaces.size() && i == spaces[spacesIndex]) spacesIndex += 1;
            addedSpacesStr[i + spacesIndex] = s[i];
        }

        return addedSpacesStr;
    }
};