#include "openglwindow.h"

OpenGLWindow::OpenGLWindow(QWidget* widget) : QOpenGLWidget(widget){
    setMouseTracking (true);  
} 

OpenGLWindow::~OpenGLWindow(){
    makeCurrent();
    doneCurrent();
}

void OpenGLWindow::initializeGL(){ 
    _engine->init();
}

void OpenGLWindow::resizeGL(int w, int h){
    _engine->setViewportWidth(w);
    _engine->setViewportHeight(h);
}

void OpenGLWindow::paintGL(){
    _engine->render();
}

void OpenGLWindow::keyPressEvent(QKeyEvent* event){

}

void OpenGLWindow::keyReleaseEvent(QKeyEvent* event){
    
}

void OpenGLWindow::mousePressEvent(QMouseEvent* event){

}

void OpenGLWindow::mouseMoveEvent(QMouseEvent* event){

} 