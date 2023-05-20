#ifndef IREADABLE_H
#define IREADABLE_H

#include <iostream>
#include <vector>
#include <string>

class IReadable {
    public:
        virtual void GetCampos(std::vector<std::string>& out) const = 0;
        
        virtual void setAtributo(const std::string key, const std::string valor) = 0;
        virtual std::string GetAtributo(std::string key) const = 0;
    
        friend std::ostream& operator <<(std::ostream& out, const IReadable& readable);

    protected:
        virtual void print(std::ostream& out) const = 0;
};


#endif
