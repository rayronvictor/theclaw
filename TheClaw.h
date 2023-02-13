#ifndef THECLAW_H
#define THECLAW_H

#include <QtOpenGL/QtOpenGL>
#include "Modelo.h"
class TheClaw {
    public:
        TheClaw();
        virtual ~TheClaw();

        GLdouble *matrix;

        int anguloTorcionalJuntaBase;
        int anguloJuntaOmbro;
        int anguloJuntaCotovelo;
        int anguloJuntaGarra;
        int anguloJuntaBaseDedo;
        int anguloJuntaMeioDedo;

        float posBaseX;
        float posBaseY;
        float posBaseZ;

        Modelo* base;

        Modelo* juntaOmbro;
        Modelo* eloBraco;
        Modelo* juntaCotovelo;
        Modelo* eloPunho;
        Modelo* juntaGarra;
        Modelo* eloGarra;
        Modelo* juntaDedos;
        Modelo* eloBaseDedo;
        Modelo* juntaMeioDedo;
        Modelo* eloPontaDedo;

        void drawPlanoX();
        void DrawUnitCylinder(int NumSegs);
        void DrawGroundPlane(int NumSegs);
        void desenharJuntaCubo();
        void desenhar();

        /*	void myDisplay();
        void redimensionar(int w, int h);
        void idle();
        void tratarMouse(int button, int state, int x, int y);
        void tratarMovimento(int x, int y);
        void tratarTecladoEspecial(int key, int x, int y)
        void tratarTeclaSolta(unsigned char Key, int x, int y);
        void tratarTeclaPressionada(unsigned char Key, int x, int y);*/
        void desenharBase();
        void desenharJuntaOmbro();
        void desenharBraco();
        void desenharJuntaCotovelo();
        void desenharPunho();
        void desenharJuntaGarra();
        void desenharGarra();
        void desenharJuntaDedos();
        void desenharBaseDedo();
        void desenharJuntaMeioDedo(int numDedo);
        void desenharPontaDedo();
        void drawSphere(double r, int lats, int longs);
};







#endif // THECLAW_H
