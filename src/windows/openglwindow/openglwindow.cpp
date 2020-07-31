#include "openglwindow.h"

OpenGLWindow::OpenGLWindow(QWidget* widget) : QOpenGLWidget(widget){
    setMouseTracking (true);  
} 

OpenGLWindow::~OpenGLWindow(){
    makeCurrent();
    doneCurrent();
}

void OpenGLWindow::initializeGL(){ 

}

void OpenGLWindow::resizeGL(int w, int h){

}

void OpenGLWindow::paintGL(){

}

void OpenGLWindow::keyPressEvent(QKeyEvent* event){

}

void OpenGLWindow::keyReleaseEvent(QKeyEvent* event){

}

void OpenGLWindow::mousePressEvent(QMouseEvent* event){

}

void OpenGLWindow::mouseMoveEvent(QMouseEvent* event){

}