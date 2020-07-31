#ifndef SHADER_H
#define SHADER_H

#include "QOpenGLShader"

class Shader : public QOpenGLShader{
    public:
        Shader(QOpenGLShader::ShaderType type, std::string sourceFileName);
    private:
        std::string _sourceFileName; 
};

#endif