#include "PainelOpenGL.h"

PainelOpenGL::PainelOpenGL(QWidget *parent) :
    QGLWidget(parent)
{
    setFormat(QGL::DoubleBuffer | QGL::DepthBuffer);


    //game = new GameCaveroids();
    game = new GameTheClaw();

    //configura o timer de redesenho de tela
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start(33);


    setFocus(); //para receber eventos de mouse e teclado

}

void PainelOpenGL::initializeGL()
{

    GLfloat LightAmbient[]=		{ 0.5f, 0.5f, 0.5f, 1.0f };
    GLfloat LightDiffuse[]=		{ 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat LightPosition[]=            { 0.0f, 0.0f, 2.0f, 1.0f };

    glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);		// Setup The Ambient Light
    glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);		// Setup The Diffuse Light
    glLightfv(GL_LIGHT1, GL_POSITION,LightPosition);	// Position The Light
    glEnable(GL_LIGHT1);								// Enable Light One

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_CULL_FACE);

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}

void PainelOpenGL::resizeGL(GLint w, GLint h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50,(float)w/h,0.1,10);
}

void PainelOpenGL::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    game->calcularLogica();
    game->desenhar();

    for (std::list<Modelo>::iterator it = game->listaModelos.begin(); it != game->listaModelos.end();it++) {
        (*it).desenhar();
//        if (!(*it).pmodel) {
//            string caminho = (*it).caminho;

//            (*it).pmodel = glmReadOBJ((char*)caminho.c_str());
//            if (!(*it).pmodel) exit(0);
//            glmUnitize((*it).pmodel);
//            glmFacetNormals((*it).pmodel);
//            glmVertexNormals((*it).pmodel, 90.0);
//        }
//        glmDraw((*it).pmodel, GLM_SMOOTH | GLM_MATERIAL);
    }

    GLfloat pos[4] = {1.f, -1.f, 0.f, 0.03f};

    glPushMatrix();
        glTranslatef(0.f, 3.f, 0.f);
        glColor3ub(255, 255, 255);

        glBegin(GL_LINE_STRIP);
            glVertex3f(0.0, 0.0, 0.0);
            if (pos[3] == 0) /* 10.0 = 'infinite' light */
                    glVertex3f(pos[0] * 10.0, pos[1] * 10.0, pos[2] * 10.0);
            else
                    glVertex3f(pos[0], pos[1], pos[2]);
        glEnd();

        glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glPopMatrix();
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void PainelOpenGL::keyReleaseEvent(QKeyEvent *event)
{
    game->teclasPressionadas.remove(event->key());

    if (event->key() == Qt::Key_Up){
        game->teclaCima = false;
    }
    if (event->key() == Qt::Key_Down){
        game->teclaBaixo = false;
    }
}

void PainelOpenGL::keyPressEvent(QKeyEvent *event)
{
    boolean contem = false;
    if (event->key() == Qt::Key_Up){
        game->teclaCima = true;
    }
    if (event->key() == Qt::Key_Down){
        game->teclaBaixo = true;
    }
    for (std::list<int>::iterator pt = game->teclasPressionadas.begin(); pt != game->teclasPressionadas.end();pt++){
        if ((*pt) == event->key()){
            contem = true;
            break;
        }
    }
    if (!contem) {
        game->teclasPressionadas.push_back(event->key());
    }
}

void PainelOpenGL::mouseMoveEvent(QMouseEvent *event)
{
    game->tratarMouseDragged(event);
    if (game->mousePressionado) {
    }
}

void PainelOpenGL::mousePressEvent(QMouseEvent *event)
{
    game->tratarMousePressed(event);
}

void PainelOpenGL::mouseReleaseEvent(QMouseEvent *event)
{
    game->tratarMouseReleased(event);
}


