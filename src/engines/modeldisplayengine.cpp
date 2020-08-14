#include "modeldisplayengine.h"

#include <iostream>

#include "camera.h"
#include "baseshaderprogram.h"
#include "shader.h"
#include "model.h" 
#include "mesh.h"
#include "texture.h"

ModelDisplayEngine::ModelDisplayEngine() : Engine(){
    
}

ModelDisplayEngine::~ModelDisplayEngine(){

} 

void ModelDisplayEngine::init(){
    initializeOpenGLFunctions();    
    initShaders();

    glClearColor(1,1,1,1);

    _camera = new Camera(QVector3D(0, 12, 12), -30, -90, QVector3D(0,1,0)); 

    _camera->setFov(70); 
    _camera->setNearPlane(0.1);
    _camera->setFarPlane(300);     

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);

    glDisable(GL_CULL_FACE);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 

    initModels(); 
}

void ModelDisplayEngine::initModels(){
    Mesh* mesh = new Mesh("meshes/grid.obj");
    Mesh* mGrass = new Mesh("meshes/Grass_update.obj"); 

    Texture* texture = new Texture("textures/grassy_ground.jpg", true, true);
    Texture* tGrass = new Texture("textures/grass.png", true, true);

    Model* terrain = new Model();
    terrain->setTexture(texture); 
    terrain->setMesh(mesh);
    terrain->setShaderProgram(_shaderProgram);

    models.push_back(terrain);
}

void ModelDisplayEngine::render(){ 
    glClearColor(1, 1, 1, 1); 

    _camera->updateCameraPosition(_keys); 
    sendDataToShader();
    
    for(int i = 0; i < models.size(); i++){
        models[i]->render();
    }
}

void ModelDisplayEngine::initShaders(){
    Shader vertex(QOpenGLShader::Vertex, "shaders/BaseVertexShader.glsl");
    Shader fragment(QOpenGLShader::Fragment, "shaders/BaseFragmentShader.glsl");
    _shaderProgram = new BaseShaderProgram(&vertex, &fragment);
}

void ModelDisplayEngine::sendDataToShader(){
    _camera->updateViewMatrix();
    _shaderProgram->setUniformValue("viewMatrix", _camera->getViewMatrix());  

    _camera->updateProjectionMatrix(_viewportWidth, _viewportHeight); 
    _shaderProgram->setUniformValue("projectionMatrix", _camera->getProjectionMatrix()); 
}

void ModelDisplayEngine::keyPress(QKeyEvent* event){

}

void ModelDisplayEngine::keyRelease(QKeyEvent* event){

} 

void ModelDisplayEngine::mouseMove(QMouseEvent* event, QPoint offset){

}

void ModelDisplayEngine::mousePress(QMouseEvent* event){

}