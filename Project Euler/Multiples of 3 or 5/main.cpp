#include <iostream>

int main() {
    int multiple3_count = 999 / 3;
    int multiple5_count = 999 / 5;
    int multiple15_count = 999 / 15;

    int multiple3_sum = multiple3_count * (multiple3_count + 1) / 2 * 3;
    int multiple5_sum = multiple5_count * (multiple5_count + 1) / 2 * 5;
    int multiple15_sum = multiple15_count * (multiple15_count + 1) / 2 * 15;

    std::cout << multiple3_sum + multiple5_sum - multiple15_sum << '\n';
    return 0;
}