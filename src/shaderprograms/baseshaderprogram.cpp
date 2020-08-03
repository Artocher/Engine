#include "baseshaderprogram.h"

#include "mesh.h"
#include "texture.h"

BaseShaderProgram::BaseShaderProgram(Shader* vertexShader, Shader* fragmentShader, Shader* geometryShader) : ShaderProgram(vertexShader, fragmentShader, geometryShader){
    retrieveAttributesLocations();
} 
 
void BaseShaderProgram::retrieveAttributesLocations(){
    _vertexLocation = attributeLocation("position");
    _textureCoordinateLocation = attributeLocation("textureCoordinate");      
}

bool BaseShaderProgram::prepareToRender(Mesh* mesh, Texture* texture, QMatrix4x4 modelMatrix){
    if(mesh == nullptr || texture == nullptr)
        return false;
    texture->bind();
    setUniformValue("texture",0);

    mesh->getArrayBuffer().bind();
    mesh->getIndexBuffer().bind();

    quintptr offset = 0;

    enableAttributeArray(_vertexLocation);
    setAttributeBuffer(_vertexLocation, GL_FLOAT, int(offset), 3, sizeof(VertexDescriptor));

    offset += sizeof(QVector3D); 

    enableAttributeArray(_textureCoordinateLocation);
    setAttributeBuffer(_textureCoordinateLocation, GL_FLOAT, int(offset), 2, sizeof(VertexDescriptor));

    setUniformValue("modelMatrix", modelMatrix);

    return true;
}

int BaseShaderProgram::getVertexLocation(){
    return _vertexLocation;
}

int BaseShaderProgram::getTextureCoordinateLocation(){
    return _textureCoordinateLocation;
} 