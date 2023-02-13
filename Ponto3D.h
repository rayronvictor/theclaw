#ifndef PONTO3D_H
#define PONTO3D_H
#include <QtOpenGL>
class Ponto3D
{
public:
    Ponto3D(GLfloat x, GLfloat y, GLfloat z);
    Ponto3D();

    GLfloat x;
    GLfloat y;
    GLfloat z;

    void setPonto(GLfloat x, GLfloat y, GLfloat z);
};

#endif // PONTO3D_H
