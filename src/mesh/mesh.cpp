#include "mesh.h"
#include "object_file_parser.h"

Mesh::Mesh(std::string filename) : _indexBuffer(QOpenGLBuffer::IndexBuffer){
	
	getDataFromFile(filename);

	_arrayBuffer.create();
	_indexBuffer.create();
	
	initBuffers();
}

Mesh::~Mesh(){
	_arrayBuffer.destroy();
	_indexBuffer.destroy();
	delete _meshData;
}

Mesh::Mesh(const Mesh& mesh) = default;

Mesh::Mesh(Mesh&& mesh) = default;

void Mesh::initBuffers(){
	_arrayBuffer.bind();
	_arrayBuffer.allocate(&_meshData->vertices.front(), _meshData->numberOfVertices * sizeof(VertexDescriptor));
	
	_indexBuffer.bind(); 
	_indexBuffer.allocate(&_meshData->indices.front(), _meshData->numberOfVertices * sizeof(int)); 
}

void Mesh::getDataFromFile(std::string& filename){
    _meshData = ObjectFileParser::parse(filename);
}

MeshData* Mesh::getMeshData(){
    return _meshData;
}

GLenum Mesh::getDrawMode(){
    return _drawMode;
}

QOpenGLBuffer Mesh::getArrayBuffer(){
    return _arrayBuffer;
}

QOpenGLBuffer Mesh::getIndexBuffer(){
    return _indexBuffer;
}

void Mesh::setDrawMode(GLenum drawMode){
    _drawMode = drawMode;
}

QMatrix4x4 Mesh::getModelMatrix(){
    return _modelMatrix;
}

void Mesh::setModelMatrix(QMatrix4x4& modelMatrix){
    _modelMatrix = modelMatrix;
}
