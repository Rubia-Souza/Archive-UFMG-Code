#ifndef CSV_H
#define CSV_H

#include <string>
#include <vector>

#include "../file/file.hpp"
#include "../ireadable/ireadable.hpp"

class CSV : public File {
    public:
        CSV();
        ~CSV();

        std::string concat(const std::vector<std::string>& reference) const;
        void split(const std::string& reference, std::vector<std::string>& splitedString) const;
        
        std::string getHeader(const IReadable& object) const;

        virtual void readLine(const std::string& head, const std::string& line, IReadable& object) const override;
        virtual std::string write(const IReadable& object) const override;
};

#endif
