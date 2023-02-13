#include "TheClaw.h"
#include <iostream>

//essas são as alturas completas dos modelos, note que estão na origem, logo
//o que fica para cima é ALTURA/2
#define ALTURA_BASE 1.0
//#define ALTURA_ELO_BRACO 0.848
#define ALTURA_ELO_BRACO 0.828
//#define ALTURA_ELO_PUNHO 0.9119
#define ALTURA_ELO_PUNHO 1.1819
#define ALTURA_ELO_GARRA 0.2
#define ALTURA_ELO_BASEDEDO 0.24
#define ALTURA_JUNTA_MEIO_DEDO 0.2

//**Esses dois valores serão incluídos na contagem para determinação da posição do órgão terminal
//**somente pelo fato do modelo usado possuir uma inclinação na junta do meio do dedo que deve
//**ser levado em consideração, todas as outras juntas nao têm influência na contagem pois sua
//**altura é desconsiderada
#define ANGULO_JUNTA_MEIO_DEDO -20
#define TRANSLACAO_JUNTA_MEIO_DEDO 0.06

TheClaw::TheClaw() {
    this->anguloTorcionalJuntaBase = 0;
    this->anguloJuntaOmbro = -30;
    this->anguloJuntaCotovelo = -90;
    this->anguloJuntaGarra = 90;
    this->anguloJuntaBaseDedo = 45;
    this->anguloJuntaMeioDedo = -60;
    this->posBaseX = -2.0;
    this->posBaseY = 0;
    this->posBaseZ = 0;

//    this->anguloTorcionalJuntaBase = 0;
//    this->anguloJuntaOmbro = 0;
//    this->anguloJuntaCotovelo = 0;
//    this->anguloJuntaGarra = 0;
//    this->anguloJuntaBaseDedo = 0;
//    this->anguloJuntaMeioDedo = 0;

    this->matrix= new double[16];
    this->base = new Modelo(NULL,"c:/body/base.obj", Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(1,1,1));
    this->juntaOmbro = new Modelo(NULL,"c:/body/juntaOmbro.obj", Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(1,1,1));
    this->eloBraco = new Modelo(NULL,"c:/body/eloBraco.obj", Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(1,1,1));
    this->eloPunho = new Modelo(NULL,"c:/body/eloPunho.obj", Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(1,1,1));
    this->eloGarra = new Modelo(NULL,"c:/body/eloPontaDedos.obj", Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(1,1,1));
    this->juntaDedos = new Modelo(NULL,"c:/body/juntaDedos.obj", Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(1,1,1));
    this->eloBaseDedo = new Modelo(NULL,"c:/body/eloBaseDoDedo.obj", Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(1,1,1));
    this->juntaMeioDedo = new Modelo(NULL,"c:/body/juntaMeioDedos.obj", Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(1,1,1));
    this->eloPontaDedo = new Modelo(NULL,"c:/body/eloPontaDedos.obj", Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(1,1,1));
    //base = new Modelo(NULL,"C:/body/body/base.obj", Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(1,1,1));
    //    base = new Modelo(NULL,"c:/Robot Arm.obj", Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(1,1,1));
   // eloBraco = new Modelo(NULL,"C:/body/body/elo1.obj", Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(0,0,0),Ponto3D(1,1,1));
}

TheClaw::~TheClaw() {
    // TODO Auto-generated destructor stub
}
#include <math.h>



