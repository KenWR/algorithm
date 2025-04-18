class Solution {
public:
    string countAndSay(int n) {
        string answer = "1";

        while(--n) {
            int count = 0; 
            char prev = answer.front();
            string next_answer = "";

            for (int i = 0; i < answer.size(); ++i) {
                if (answer[i] == prev) {
                    count++;
                }
                else if (answer[i] != prev) {
                    next_answer += to_string(count);
                    next_answer += prev;
                    count = 1;
                    prev = answer[i];
                }
                if (i == answer.size() - 1) {
                    next_answer += to_string(count);
                    next_answer += prev;
                }
            }
            if (next_answer.empty() == false) {
                answer.swap(next_answer);
            }
        }

        return answer;
    }
};