#include "Shape.h"
#include<iostream>
Shape::Shape(Ponto3D pos, Ponto3D vel,Ponto3D angulo,Ponto3D escala)
{
    this->pos = pos;
    this->vel = vel;
    this->angulo = angulo;
    this->escala = escala;
}


Ponto3D Shape::getPos()
{
    return pos;
}

Ponto3D Shape::getVel()
{
    return vel;
}

Ponto3D Shape::getAngulo()
{
    return angulo;
}

Ponto3D Shape::getEscala()
{
    return escala;
}

void Shape::setPos(Ponto3D pos)
{
    this->pos = pos;
}

void Shape::setVel(Ponto3D vel)
{
    this->vel = vel;
}

void Shape::setAngulo(Ponto3D angulo)
{
    this->angulo = angulo;
}

void Shape::setEscala(Ponto3D escala)
{
    this->escala = escala;
}