void TheClaw::DrawUnitCylinder(int NumSegs)  // x,y,z in [0,1], Y-axis is up
{
  int i;
  float *Px = new float[NumSegs];
  float *Py = new float[NumSegs];
  float AngIncr = (2.0f*3.1415927f) / (float)NumSegs;
  float Ang = AngIncr;
  Px[0]=1;
  Py[0]=0;
  for (i=1; i<NumSegs; i++, Ang+=AngIncr)
  {
    Px[i]=(float)cos(Ang);
    Py[i]=(float)sin(Ang);
  }

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
    glTranslatef(0.5f,0.5f,0.5f);
    glScalef(0.5f,0.5f,0.5f);

    // TOP
    glNormal3f(0,1,0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0,1,0);
    for (i=0; i<NumSegs; i++)
      glVertex3f(Px[i],1,-Py[i]);
    glVertex3f(Px[0],1,-Py[0]);
    glEnd();

    // BOTTOM
    glNormal3f(0,-1,0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0,-1,0);
    for (i=0; i<NumSegs; i++)
      glVertex3f(Px[i],-1,Py[i]);
    glVertex3f(Px[0],-1,Py[0]);
    glEnd();

    // SIDES
    glBegin(GL_QUAD_STRIP);
    for (i=0; i<NumSegs; i++)
    {
      glNormal3f(Px[i],0,-Py[i]);
      glVertex3f(Px[i],1,-Py[i]);
      glVertex3f(Px[i],-1,-Py[i]);
    }
    glNormal3f(Px[0],0,-Py[0]);
    glVertex3f(Px[0],1,-Py[0]);
    glVertex3f(Px[0],-1,-Py[0]);
    glEnd();

  glPopMatrix();

  delete[] Px;
  delete[] Py;
}
void TheClaw::DrawGroundPlane(int NumSegs)
{
  glColor3f(0.7f,0.7f,0.7f);
  glBegin(GL_QUADS);
    glNormal3f(0,1,0);
    glVertex3f(-2*5,0,1.8*5);
    glVertex3f(2*5,0,1.8*5);
    glVertex3f(2*5,0,-1.8*5);
    glVertex3f(-2*5,0,-1.8*5);
  glEnd();
}
void TheClaw::drawPlanoX() {
    glBegin(GL_QUADS);
    glNormal3f(0,1,0);
    glVertex3f(-1.4f,0,1.4f);
    glVertex3f(1.4f,0,1.4f);
    glVertex3f(1.4f,0,-1.4);
    glVertex3f(-1.4f,0,-1.4);
    glEnd();
}

void TheClaw::desenharJuntaCubo() {
    glPushMatrix();;
    glColor3f(0.0f,1.0f,1.0f);
            glTranslatef(0,-0.14,0);
            glScalef(0.1,0.1,0.1);
            glRotatef(180,0,0,1);
            drawPlanoX();
    glPopMatrix();

    glPushMatrix();
            glColor3f(1.0f,0.0f,0.0f);
            glScalef(0.1,0.1,0.1);
            glTranslatef(-1.4,0,0);
            glRotatef(90,0,0,1);
            drawPlanoX();
    glPopMatrix();

    glPushMatrix();
            glColor3f(0.0f,0.0f,1.0f);
            glScalef(0.1,0.1,0.1);
            glTranslatef(0,0,-1.4);
            glRotatef(-90,1,0,0);
            drawPlanoX();
    glPopMatrix();

    glPushMatrix();
            glColor3f(1.0f,1.0f,0.0f);
            glScalef(0.1,0.1,0.1);
            glTranslatef(1.4,0,0);
            glRotatef(-90,0,0,1);
            drawPlanoX();
    glPopMatrix();

    glPushMatrix();//topo
            glColor3f(1.0f,1.0f,1.0f);
            glScalef(0.1,0.1,0.1);
            glTranslatef(0,1.4f,0);
            drawPlanoX();
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.0f,1.0f,0.0f);
            glScalef(0.1,0.1,0.1);
            glTranslatef(0,0,1.4);
            glRotatef(90,1,0,0);
            drawPlanoX();
    glPopMatrix();



}

void TheClaw::desenharBase(){
    glPushMatrix();
        glRotatef(90,0,1,0);
        glScalef(0.65, 0.65, 0.65);
        this->base->desenhar();
    glPopMatrix();
//    glPushMatrix();
//        glColor3f(0.3,0.3,0.3);
//        glTranslatef(-0.25,0,-0.25);
//        glScalef(0.5f,0.06f,0.5);
//        DrawUnitCylinder(26);
//    glPopMatrix();
//    glPushMatrix();
//    glColor3f(0.3,0.3,0.3);
//        glTranslatef(-0.05,0.06,-0.05);
//        glScalef(0.1f,0.4,0.1f);
//        DrawUnitCylinder(16);
//    glPopMatrix();

}

