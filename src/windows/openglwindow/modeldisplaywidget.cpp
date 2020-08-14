#include "modeldisplaywidget.h"
#include "modeldisplayengine.h" 

ModelDisplayWidget::ModelDisplayWidget(QWidget* widget) : OpenGLWindow(widget){
    _engine = new ModelDisplayEngine(); 
    resize(100,100); 
    setFocusPolicy(Qt::StrongFocus); 
    startTimer(1000/200);
    setMaximumSize(100, 100);
} 

ModelDisplayWidget::~ModelDisplayWidget(){

}

void ModelDisplayWidget::keyPressEvent(QKeyEvent* event){
    
}

void ModelDisplayWidget::keyReleaseEvent(QKeyEvent* event){

}

void ModelDisplayWidget::mousePressEvent(QMouseEvent* event){

}

void ModelDisplayWidget::mouseMoveEvent(QMouseEvent* event){

}

void ModelDisplayWidget::timerEvent(QTimerEvent*){ 

}