#include <iostream>
#include <string>
#include <vector>

#include "./Imagem.hpp"
#include "../Pixel/Pixel.hpp"

#define BRANCO 255
#define PRETO 0

Imagem::Imagem() {
    set_width(0);
    set_height(0);
}

Imagem::Imagem(const unsigned int width, const unsigned int height) {
    initialize_image(width, height);
}

void Imagem::initialize_image(const unsigned int width, const unsigned int height) {
    clear();

    set_width(width);
    set_height(height);

    for(unsigned int i = 0; i < get_height(); i++) {
        pixels.push_back(*(new std::vector<Pixel>{}));
        
        for(unsigned int j = 0; j < get_width(); j++) {
            pixels[i].push_back(*(new Pixel()));
        }
    }
    
    return;
}

void Imagem::clear() {
    for(unsigned int i = 0; i < pixels.size(); i++) {
        pixels[i].clear();
    }
    pixels.clear();

    return;
}

void Imagem::fill(const unsigned int linha, const unsigned int coluna, const std::string& pixel) {
    pixels[linha][coluna].set_rgb(pixel);

    return;
}

void Imagem::to_grayscale() {
    for(unsigned int i = 0; i < pixels.size(); i++) {
        for(unsigned int j = 0; j < pixels[i].size(); j++) {
            int tom_medio = pixels[i][j].get_tom_medio();
            pixels[i][j].set_rgb(tom_medio, tom_medio, tom_medio);
        }
    }
    
    return;
}

void Imagem::grayscale_thresholding(const unsigned int limiar) {
    for(unsigned int i = 0; i < pixels.size(); i++) {
        for(unsigned int j = 0; j < pixels[i].size(); j++) {
            if(pixels[i][j].get_tom_medio() > limiar) {
                pixels[i][j].set_rgb(BRANCO, BRANCO, BRANCO);
            }
            else {
                pixels[i][j].set_rgb(PRETO, PRETO, PRETO);
            }
        }
    }

    return;
}

void Imagem::show() const {
    for(unsigned int i = 0; i < pixels.size(); i++) {
        for(unsigned int j = 0; j < pixels[i].size(); j++) {
            pixels[i][j].print();
            
            if(j < pixels[i].size() - 1) {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
    
    return;
}

void Imagem::set_width(const unsigned int width) {
    this->width = width;
    return;
}

unsigned int Imagem::get_width() const {
    return width;
}

void Imagem::set_height(const unsigned int height) {
    this->height = height;
    return;
}

unsigned int Imagem::get_height() const {
    return height;
}

std::vector<std::vector<Pixel>> Imagem::get_pixels() const {
    return pixels;
}