void TheClaw::desenharJuntaOmbro() {
    glPushMatrix();
        glTranslatef(0,ALTURA_BASE/2,0);   //altura da base
        glScalef(0.65, 0.65, 0.65);
        glRotatef(90,0,1,0);
        this->juntaOmbro->desenhar();
    glPopMatrix();

//    glPushMatrix();
//        glTranslatef(0,0.06 + 0.4,0);   //altura da base + altura do elo (cilindro) da base
//        desenharJuntaCubo();
//    glPopMatrix();

}
void TheClaw::desenharBraco(){
    glPushMatrix();
        glRotatef(90,0,1,0);
        glTranslatef(0,ALTURA_ELO_BRACO/2,0);   //altura do ombro
        eloBraco->desenhar();
    glPopMatrix();
//    glPushMatrix();
//            glColor3f(0.5,0.3,0.3); //vermelho
//            glTranslatef(-0.05,0.14,-0.05);
//            glScalef(0.1f,0.4f,0.1f);
//            DrawUnitCylinder(16);
//    glPopMatrix();
}


void TheClaw::desenharJuntaCotovelo(){
//    glPushMatrix();
//        glTranslatef(0,0.28+0.4,0);   //altura da base + altura do elo (cilindro) da base
//        //pega matriz transformação atual
//        glGetDoublev( GL_MODELVIEW_MATRIX, &*matrix );

//        desenharJuntaCubo();

//    glPopMatrix();
}

void TheClaw::desenharPunho(){
    glPushMatrix();
        glScalef(1.4, 1.4, 1.4);
        glTranslatef(-0.03,ALTURA_ELO_PUNHO/2 - 0.26,0);   //altura do ombro

        glRotatef(90,0,1,0);
        glRotatef(-90,1,0,0);
        eloPunho->desenhar();
    glPopMatrix();

}

void TheClaw::desenharJuntaGarra(){
    glPushMatrix(); //neste momento o ponto esta no centro da junta anterior então soma o raio da junta + altura do elo + raio da nova junta (pois o modelo e a partir do centro) isto é: (0.14 + 0.4 + 0.14)
        glTranslatef(0,0.14 + 0.4 + 0.14,0);   //altura da base + altura do elo (cilindro) do punho
        desenharJuntaCubo();
    glPopMatrix();
}

void TheClaw::desenharGarra(){
    glPushMatrix();
        glRotatef(180,1,0,0);
        glTranslatef(-0.18,-0.41,0.2);
        eloGarra->desenhar();
    glPopMatrix();
}

void TheClaw::desenharJuntaDedos(){
    glPushMatrix(); //neste momento o ponto esta no centro da junta anterior então soma o raio da junta + altura do elo + raio da nova junta (pois o modelo e a partir do centro) isto é: (0.07 + 0.2 + 0.07)
     glTranslatef(0,ALTURA_ELO_GARRA,0);
     glRotatef(90,0,1,0);

    juntaDedos->desenhar();
    glPopMatrix();
}

void TheClaw::desenharBaseDedo(){
    glPushMatrix();
    glTranslatef(0,ALTURA_ELO_GARRA/2,0);
        glRotatef(90,0,1,0);
        eloBaseDedo->desenhar();
    glPopMatrix();
}
void TheClaw::desenharJuntaMeioDedo(int numDedo){

    glPushMatrix();
        glRotatef(90,0,1,0);
        glTranslatef((numDedo==2?TRANSLACAO_JUNTA_MEIO_DEDO:-TRANSLACAO_JUNTA_MEIO_DEDO),ALTURA_ELO_BASEDEDO,0);
        juntaMeioDedo->desenhar();

    glPopMatrix();
}
void TheClaw::desenharPontaDedo(){
    glPushMatrix();
        glRotatef(180,1,0,0);
        glRotatef(90,0,1,0);
        glTranslatef(-0.18,-0.4,0.2);
            eloPontaDedo->desenhar();
    glPopMatrix();
}

