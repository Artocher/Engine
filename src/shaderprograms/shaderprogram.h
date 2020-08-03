#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <QOpenGLShaderProgram> 
#include <QMatrix4x4>

class Shader;
class Texture;
class Mesh;



class ShaderProgram : public QOpenGLShaderProgram{
    public:
        ShaderProgram(Shader* vertexShader, Shader* fragmentShader, Shader* geometryShader = 0); 
        virtual void retrieveAttributesLocations() = 0;  
        virtual bool prepareToRender(Mesh* mesh, Texture* texture, QMatrix4x4 modelMatrix) = 0;
    private:
        Shader* _vertexShader;
        Shader* _fragmentShader;
        Shader* _geometryShader; 
};

#endif