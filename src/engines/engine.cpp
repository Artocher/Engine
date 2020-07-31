#include "engine.h"

AbstractEngine::AbstractEngine() : QOpenGLFunctions(){

}

AbstractEngine::~AbstractEngine(){

}

void AbstractEngine::setViewportWidth(int viewportWidth){
    _viewportWidth = viewportWidth;
}

void AbstractEngine::setViewportHeight(int viewportHeight){
    _viewportHeight = viewportHeight;
}
