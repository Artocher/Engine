#ifndef MESH_H
#define MESH_H

#include "QVector3D"
#include "QMatrix4x4"

#include "QOpenGLBuffer"

#include "meshdata.h" 

class Mesh{  
    public:
        Mesh(std::string filename);
        Mesh(const Mesh& mesh); 
        Mesh(Mesh&& mesh);
        virtual ~Mesh();

        QMatrix4x4 getModelMatrix();
        MeshData* getMeshData();
        GLenum getDrawMode(); 

        QOpenGLBuffer getArrayBuffer();
        QOpenGLBuffer getIndexBuffer();

        void setModelMatrix(QMatrix4x4& modelMatrix);
        void setDrawMode(GLenum drawMode);

        Mesh& operator=(const Mesh& other) noexcept;
        Mesh& operator=(Mesh&& other) noexcept; 

    protected:
        QOpenGLBuffer _arrayBuffer;
        QOpenGLBuffer _indexBuffer; 

        MeshData* _meshData;
        QMatrix4x4 _modelMatrix; 
        GLenum _drawMode;

    private:
        void getDataFromFile(std::string& filename);	 
        void initBuffers();
};

#endif
