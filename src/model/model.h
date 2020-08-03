#ifndef MODEL_H
#define MODEL_H

#include "object.h"
#include <QOpenGLFunctions> 

class Texture;
class Mesh;
class ShaderProgram;

class Model : public Object, protected QOpenGLFunctions{
    public:
        Model(QVector3D position = QVector3D(0,0,0), QVector3D scale = QVector3D(1,1,1), qreal rotationX = 0, qreal rotationY = 0, qreal rotationZ = 0);
        ~Model();
        void render();
        void setTexture(Texture* texture);
        void setMesh(Mesh* mesh);
        void setShaderProgram(ShaderProgram* shaderProgram);

    private:
        Texture* _texture;
        Mesh* _mesh;
        ShaderProgram* _shaderProgram;
};

#endif