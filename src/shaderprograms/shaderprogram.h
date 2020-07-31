#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include "QOpenGLShaderProgram"

class Shader;

class ShaderProgram : public QOpenGLShaderProgram{
    public:
        ShaderProgram(Shader* vertexShader, Shader* fragmentShader, Shader* geometryShader = 0); 
        virtual void retrieveAttributesLocations() = 0;  
    private:
        Shader* _vertexShader;
        Shader* _fragmentShader;
        Shader* _geometryShader; 
};

#endif