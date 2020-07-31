#include "engine.h"

Engine::Engine() : QOpenGLFunctions(){

}

Engine::~Engine(){

}

void Engine::setViewportWidth(int viewportWidth){
    _viewportWidth = viewportWidth;
}

void Engine::setViewportHeight(int viewportHeight){
    _viewportHeight = viewportHeight;
}
