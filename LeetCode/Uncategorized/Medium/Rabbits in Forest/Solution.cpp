class Solution {
public:
    int numRabbits(vector<int>& answers) {
        sort(answers.begin(), answers.end());
        int minimum_rabbits = 0;

        int prev = 0, count = 0, rabbit_num, rabbit_set;
        for (const auto &answer : answers) {
            if (prev == answer) {
                count++;
            }
            else {
                rabbit_num = prev + 1;
                rabbit_set = count / rabbit_num;
                if (count % rabbit_num) {
                    rabbit_set += 1;
                }
                minimum_rabbits += rabbit_set * rabbit_num;                
                prev = answer;
                count = 1;
            }
        }
        rabbit_num = prev + 1;
        rabbit_set = count / rabbit_num;
        if (count % rabbit_num) {
            rabbit_set += 1;
        }
        minimum_rabbits += rabbit_set * rabbit_num;

        return minimum_rabbits;
    }
};