#include "Modelo.h"
#include <iostream>
Modelo::Modelo(GLMmodel* pmodel,string caminho,Ponto3D pos, Ponto3D vel,Ponto3D angulo,Ponto3D escala):
    Shape (pos,vel,angulo,escala) {
    this->pmodel = pmodel;
    this->caminho = caminho;
}

void Modelo::desenhar()
{
    if (!pmodel) {
        pmodel = glmReadOBJ((char*)this->caminho.c_str());
        if (!pmodel) exit(0);
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel, 90.0);
    }

    glPushMatrix();
        glTranslatef(getPos().x,getPos().y,getPos().z);
        glScalef(getEscala().x,getEscala().y,getEscala().z);
        glRotatef(getAngulo().x,1,0,0);
        glRotatef(getAngulo().y,0,1,0);
        glRotatef(getAngulo().z,0,0,1);
        glColor3f(0.55,0.55,0.0);
        //glmDraw(pmodel, GLM_SMOOTH );
        glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL);
    glPopMatrix();
}


