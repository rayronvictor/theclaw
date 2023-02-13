#ifndef GAMETHECLAW_H
#define GAMETHECLAW_H
#include "TheClaw.h"
#include "Modelo.h"
#include "Alvo.h"
#include <iostream>
#include <list>
#include <Qt>
#include <QMouseEvent>

#define INC_ROT_CAM 2
#define INC_POS_CAM 0.1

class GameTheClaw
{
public:
    GameTheClaw();


    void tratarTeclas();
    void tratarMouseDragged(QMouseEvent *event);
    void tratarMousePressed(QMouseEvent *event);
    void tratarMouseReleased(QMouseEvent *event);

    void calcularLogica();
    void desenhar();

    Ponto3D getCoodTelaParaMundo(Ponto3D pontoTela);

    TheClaw* claw;
    std::list<Alvo> listaAlvos;
    std::list<Modelo> listaModelos;
    std::list<int> teclasPressionadas;

    bool teclaCima,teclaBaixo,teclaEsq,teclaDir;
    bool mousePressionado;
    float eyeX,eyeY,eyeZ;
    float centerX,centerY,centerZ;

    float anguloRotacaoCameraY,anguloRotacaoCameraX;

    Ponto3D pontoClique;
};

#endif // GAMETHECLAW_H
