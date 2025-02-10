// String

class Solution {
public:
    string clearDigits(string s) {
        string answer = "";

        for (const auto c : s) {
            if (isdigit(c)) answer.pop_back();
            else answer.push_back(c);
        }

        return answer;
    }
};

// String을 다루는 문제다
// 하지만 문제의 본질은 기본적으로 Stack에 더 가깝다
// 마치 괄호 "()" 가 제대로 닫히는지를 확인하는 것 처럼
// String을 순회하면서 Stack에 문자를 넣고 숫자가나오면 pop을 하면 된다
// 이 기능은 String의 push_back(), pop_back() 메소드로 동일하게 구현할 수 있다