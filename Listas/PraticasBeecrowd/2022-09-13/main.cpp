#include <iostream>

int main() {
    unsigned int size = 0;
    int balls[64];

    std::cin >> size;
    for(unsigned int i = 0; i < size; i++) {
        std::cin >> balls[i];
    }

    while(size > 1) {
        for(unsigned int i = 0, j = 1; j < size; i++, j++) {
            if(balls[i] == balls[j]) {
                balls[i] = 1;
            }
            else {
                balls[i] = -1;
            }
        }

        size--;
    }

    if(balls[0] == 1) {
        std::cout << "preta\n";
    }
    else {
        std::cout << "branca\n";
    }

    return 0;
}
