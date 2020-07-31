#ifndef OBJECT_FILE_PARSER_H
#define OBJECT_FILE_PARSER_H

#include <string> 
#include "meshdata.h"

class ObjectFileParser{
    public:
	    ObjectFileParser() = default;
	    ~ObjectFileParser();
 
	    static MeshData* parse(const std::string filename); 
};

#endif
