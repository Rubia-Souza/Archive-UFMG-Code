#include <string>
#include <math.h>
#include <iomanip>
#include <sstream>

#include "Ponto2D.hpp"

Ponto2D::Ponto2D() {
    set_x(0.0);
    set_y(0.0);
}

Ponto2D::Ponto2D(const double x, const double y) {
    set_x(x);
    set_y(y);
}

double Ponto2D::calcular_distancia(const Ponto2D& ponto) const {
    double distancia_horizontal = get_x() - ponto.get_x();
    double distancia_vertical = get_y() - ponto.get_y();

    return sqrt(pow(distancia_horizontal, 2) + pow(distancia_vertical, 2));
}

std::string Ponto2D::get_dados() const {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << "[" << get_x() << ", " << get_y() << "]";
    
    return stream.str();
}

void Ponto2D::set_x(const double x) {
    this->x = x;
    return;
}

double Ponto2D::get_x() const {
    return this->x;
}

void Ponto2D::set_y(const double y) {
    this->y = y;
    return;
}

double Ponto2D::get_y() const {
    return this->y;
}
