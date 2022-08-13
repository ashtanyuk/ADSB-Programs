// Copyright 2022

#include <iostream>

void hanoi(char from, char to, char other, int n) {
    if(n > 0) {
        hanoi(from, other, to, n - 1);
        std::cout << from << " -> " << to << std::endl;
        hanoi(other, to, from, n - 1);
    }
}
int main() {
    int number = 5;
    hanoi('A', 'C', 'B', number);
    return 0;
}
