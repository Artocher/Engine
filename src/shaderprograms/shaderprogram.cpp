#include "shaderprogram.h"
#include <iostream>

#include "shader.h"

ShaderProgram::ShaderProgram(Shader* vertexShader, Shader* fragmentShader, Shader* geometryShader){
    if(!addShader(vertexShader)){ 
	    std::cout << "Vertex shader error" << std::endl; 
    }else{
        _vertexShader = vertexShader;
    }

    if(!addShader(fragmentShader)){ 
	    std::cout << "Fragment shader error" << std::endl;  
    }else{
        _fragmentShader = fragmentShader;  
    }

    if(geometryShader){
        if(!addShader(geometryShader)){
            std::cout << "Geometry shader error" << std::endl;
        }else{
            _geometryShader = geometryShader;
        }
    }

    if(!link())
	    std::cout << "Program link error" << std::endl; 

    if(!bind())
	    std::cout << "Program binding error" << std::endl;  
}