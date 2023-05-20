#ifndef PIXEL_H
#define PIXEL_H

#include <string>
#include <vector>

class Pixel {
    private:
        int red;
        int green;
        int blue;
    
    public:
        Pixel();
        Pixel(const int red, const int green, const int blue);

        void print() const;

        void set_rgb(const std::string& cor);
        void set_rgb(const int red, const int green, const int blue);
        std::vector<int> get_rgb() const;

        void set_red(const int red);
        int get_red() const;

        void set_green(const int green);
        int get_green() const;

        void set_blue(const int blue);
        int get_blue() const;
    
        int get_tom_medio() const;
};

#endif
