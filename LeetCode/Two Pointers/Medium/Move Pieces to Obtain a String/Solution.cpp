class Solution {
public:
    bool canChange(string start, string target) {
        int len = start.size();
        int startIndex = 0, targetIndex = 0;

        while (startIndex < len || targetIndex < len) {
            while (startIndex < len && start[startIndex] == '_') {
                startIndex++;
            }
            while (targetIndex < len && target[targetIndex] == '_') {
                targetIndex++;
            }
            if (startIndex == len || targetIndex == len) {
                return startIndex == len && targetIndex == len;
            }

            if (start[startIndex] != target[targetIndex] ||
                (start[startIndex] == 'L' && startIndex < targetIndex) ||
                (start[startIndex] == 'R' && startIndex > targetIndex))
                return false;

            startIndex++;
            targetIndex++;
        }

        return true;
    }
};