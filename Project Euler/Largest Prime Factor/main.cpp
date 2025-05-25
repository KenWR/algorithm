#include <iostream>
#include <list>
#include <iterator>
#include <cstdlib>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <n>\n";
        return 1;
    }

    long long number = std::strtoll(argv[1], nullptr, 10);
    long long prime_max;
    // 2로 인수분해
    while (number % 2 == 0) {
        prime_max = 2;
        number /= 2;
    }
    // 3으로 인수분해해
    while (number % 3 == 0) {
        prime_max = 3;
        number /= 3;
    }

    // 6k ± 1 소수 후보 검사
    for (long long i = 5; i * i <= number; i += 6) {
        // i = 6k − 1 (== 6k + 5)로 나눠질 때마다 분해
        while (number % i == 0) {
            prime_max = i;
            number /= i;
        }
        // i + 2 = 6k + 1 로 나눠질 때마다 분해
        while (number % (i + 2) == 0) {
            prime_max = i + 2;
            number /= i + 2;
        }
    }
    // 완전히 분해가 되지않았았으면 남은 숫자가 곧 가장 큰 소인수수
    if (number > 1) {
        prime_max = number;
    }

    std::cout << prime_max << '\n';
}
