#ifndef OBJECT_H
#define OBJECT_H

#include <QVector3D>

class Object{
    public:
        Object(QVector3D position, QVector3D scale, qreal rotation_x, qreal rotation_y, qreal rotation_z);
        Object();
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
