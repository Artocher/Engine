#include "camera.h"

#include <QKeyEvent>  
#include <cmath> 

Camera::Camera(QVector3D position, double pitch, double yaw, QVector3D axis){
    viewMatrix.setToIdentity();
    projectionMatrix.setToIdentity();
    this->position = position;
    this->axis = axis;

    right = QVector3D(0,0,0); 
    worldUp = axis;

    this->pitch = pitch;  
    this->yaw = yaw;  

    maxPitch = 80;
    minPitch = 80;

    updateCameraProperties();
}

void Camera::setPosition(QVector3D position){
    this->position = position;
}

void Camera::move(Direction direction){
     switch (direction){
    case FORWARD:
        position += look * 0.5f;
        break;
    case BACKWARD:
        position -= look * 0.5f;
        break;
    case LEFT:
        position -= right * 0.5f;
        break;
    case RIGHT:
        position += right * 0.5f;
        break;
    case UPWARD:
        position += axis * 0.5f;
        break;
    case DOWNWARD:
        position -= axis * 0.5f;
    }
}

const QMatrix4x4 Camera::getViewMatrix(){
    return viewMatrix;
}

const QMatrix4x4 Camera::getProjectionMatrix(){
    return projectionMatrix;
}

void Camera::setProjectionMatrix(QMatrix4x4 projectionMatrix){
    this->projectionMatrix = projectionMatrix; 
}

const QVector3D Camera::getPosition(){
    return position;
}

const QVector3D Camera::getAxis(){
    return axis;
}

const QVector3D Camera::getLook(){
    return look;
}

void Camera::updateViewMatrix(){
    updateCameraProperties();
    viewMatrix.setToIdentity();
    viewMatrix.lookAt(position, position + look, axis);
}

void Camera::updateProjectionMatrix(int viewportWidth, int viewportHeight){
    projectionMatrix.setToIdentity();  
    projectionMatrix.perspective(fov, (float) viewportWidth/viewportHeight, nearPlane, farPlane);   
}

void Camera::updateCameraRotation(const float& offsetX, const float& offsetY){
    pitch += double(offsetY/15);
    yaw += double(offsetX/15);   

    if(pitch > maxPitch)
        pitch = maxPitch;
    else if(pitch < - minPitch) 
        pitch = - minPitch; 
}

void Camera::updateCameraPosition(QMap<int, bool> keys){ 
    if(keys[Qt::Key_Z])
        move(FORWARD);
    if(keys[Qt::Key_S])
        move(BACKWARD);
    if(keys[Qt::Key_Q])
        move(LEFT);
    if(keys[Qt::Key_D])
        move(RIGHT);
    if(keys[Qt::Key_K])
        move(UPWARD);
    if(keys[Qt::Key_J])
        move(DOWNWARD);
}

void Camera::updateCameraProperties(){
    look.setX(float(cos(yaw * M_PI/180)) * float(cos(pitch * M_PI/180)));
    look.setY(float(sin(pitch * M_PI/180)));
    look.setZ(float(sin(yaw * M_PI/180))* float(cos(pitch * M_PI/180))); 

    look.normalize();
    right = QVector3D::crossProduct(look, worldUp);
}

void Camera::setFov(double fov){
    this->fov = fov;
}

void Camera::setNearPlane(double nearPlane){
    this->nearPlane = nearPlane;
}

void Camera::setFarPlane(double farPlane){
    this->farPlane = farPlane;
}

double Camera::getFov(){
    return fov;
}

double Camera::getNearPlane(){
    return nearPlane;
}

double Camera::getFarPlane(){
    return farPlane;  
}