void TheClaw::desenhar() {
        glPushMatrix();
            DrawGroundPlane(16);
            //**Primeira hierarquia - Base + juntaOmbro
            glTranslatef(posBaseX,posBaseY,posBaseZ);

            desenharBase();         //altura de 0.06 + 0.4 (a base e o elo da base)

            glRotatef((double)anguloTorcionalJuntaBase,0,1,0);

            desenharJuntaOmbro();   //altura de 0.28
            //após desenhar a junta do ombro a caneta ainda está na altura da base (a altura
            //da junta ainda nao foi contabilizada, por isso basta transladar para a altura da junta)

            //**Segunda hierarquia - Braço + juntaCotovelo
            glTranslatef(0,ALTURA_BASE/2,0);   //altura da base
            glRotatef((double)anguloJuntaOmbro,0,0,1);   //dá a direção do braço

            desenharBraco();//vermelho
            desenharJuntaCotovelo();//vazio

            //**Terceira hierarquia - Punho + juntaDedos
            glTranslatef(0,ALTURA_ELO_BRACO,0);   //altura do ombro
            glRotatef((double)anguloJuntaCotovelo,0,0,1);  //dá a direção do punho (é como se fosse o ante-braço em humanos)

            desenharPunho();//azul
            //desenharJuntaGarra();

            //**Quarta hierarquia - elo da garra + juntaMão (que é um angulo so mas invertido para dedo oposto)
            glTranslatef(0,ALTURA_ELO_PUNHO - 0.12*2,0);   //altura do ombro
            glRotatef((double)anguloJuntaGarra,0,0,1);

            desenharGarra();    //elo da garra, ferro quebra munheca
            desenharJuntaDedos();

            //**Hierarquia 4.1 - elo primeiro dedo + junta do meio do dedo
                glPushMatrix();
                //**Hierarquia 4.1.1 - elo base do dedo + junta do meio do dedo
                    glTranslatef(0,ALTURA_ELO_GARRA,0); //altura da junta conta!
                    glRotatef(anguloJuntaBaseDedo,1,0,0);

                    desenharBaseDedo();
                    glRotatef(ANGULO_JUNTA_MEIO_DEDO,1,0,0);    //atenção aqui pois o angulo dessa junta conta!
                    desenharJuntaMeioDedo(1);

                    //**Hierarquia 4.1.2 - elo ponta do dedo
                    //**obs: na verdade nem precisava transladar os 0.035, aí o elo desenharia colado ao elo anterior, fazendo a junta apenas tapar a fresta pois nao ficaria buraco
                    // glTranslateALTURA_ELO_BASEDEDO + ALTURA_JUNTA_MEIO_DEDO ,0);
                    glTranslatef(0,ALTURA_ELO_BASEDEDO+ ALTURA_JUNTA_MEIO_DEDO/2,TRANSLACAO_JUNTA_MEIO_DEDO);
                    glRotatef(anguloJuntaMeioDedo,1,0,0);
                    // É TRANSLAÇÃO AQUI
                    desenharPontaDedo();

                glPopMatrix();

                //**Hierarquia 4.2 - elo primeiro dedo + junta do meio do dedo
                    glPushMatrix();
                    //**Hierarquia 4.2.1 - elo base do dedo + junta do meio do dedo
                        //glTranslatef(0.1 + 0.1,0,0);
                        glTranslatef(0,ALTURA_ELO_GARRA,0); //altura da junta conta!
                        glRotatef(-anguloJuntaBaseDedo,1,0,0);
                        //glRotatef(anguloBaseDedo,0,0,1);

                        desenharBaseDedo();
                       // glTranslatef(translX,ALTURA_ELO_BASEDEDO,0);
                        glRotatef(-ANGULO_JUNTA_MEIO_DEDO,1,0,0);    //atenção aqui pois o angulo dessa junta conta!
                        desenharJuntaMeioDedo(2);

                        //**Hierarquia 4.2.2 - elo ponta do dedo
                        //**obs: na verdade nem precisava transladar os 0.035, aí o elo desenharia colado ao elo anterior, fazendo a junta apenas tapar a fresta pois nao ficaria buraco
                        glTranslatef(0,ALTURA_ELO_BASEDEDO+ ALTURA_JUNTA_MEIO_DEDO/2,-TRANSLACAO_JUNTA_MEIO_DEDO);
                        glRotatef(-anguloJuntaMeioDedo,1,0,0);
                       // É TRANSLAÇÃO AQUI
                        desenharPontaDedo();

                    glPopMatrix();

        glPopMatrix();

}

