#include "engine.h"

#include "baseshaderprogram.h"
#include "camera.h" 

Engine::Engine() : QOpenGLFunctions(){

}

Engine::~Engine(){
    delete _camera;
    delete _shaderProgram;
}

void Engine::setViewportWidth(int viewportWidth){
    _viewportWidth = viewportWidth;
}

void Engine::setViewportHeight(int viewportHeight){
    _viewportHeight = viewportHeight;
}
