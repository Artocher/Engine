
#include "object_file_parser.h"

#include <iostream>
#include <fstream>
#include "QVector3D"
#include "QVector2D"
#include <vector>

MeshData* ObjectFileParser::parse(std::string filename){
	std::ifstream file(filename ,std::ios::in);

	std::string prefix;
	float x;
	float y;
	float z;
    
	std::vector<QVector3D> positions;
	std::vector<QVector2D> textures;
	std::vector<QVector3D> normals;

	MeshData* meshData = new MeshData();

	while(file){
		file >> prefix;
		if(prefix == "v"){	    
			file >> x >> y >> z;
			positions.push_back(QVector3D(x, y, z));
		}else if(prefix == "vt"){
			file >> x >> y;
			textures.push_back(QVector2D(x, y));
		}else if(prefix == "vn"){
			file >> x >> y >> z;
			normals.push_back(QVector3D(x,y,z));
		}else if(prefix == "f"){
			for(int i=0; i<3; i++){
				file >> x >> y >> z;
				meshData->vertices.push_back({positions[x-1],
						    textures[y-1],
						    normals[z-1]});
			} 
		}
		prefix = "";
	} 

	meshData->numberOfVertices = meshData->vertices.size(); 

	for(int i = 0; i < meshData->numberOfVertices; i++)
		meshData->indices.push_back(i+1);  

	file.close();
	return meshData;
}