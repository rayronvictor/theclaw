#include "Ponto3D.h"

Ponto3D::Ponto3D(GLfloat x, GLfloat y, GLfloat z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Ponto3D::Ponto3D() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

void Ponto3D::setPonto(GLfloat x, GLfloat y, GLfloat z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
