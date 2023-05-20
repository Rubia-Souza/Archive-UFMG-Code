#ifndef PONTO2D_H
#define PONTO2D_H

#include <string>

struct Ponto2D {
    double x;
    double y;

    Ponto2D();
    Ponto2D(const double x, const double y);

    double calcular_distancia(const Ponto2D& ponto) const;
    std::string get_dados() const;

    void set_x(const double x);
    double get_x() const;

    void set_y(const double y);
    double get_y() const;
};

#endif