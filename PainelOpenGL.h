#ifndef PAINELOPENGL_H
#define PAINELOPENGL_H

#include <QGLWidget>
#include <iostream>
#include <QTimer>
#include <QtOpenGL/QtOpenGL>
#include "GameTheClaw.h"

#define LARGURA_MUNDO 60
#define ALTURA_MUNDO 40

class PainelOpenGL : public QGLWidget
{
    Q_OBJECT
public:
    explicit PainelOpenGL(QWidget *parent = 0);
        QTimer *timer;
        GameTheClaw *game;


        void initializeGL();
        void resizeGL(GLint width, GLint height);
        void paintGL();
        void keyPressEvent(QKeyEvent *event);
        void keyReleaseEvent(QKeyEvent *event);
        void mouseMoveEvent ( QMouseEvent * event );
        void mousePressEvent(QMouseEvent *event);
        void mouseReleaseEvent(QMouseEvent *event);

        void DrawUnitSphere(int NumSegs);  // x,y,z in [0,1]


signals:

public slots:

};

#endif // PAINELOPENGL_H
