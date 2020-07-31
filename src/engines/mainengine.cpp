#include "engine.h"

#include <iostream>

Engine::Engine() : AbstractEngine(){
    
}

Engine::~Engine(){

}

void Engine::init(){
    initializeOpenGLFunctions(); 
    initShaders();

    glClearColor(0.1, 0.1, 0.1, 1);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);

    glDisable(GL_CULL_FACE);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 

    initModels();  
}

void Engine::initModels(){

}

void Engine::render(){
    glClearColor(0.1, 0.1, 0.1, 1);
    
}

void Engine::initShaders(){

}

void Engine::sendDataToShader(){

}

void Engine::keyPress(QKeyEvent* event){
    _keys[event->key()] = true;
}

void Engine::keyRelease(QKeyEvent* event){
    _keys[event->key()] = false;
}

void Engine::mouseMove(QMouseEvent* event, QPoint offset){

}

void Engine::mousePress(QMouseEvent* event){

}