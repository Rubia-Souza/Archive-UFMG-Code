#include <vector>

#include "./Coordenada.hpp"

Coordenada::Coordenada() {
    setRow(0);
    setColumn(0);
}

Coordenada::Coordenada(const unsigned int row, const unsigned int column) {
    setRow(row);
    setColumn(column);
}

Coordenada::~Coordenada() {
    setRow(0);
    setColumn(0);
}

void Coordenada::getCoordenadasAdjacentes(std::vector<Coordenada>& adjacentes, const unsigned int rowBoundary, const unsigned int columnBoundary) {
    Coordenada* posicao_adjacente = new Coordenada(getRow(), getColumn());

    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            if(i == 0 && j == 0) {
                continue;
            }

            posicao_adjacente->setRow(getRow() + i);
            posicao_adjacente->setColumn(getColumn() + j);

            if(estaNasConstricoes(*posicao_adjacente, rowBoundary, columnBoundary)) {
                adjacentes.push_back(*posicao_adjacente);
            }
        }
    }

    delete posicao_adjacente;
    return;
}

bool Coordenada::estaNasConstricoes(const Coordenada& coordenada, const unsigned int rowBoundary, const unsigned int columnBoundary) {
    bool isRowInRange = coordenada.getRow() < rowBoundary && coordenada.getRow() >= 0;
    bool isColumnInRange = coordenada.getColumn() < columnBoundary && coordenada.getColumn() >= 0;
    
    return  isRowInRange && isColumnInRange;
}

void Coordenada::setRow(const unsigned int row) {
    this->row = row;
    return;
}

unsigned int Coordenada::getRow() const {
    return row;
}

void Coordenada::setColumn(const unsigned int column) {
    this->column = column;
    return;
}

unsigned int Coordenada::getColumn() const {
    return column;
}
