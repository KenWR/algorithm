class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int size = nums.size();
        
        for (int i = 0; i < size; ++i) {
            if (nums[i] > nums[(i + 1) % size]) count++;
            if (count > 1) return false;
        }
        
        return true;
    }
};

// 매번 인덱스에서 정렬이 되어있는지 찾는 것 보다는 O(n^2)
// 가장 낮은 숫자부터 시작해서 정렬이 되어있는지를 확인하는것이 가장 빠를 것이라고 생각했다 O(2n)
// 하지만 중복된 숫자가 나올 수 있으므로 이는 올바른 풀이가 되지 못한다
// 그렇기에 조금더 간단하게 풀기로 했다

// 만약 배열이 정렬이 되어 있다면 
// 현재 원소가 다음 원소보다 클 경우가 최대 1번이므로 (배열이 rotate 되므로) 
// 이를 통해 배열이 정렬이 되어있는지 여부를 확인할 수 있을 것이다 O(n)