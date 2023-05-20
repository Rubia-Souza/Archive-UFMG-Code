#include "Celula.h"
#include "Registro.h"

Celula::Celula() {}
Celula::~Celula() {
    proxima = nullptr;
    anterior = nullptr;
    
    return;
}
