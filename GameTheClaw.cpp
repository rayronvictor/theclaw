#include "GameTheClaw.h"

GameTheClaw::GameTheClaw() {
    claw = new TheClaw();
    teclaCima = false;
    teclaBaixo = false;
    teclaEsq = false;
    teclaDir = false;
    mousePressionado = false;
    eyeX = centerX = centerZ= 0;
    eyeY = 2;
    eyeZ = 4;
    centerY = 0.6;
    anguloRotacaoCameraY = anguloRotacaoCameraX = 0;
    std::list<Ponto3D> lis;
    lis.push_back(Ponto3D(-1.4f,0,1.4f));
    lis.push_back(Ponto3D(1.4f,0,1.4f));
    lis.push_back(Ponto3D(1.4f,0,-1.4));
    lis.push_back(Ponto3D(-1.4f,0,-1.4));

    float distX = -2.5;
    float inc = 0.9;

    //listaModelos.push_back(Modelo(NULL,"c:/body/base.obj", Ponto3D(distX+inc,0,distX+inc),Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(1,1,1)));
    //listaModelos.push_back(Modelo(NULL,"c:/body/juntaOmbro.obj", Ponto3D(distX+inc*2,0,distX+inc*2),Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(1,1,1)));
    //listaModelos.push_back(Modelo(NULL,"c:/body/eloBraco.obj", Ponto3D(distX+inc*3,0,distX+inc*3),Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(1,1,1)));
                                              //juntaCotovelo.obj
    //listaModelos.push_back(Modelo(NULL,"c:/body/eloPunho.obj", Ponto3D(distX+inc*4,0,distX+inc*4),Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(1,1,1)));
                                              //juntaGarra.obj
                                              //eloGarra.obj
    //listaModelos.push_back(Modelo(NULL,"c:/body/juntaDedos.obj", Ponto3D(distX+inc*5,0,distX+inc*5),Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(1,1,1)));
    listaModelos.push_back(Modelo(NULL,"c:/body/eloBaseDoDedo.obj", Ponto3D(distX+inc*6,0,distX+inc*6),Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(1,1,1)));
    listaModelos.push_back(Modelo(NULL,"c:/body/juntaMeioDedos.obj", Ponto3D(distX+inc*7,0,distX+inc*7),Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(1,1,1)));
    listaModelos.push_back(Modelo(NULL,"c:/body/eloPontaDedos.obj", Ponto3D(distX+inc*8,0,distX+inc*8),Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(1,1,1)));
//    listaModelos.push_back(Modelo(NULL,"D:/Travels/house/House 6.0/tutors-win32/tutors/data/al.obj", Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(1,1,1)));
//    listaModelos.push_back(Modelo(NULL,"D:/Travels/house/House 6.0/tutors-win32/tutors/data/dolphins.obj", Ponto3D(1,1,0),Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(1,1,1)));
//    listaModelos.push_back(Modelo(NULL,"D:/Travels/house/House 6.0/tutors-win32/tutors/data/porsche.obj", Ponto3D(-1,0,0),Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(1,1,1)));
//    listaModelos.push_back(Modelo(NULL,"D:/Travels/house/House 6.0/tutors-win32/tutors/data/flowers.obj", Ponto3D(1,1,1),Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(1,1,1)));

    //pmodel = new GLMmodel();
   // listaAlvos.push_back(Alvo(lis,0.0,0.0,0));
}

