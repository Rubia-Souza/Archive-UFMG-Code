#include "TiposVerbete.h"

TiposVerbete converterCharParaTiposVerbete(const char tipo) {
    switch(tipo) {
        case(TiposVerbete::NOME): {
            return TiposVerbete::NOME;
            break;
        }
        case(TiposVerbete::ADJETIVO): {
            return TiposVerbete::ADJETIVO;
            break;
        }
        case(TiposVerbete::VERBO): {
            return TiposVerbete::VERBO;
            break;
        }
    }
    
    return TiposVerbete::NOME;
}
