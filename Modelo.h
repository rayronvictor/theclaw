#ifndef MODELO_H
#define MODELO_H
#include "glm.h"
#include <string>
#include "Shape.h"

using std::string;

class Modelo : Shape
{
    public:
        Modelo(GLMmodel* pmodel,string caminho,Ponto3D pos, Ponto3D vel,Ponto3D angulo,Ponto3D escala);


        string caminho;
        GLMmodel* pmodel;


        void desenhar();
};

#endif // MODELO_H
