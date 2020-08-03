#include "model.h"
#include "texture.h"
#include "mesh.h"
#include "shaderprogram.h"

Model::Model(QVector3D position, QVector3D scale, qreal rotationX, qreal rotationY, qreal rotationZ) : Object(position, scale, rotationX, rotationY, rotationZ){
    initializeOpenGLFunctions();
}

Model::~Model(){
    delete _texture;
    delete _shaderProgram;
    delete _mesh;
}

void Model::render(){
    if(_shaderProgram->prepareToRender(_mesh, _texture))
	    glDrawArrays(_mesh->getDrawMode(), 0, _mesh->getMeshData()->numberOfVertices);   
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