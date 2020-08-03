#ifndef OBJECT_H
#define OBJECT_H

#include <QVector3D>

class Object{
    public:
        Object(QVector3D position = QVector3D(0,0,0), QVector3D scale = QVector3D(1,1,1), qreal rotation_x = 0, qreal rotation_y = 0, qreal rotation_z = 0);
        virtual~Object();

        //Position
        void setPosition(QVector3D position);
        QVector3D getPosition();

        //Rotation
        void setRotationX(qreal rotation_x);
        void setRotationY(qreal rotation_y);
        void setRotationZ(qreal rotation_z);
        qreal getRotationX();
        qreal getRotationY();
        qreal getRotationZ();

        //Scale
        void setScale(QVector3D scale);
        QVector3D getScale();
        
    protected:
        QVector3D _position;
        qreal _rotation_x;
        qreal _rotation_y;
        qreal _rotation_z;
        QVector3D _scale;
};

#endif
