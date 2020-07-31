#include "object.h"

Object::Object(QVector3D position, QVector3D scale, qreal rotation_x, qreal rotation_y, qreal rotation_z){
    _position = position;
    _rotation_x = rotation_x;
    _rotation_y = rotation_y; 
    _rotation_z = rotation_z;
    _scale = scale;
}

Object::~Object(){

}

Object::Object(){
    _position = QVector3D(0,0,0);
    _rotation_x = 0;
    _rotation_y = 0;
    _rotation_z = 0;
    _scale = QVector3D(1,1,1);  

}

void Object::setPosition(QVector3D position){
    _position = position;
}

void Object::setRotationX(qreal rotation_x){
    _rotation_x = rotation_x;
}

void Object::setRotationY(qreal rotation_y){
    _rotation_y = rotation_y;
}

void Object::setRotationZ(qreal rotation_z){
    _rotation_z = rotation_z;
}

void Object::setScale(QVector3D scale){
    _scale = scale;
}

QVector3D Object::getPosition(){
    return _position;
}

qreal Object::getRotationX(){
    return _rotation_x;
}

qreal Object::getRotationY(){
    return _rotation_y;
}

qreal Object::getRotationZ(){
    return _rotation_z;
}

QVector3D Object::getScale(){
    return _scale;
}
