#ifndef COORDENADA_H
#define COORDENADA_H

#include <vector>

class Coordenada {
    private:
        unsigned int row = 0;
        unsigned int column = 0;
    public:
        Coordenada();
        Coordenada(const unsigned int row, const unsigned int column);
        ~Coordenada();

        void getCoordenadasAdjacentes(std::vector<Coordenada>& adjacentes, const unsigned int rowBoundary, const unsigned int columnBoundary);

        void setRow(const unsigned int row);
        unsigned int getRow() const;

        void setColumn(const unsigned int column);
        unsigned int getColumn() const;
    
    private:
        bool estaNasConstricoes(const Coordenada& coordenada, const unsigned int rowBoundary, const unsigned int columnBoundary);
};

#endif
