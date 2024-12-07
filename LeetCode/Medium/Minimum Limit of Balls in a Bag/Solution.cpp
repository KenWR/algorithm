// Not Solved!
// Solved by parametric search

// 데이터상으로 존재하지 않는 공의 개수를 통해 최대 가방수가 나오면서 공의 개수가 최소인 이진 탐색법

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxBags) {
        int minimumBallNum = 1;
        int MaximumBallNum = 0;

        for (auto ballNum : nums) {
            MaximumBallNum = max(MaximumBallNum, ballNum);
        }

        while (minimumBallNum < MaximumBallNum) {
            // 이진탐색을 위한 중간 값 구하기 +1 여부는 상관없이 정확히 중간값이 나온다
            int middleBallNum = (minimumBallNum + MaximumBallNum) / 2;

            // 각 중간값이 가능한지 확인하고 불가능하지 않을시에 중간값을 최대값으로 설정
            if (isPossible(middleBallNum, nums, maxBags)) MaximumBallNum = middleBallNum;
            else minimumBallNum = middleBallNum + 1;
        }

        return minimumBallNum;
    }

    bool isPossible(int maxBallsInBag, vector<int>& nums, int maxBags) {
        int totalBags = 0;

        for (int num : nums) {
            // 공 개수를 중간값으로 나눔
            // -1을 하는 이유는 가방하나는 재사용이 가능하기 때문
            // 올림이라 최소 1이 나오고 이는 -1로 0이 됨
            int bags = ceil(num / (double)maxBallsInBag) - 1;
            totalBags += bags;
            // 계산한 가방 개수가 최대 가방 개수를 넘으면 불가능
            if (totalBags > maxBags) return false;
        }

        return true;
    }
};