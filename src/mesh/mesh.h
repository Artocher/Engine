#ifndef MESH_H
#define MESH_H

#include <QVector3D>
#include <QOpenGLBuffer> 

#include "meshdata.h" 

class Mesh{  
    public:
        Mesh(std::string filename);
        Mesh(const Mesh& mesh); 
        Mesh(Mesh&& mesh);
        virtual ~Mesh();

        MeshData* getMeshData();
        GLenum getDrawMode(); 

        QOpenGLBuffer getArrayBuffer();
        QOpenGLBuffer getIndexBuffer();

        void setDrawMode(GLenum drawMode);

        Mesh& operator=(const Mesh& other) noexcept;
        Mesh& operator=(Mesh&& other) noexcept; 

    protected:
        QOpenGLBuffer _arrayBuffer;
        QOpenGLBuffer _indexBuffer; 

        MeshData* _meshData; 
        GLenum _drawMode = GL_TRIANGLES;

    private:
        void getDataFromFile(std::string& filename);	 
        void initBuffers();
};

#endif
