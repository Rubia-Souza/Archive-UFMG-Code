#ifndef FILE_H
#define FILE_H

#include <string>

#include "../ireadable/ireadable.hpp"

class File {
    public:
        virtual void readLine(const std::string& head, const std::string& line, IReadable& object) const = 0;
        virtual std::string write(const IReadable& object) const = 0;
};

#endif