void GameTheClaw::tratarTeclas(){
    for (std::list<int>::iterator pt = teclasPressionadas.begin(); pt != teclasPressionadas.end();pt++) {
        int tecla = (*pt);

        if (tecla == Qt::Key_Left){
            anguloRotacaoCameraY -= INC_ROT_CAM;
        }
        else if (tecla == Qt::Key_Right){
            anguloRotacaoCameraY += INC_ROT_CAM;
        }
        else if (tecla == Qt::Key_Up){
            anguloRotacaoCameraX -= INC_ROT_CAM;
        }
        else if (tecla == Qt::Key_Down){
            anguloRotacaoCameraX += INC_ROT_CAM;
        }
        else if (tecla == Qt::Key_E)
            claw->anguloTorcionalJuntaBase-= 2;
        else if (tecla == Qt::Key_3)
            claw->anguloTorcionalJuntaBase+= 2;
        else if (tecla == Qt::Key_R)
            claw->anguloJuntaOmbro-= 2;
        else if (tecla == Qt::Key_4)
            claw->anguloJuntaOmbro+= 2;
        else if (tecla == Qt::Key_T)
            claw->anguloJuntaCotovelo-= 2;
        else if (tecla == Qt::Key_5)
            claw->anguloJuntaCotovelo+= 2;
        else if (tecla == Qt::Key_Y)
            claw->anguloJuntaGarra-= 2;
        else if (tecla == Qt::Key_6)
            claw->anguloJuntaGarra+= 2;
        else if (tecla == Qt::Key_U)
            claw->anguloJuntaBaseDedo+= 2;
        else if (tecla == Qt::Key_7)
            claw->anguloJuntaBaseDedo-= 2;
        else if (tecla == Qt::Key_I)
            claw->anguloJuntaMeioDedo+= 2;
        else if (tecla == Qt::Key_8)
            claw->anguloJuntaMeioDedo-= 2;
        else if (tecla == Qt::Key_A){
            //claw->posBaseX -= 0.05;
            eyeZ = eyeZ - (INC_POS_CAM * sin(anguloRotacaoCameraY * (M_PI/180)));
            centerZ = centerZ - (INC_POS_CAM * sin(anguloRotacaoCameraY * (M_PI/180)));

            eyeX = eyeX - (INC_POS_CAM * cos(anguloRotacaoCameraY * (M_PI/180)));
            centerX = centerX - (INC_POS_CAM * cos(anguloRotacaoCameraY * (M_PI/180)));

        }
        else if (tecla == Qt::Key_S){
            //claw->posBaseZ += INC_POS_CAM;
            eyeZ = eyeZ + (INC_POS_CAM * cos(anguloRotacaoCameraY * (M_PI/180)));
            centerZ = centerZ + (INC_POS_CAM * cos(anguloRotacaoCameraY * (M_PI/180)));

            eyeX = eyeX - (INC_POS_CAM * sin(anguloRotacaoCameraY * (M_PI/180)));
            centerX = centerX - (INC_POS_CAM * sin(anguloRotacaoCameraY * (M_PI/180)));

            eyeY = eyeY + (INC_POS_CAM * sin(anguloRotacaoCameraX * (M_PI/180)));
            centerY = centerY + (INC_POS_CAM * sin(anguloRotacaoCameraX * (M_PI/180)));
        }
        else if (tecla == Qt::Key_D){
            //claw->posBaseX += INC_POS_CAM;
            eyeZ = eyeZ + (INC_POS_CAM * sin(anguloRotacaoCameraY * (M_PI/180)));
            centerZ = centerZ + (INC_POS_CAM * sin(anguloRotacaoCameraY * (M_PI/180)));

            eyeX = eyeX + (INC_POS_CAM * cos(anguloRotacaoCameraY * (M_PI/180)));
            centerX = centerX + (INC_POS_CAM * cos(anguloRotacaoCameraY * (M_PI/180)));
        }
        else if (tecla == Qt::Key_W){
            //claw->posBaseZ -= INC_POS_CAM;
            eyeZ = eyeZ - (INC_POS_CAM * cos(anguloRotacaoCameraY * (M_PI/180)));
            centerZ = centerZ - (INC_POS_CAM * cos(anguloRotacaoCameraY * (M_PI/180)));

            eyeX = eyeX + (INC_POS_CAM * sin(anguloRotacaoCameraY * (M_PI/180)));
            centerX = centerX + (INC_POS_CAM * sin(anguloRotacaoCameraY * (M_PI/180)));

            eyeY = eyeY - (INC_POS_CAM * sin(anguloRotacaoCameraX * (M_PI/180)));
            centerY = centerY - (INC_POS_CAM * sin(anguloRotacaoCameraX * (M_PI/180)));
        }
    }

}

void GameTheClaw::calcularLogica()
{
    tratarTeclas();

    //detectar colisões
}
void GameTheClaw::desenhar() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyeX,eyeY,eyeZ,
              centerX,centerY,centerZ,
              0,1,0);

    glTranslatef(eyeX,eyeY,eyeZ);
    glRotatef(anguloRotacaoCameraX,1,0,0);
    glRotatef(anguloRotacaoCameraY,0,1,0);
    glTranslatef(-eyeX,-eyeY,-eyeZ);

//    glTranslatef(eyeX,eyeY,eyeZ);
//    glTranslatef(-eyeX,-eyeY,-eyeZ);

//    std::cout << "eyeX: " << eyeX << " eyeY: "<<eyeY << " eyeZ: "<<eyeZ << " centerX: "<<centerX << " centerY: "<<centerY<< " centerZ: " << centerZ << std::endl;
 //   std::cout << "anguloRotY: " << anguloRotacaoCameraY <<  "anguloRotX: " << anguloRotacaoCameraX << std::endl;
    claw->desenhar();




    for (std::list<Alvo>::iterator p = listaAlvos.begin(); p != listaAlvos.end();p++){
        (*p).desenhar();
    }
}


void GameTheClaw::tratarMousePressed(QMouseEvent *event)
{
    mousePressionado = true;
    pontoClique.setPonto(event->x(),event->y(),0);

}

void GameTheClaw::tratarMouseReleased(QMouseEvent *event)
{
    mousePressionado = false;
}

void GameTheClaw::tratarMouseDragged(QMouseEvent *event)
{
    Ponto3D coordMundo = getCoodTelaParaMundo(Ponto3D(event->x(),event->y(),0));

    std::cout << "mundo: (" << coordMundo.x << "," << coordMundo.y << "," << coordMundo.z << ")" << std::endl;

    std::cout << "matriz do ombro:" << std::endl;
    for (int i = 0; i < 16;i++){
        std::cout << claw->matrix[i] << " " <<  std::ends;
        if ((i+1)%4==0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "matriz do ombro no mundo:" << std::endl;


}

Ponto3D GameTheClaw::getCoodTelaParaMundo(Ponto3D pontoTela)
{
    GLint viewport[4];
    GLdouble modelview[16];
    GLdouble projection[16];
    GLfloat winX, winY, winZ;
    GLdouble posX, posY, posZ;

    glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
    glGetDoublev( GL_PROJECTION_MATRIX, projection );
    glGetIntegerv( GL_VIEWPORT, viewport );

    winX = (float)pontoTela.x;
    winY = (float)viewport[3] - (float)pontoClique.y;
    glReadPixels(pontoTela.x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ );

    gluUnProject( winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

    return Ponto3D(posX,posY,posZ);
}

















