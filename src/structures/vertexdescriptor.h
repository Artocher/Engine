#ifndef VERTEXDESCRIPTOR_H
#define VERTEXDESCRIPTOR_H

#include <QVector3D>
#include <QVector2D>

struct VertexDescriptor{
    QVector3D position; 
    QVector2D textureCoordinates;
    QVector3D normals;
    QVector3D color; 
}; 

#endif
