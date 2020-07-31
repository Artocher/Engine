#ifndef TEXTURE_H
#define TEXTURE_H

#include "QOpenGLTexture"
#include <string>

class Texture : public QOpenGLTexture{
public:
    Texture(std::string filename, bool magnification, bool minification);
};

#endif