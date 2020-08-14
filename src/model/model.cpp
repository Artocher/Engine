#include "model.h"
#include "texture.h"
#include "mesh.h"
#include "shaderprogram.h"

#include <iostream>

Model::Model(QVector3D position, QVector3D scale, qreal rotationX, qreal rotationY, qreal rotationZ) : Object(position, scale, rotationX, rotationY, rotationZ){
    initializeOpenGLFunctions();
}

Model::~Model(){
    delete _texture;
    delete _shaderProgram;
    delete _mesh;
}

void Model::render(){
    updateModelMatrix();
    if(_shaderProgram->prepareToRender(_mesh, _texture, _modelMatrix))
	    glDrawArrays(_mesh->getDrawMode(), 0, _mesh->getMeshData()->numberOfVertices);   
}

void Model::updateModelMatrix(){
    _modelMatrix.setToIdentity();
    
    _modelMatrix.translate(getPosition().x(), getPosition().y(), getPosition().z());
    _modelMatrix.rotate(getRotationX(), QVector3D(1,0,0)); 
    _modelMatrix.rotate(getRotationY(), QVector3D(0,1,0));   
    _modelMatrix.rotate(getRotationZ(), QVector3D(0,0,1));

    _modelMatrix.scale(getScale().x(), getScale().y(), getScale().z());    
}

void Model::setTexture(Texture* texture){
    _texture = texture;
}

void Model::setMesh(Mesh* mesh){
    _mesh = mesh;
}

void Model::setShaderProgram(ShaderProgram* shaderProgram){
    _shaderProgram = shaderProgram;
}

void Model::setModelMatrix(QMatrix4x4 modelMatrix){
    _modelMatrix = modelMatrix;
}