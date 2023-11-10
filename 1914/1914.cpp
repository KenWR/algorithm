#include <iostream>

void hanoi(int n, int from, int temp, int to) {
    if (n == 1) {
        printf ("%d %d\n", from, to);
        return;
    }
    hanoi(n - 1, from, to, temp);
    printf ("%d %d\n", from, to);
    hanoi(n - 1, temp, from, to);
}

int main() {
    long n;
    std::cin >> n;

    if (n > 20) {
        printf ((1 << n) - 1);
    } else {
        
        hanoi(n, 1, 2, 3);
    }

    return 0;
}