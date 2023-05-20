#ifndef DIARIO_CLASSE_H
#define DIARIO_CLASSE_H

class ExcecaoNotaSemestreInvalida {};

class ExcecaoNotaEspecialInvalida {};

class ExcecaoFrequenciaInvalida {};

class DiarioClasse {
    public:
        DiarioClasse();
        virtual ~DiarioClasse();
        
        bool determinarAprovacao(double notaSemestre, double notaEspecial, double frequencia);
};

#endif
