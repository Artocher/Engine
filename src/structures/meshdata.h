#ifndef MESHDATA_H
#define MESHDATA_H

#include "vertexdescriptor.h"

#include <vector>

typedef struct{
    std::vector<VertexDescriptor> vertices;
    std::vector<int> indices; 
    int numberOfVertices; 
    double size;
}MeshData;

#endif
