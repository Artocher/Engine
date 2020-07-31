#include "baseshaderprogram.h"

BaseShaderProgram::BaseShaderProgram(Shader* vertexShader, Shader* fragmentShader, Shader* geometryShader) : ShaderProgram(vertexShader, fragmentShader, geometryShader){
    retrieveAttributesLocations();
} 
 
void BaseShaderProgram::retrieveAttributesLocations(){
    _vertexLocation = attributeLocation("position");
    _textureCoordinateLocation = attributeLocation("textureCoordinate");      
}

int BaseShaderProgram::getVertexLocation(){
    return _vertexLocation;
}

int BaseShaderProgram::getTextureCoordinateLocation(){
    return _textureCoordinateLocation;
} 