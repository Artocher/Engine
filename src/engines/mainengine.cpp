#include "mainengine.h"

#include <iostream>

MainEngine::MainEngine() : Engine(){
    
}

MainEngine::~MainEngine(){

}

void MainEngine::init(){
    initializeOpenGLFunctions(); 
    initShaders();

    glClearColor(0.1, 0.1, 0.1, 1);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);

    glDisable(GL_CULL_FACE);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 

    initModels();  
}

void MainEngine::initModels(){

}

void MainEngine::render(){
    glClearColor(0.2, 0.2, 0.2, 1);
    
}

void MainEngine::initShaders(){

}

void MainEngine::sendDataToShader(){

}

void MainEngine::keyPress(QKeyEvent* event){
    _keys[event->key()] = true;
}

void MainEngine::keyRelease(QKeyEvent* event){
    _keys[event->key()] = false;
}

void MainEngine::mouseMove(QMouseEvent* event, QPoint offset){
    
}

void MainEngine::mousePress(QMouseEvent* event){

}