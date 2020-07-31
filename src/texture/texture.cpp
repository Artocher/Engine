#include "texture.h"
#include "QString"

Texture::Texture(std::string filename, bool magnification, bool minification) : QOpenGLTexture(QImage(QString::fromStdString(filename)).mirrored()){
    if(magnification)
	    setMagnificationFilter(QOpenGLTexture::Linear);
    if(minification)
	    setMinificationFilter(QOpenGLTexture::Linear);
    setWrapMode(QOpenGLTexture::Repeat);
}
