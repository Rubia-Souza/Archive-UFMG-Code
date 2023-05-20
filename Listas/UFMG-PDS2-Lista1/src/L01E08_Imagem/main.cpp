#include <iostream>
#include <string>
#include <vector>

#include "./avaliacao_basica_imagem.hpp"
#include "./structs/Imagem/Imagem.hpp"

#define INICIALIZAR_IMAGEN 'i'
#define PREENCHER_IMAGEM 'p'
#define EXIBIR_IMAGEM 's'
#define TRANSFORMAR_TONS_CINZA 'g'
#define BINARIZAR 't'
#define AVALICAO_BASICA 'b'

void set_matriz_pixels(Imagem* imagem);

int main() {
    char input;
    Imagem* imagem = new Imagem();

    while(std::cin >> input) {
        switch(input) {
            case(INICIALIZAR_IMAGEN): {
                unsigned int height = 0, width = 0;
                std::cin >> width >> height;

                imagem->initialize_image(width, height);

                break;
            }
            case(PREENCHER_IMAGEM): {
                set_matriz_pixels(imagem);
                break;
            }
            case(EXIBIR_IMAGEM): {
                imagem->show();
                break;
            }
            case(TRANSFORMAR_TONS_CINZA): {
                imagem->to_grayscale();
                break;
            }
            case(BINARIZAR): {
                unsigned int limiar = 0;
                std::cin >> limiar;

                imagem->grayscale_thresholding(limiar);

                break;
            }
            case(AVALICAO_BASICA): {
                avaliacao_basica();
                break;
            }
        }
    }

    return 0;
}

void set_matriz_pixels(Imagem* imagem) {
    std::string cor_atual = "";

    for(unsigned int i = 0; i < imagem->get_height(); i++) {
        for(unsigned int j = 0; j < imagem->get_width(); j++) {
            std::cin >> cor_atual;
            imagem->fill(i, j, cor_atual);
        }
    }

    return;
}
