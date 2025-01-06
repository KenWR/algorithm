// Prefix Sum

// 각 박스(boxes[i])에서 공(ball)을 옮기는 최소 연산 횟수를 계산
// 1. 초기화 단계:
//    - 오른쪽(rightBallsNum): 초기에는 모든 공의 개수
//    - 오른쪽 연산(rightOperation): 초기에는 모든 공을 0번 위치로 옮기는 데 필요한 작업 수
// 2. 순회하며 계산:
//    - 현재 박스에서 왼쪽 공의 연산(leftOperation)과 오른쪽 공의 연산(rightOperation)을 합산하여 최소 연산 횟수를 기록
//    - 박스를 순회하며 현재 박스에 따라 오른쪽 공의 개수를 줄이고(leftBallsNum 증가, rightBallsNum 감소), 연산 수를 갱신


class Solution {
public:
    vector<int> minOperations(string boxes) {
        int leftBallsNum = 0, rightBallsNum = 0;
        int leftOperation = 0, rightOperation = 0;
        vector<int> operations(boxes.size(), 0);

        // 
        for (int i = 0; i < boxes.size(); i++) {
            if (boxes[i] == '1') {
                rightBallsNum++;
                rightOperation += i;
            }
        }

        for (int i = 0; i < boxes.size(); i++) {
            operations[i] = leftOperation + rightOperation;
            if (boxes[i] == '1') {
                rightBallsNum--;
                leftBallsNum++;
            }
            leftOperation += leftBallsNum;
            rightOperation -= rightBallsNum;
        }

        return operations;
    }
};