#include <iostream>
#include <vector>
#include <string>

#include "./Pixel.hpp"

std::vector<int> get_cor_de_string(const std::string& cor);
std::vector<std::string> formatar_cores(const int red, const int green, const int blue);

Pixel::Pixel() {
    set_rgb(0, 0, 0);
}

Pixel::Pixel(const int red, const int green, const int blue) {
    set_rgb(red, blue, green);
}

void Pixel::print() const {
    std::vector<std::string> cores = formatar_cores(get_red(), get_green(), get_blue());

    std::cout << cores[0] << cores[1] << cores[2];

    return;
}

std::vector<std::string> formatar_cores(const int red, const int green, const int blue) {
    std::vector<std::string> cores;
    cores.push_back(std::to_string(red));
    cores.push_back(std::to_string(green));
    cores.push_back(std::to_string(blue));

    std::string cores_formatadas = "";

    for(unsigned int i = 0; i < cores.size(); i++) {
        if(cores[i].size() == 1) {
            cores[i].insert(0, "00");
        }
        else if(cores[i].size() == 2) {
            cores[i].insert(0, "0");
        }
    }

    return cores;
}

void Pixel::set_rgb(const std::string& cor) {
    std::vector<int> valores = get_cor_de_string(cor);
    set_rgb(valores[0], valores[1], valores[2]);

    return;
}

std::vector<int> get_cor_de_string(const std::string& cor) {
    std::vector<int> cor_rgb_separada;
    std::string cor_atual = "";
    
    unsigned int i = 0;
    for(char character : cor) {
        cor_atual.push_back(character);
        i++;
        
        if(i % 3 == 0) {
            cor_rgb_separada.push_back(std::stoul(cor_atual));
            cor_atual.clear();
        }
    }
    
    return cor_rgb_separada;
}

void Pixel::set_rgb(const int red, const int green, const int blue) {
    set_red(red);
    set_blue(blue);
    set_green(green);

    return;
}

std::vector<int> Pixel::get_rgb() const {
    std::vector<int> cores;

    cores.push_back(get_red());
    cores.push_back(get_green());
    cores.push_back(get_blue());

    return cores;
}

int Pixel::get_tom_medio() const {
    return (red + blue + green) / 3;
}

void Pixel::set_red(const int red) {
    this->red = red;
    return;
}

int Pixel::get_red() const {
    return red;
}

void Pixel::set_green(const int green) {
    this->green = green;
    return;
}

int Pixel::get_green() const {
    return green;
}

void Pixel::set_blue(const int blue) {
    this->blue = blue;
    return;
}

int Pixel::get_blue() const {
    return blue;
}
