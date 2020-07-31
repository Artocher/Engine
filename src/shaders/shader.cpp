#include "shader.h"

Shader::Shader(QOpenGLShader::ShaderType type, std::string sourceFileName) : QOpenGLShader(type){
    compileSourceFile(QString::fromStdString(sourceFileName));
    _sourceFileName = sourceFileName;
}