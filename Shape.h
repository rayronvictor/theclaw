#ifndef SHAPE_H
#define SHAPE_H

#include <QtOpenGL>
#include "Ponto3D.h"
class Shape
{
    public:
        //Shape(GLfloat posX,GLfloat posY,GLfloat velX,GLfloat velY,GLint anguloDesenho,GLfloat tamanhoEscalaX,GLfloat tamanhoEscalaY);
        Shape(Ponto3D pos, Ponto3D vel,Ponto3D angulo,Ponto3D escala);

        Ponto3D getPos();
        Ponto3D getVel();
        Ponto3D getAngulo();
        Ponto3D getEscala();
        void setPos(Ponto3D pos);
        void setVel(Ponto3D vel);
        void setAngulo(Ponto3D angulo);
        void setEscala(Ponto3D escala);

    private :
        Ponto3D pos,vel,angulo,escala;
};

#endif // SHAPE_H
