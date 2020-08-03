#ifndef BASESHADERPROGRAM_H
#define BASESHADERPROGRAM_H

#include "shaderprogram.h"

class Texture;
class Mesh;

class BaseShaderProgram : public ShaderProgram{
    public:
        BaseShaderProgram(Shader* vertexShader, Shader* fragmentShader, Shader* geometryShader = 0);
        void retrieveAttributesLocations();
        bool prepareToRender(Mesh* mesh, Texture* texture);

        int getVertexLocation();
        int getTextureCoordinateLocation();
    private:
        int _vertexLocation;
        int _textureCoordinateLocation;
};

#endif