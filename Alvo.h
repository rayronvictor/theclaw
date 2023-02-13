#ifndef ALVO_H
#define ALVO_H

#include <list>
#include <Ponto3D.h>
#include <QtOpenGL/QtOpenGL>

#define X .525731112119133606
#define Z .850650808352039932

class Alvo
{
public:
    Alvo(std::list<Ponto3D> listaPontos,float x, float y, float z);

    std::list<Ponto3D> listaPontos;

    Ponto3D pos;

    bool agarrado;

    void drawtri(GLfloat *a, GLfloat *b, GLfloat *c, int div, float r);
    void normalize(GLfloat *a);
    void drawsphere(int ndiv, float radius =1.0);
    void desenhar();
};

#endif // ALVO_H
