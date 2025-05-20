// Math
class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a = nums[0], b = nums[1], c = nums[2];

        if (a + b > c && a + c > b && b + c > a) {
            if (a == b && a == c) {
                return "equilateral";
            }
            if (a == b || a == c || b == c) {
                return "isosceles";
            }
            else {
                return "scalene";
            }
        }
        return "none";
    }
};