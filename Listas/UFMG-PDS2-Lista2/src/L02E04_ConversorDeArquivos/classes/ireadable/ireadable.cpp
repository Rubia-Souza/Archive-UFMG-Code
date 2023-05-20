#include <iostream>

#include "./ireadable.hpp"

std::ostream& operator <<(std::ostream& out, const IReadable& readable) {
    readable.print(out);
    return out;
}
