#ifndef CAMERA_H
#define CAMERA_H

#include "QVector3D"
#include "QMatrix4x4"
#include <QMap>

enum Direction{FORWARD, BACKWARD, UPWARD, DOWNWARD, LEFT, RIGHT};

class Camera
{
    public:
		Camera() = default;
		Camera(QVector3D position, double pitch, double yaw, QVector3D axis);

		void setPosition(QVector3D position);
		void move(Direction direction);
		void setProjectionMatrix(QMatrix4x4 projectionMatrix); 

		const QMatrix4x4 getViewMatrix();
		const QMatrix4x4 getProjectionMatrix();
		const QVector3D getPosition();
		const QVector3D getAxis();
		const QVector3D getLook(); 

		void setFov(double fov);
		void setNearPlane(double fov);
		void setFarPlane(double fov);
		double getFov();
		double getNearPlane();
		double getFarPlane();

		void updateViewMatrix();
		void updateProjectionMatrix(int viewportWidth, int viewportHeight);
		void updateCameraRotation(const float& offsetX, const float& offsetY);
		void updateCameraPosition(QMap<int, bool> keys);

		virtual ~Camera() = default;

    protected:
		QVector3D position;
		QVector3D look;
		QVector3D axis;
		QMatrix4x4 viewMatrix;
		QMatrix4x4 projectionMatrix;

		QVector3D right;
		QVector3D worldUp;

		double pitch; 
		double yaw;	 

		double maxPitch;
		double minPitch; 

		double fov;
		double nearPlane;
		double farPlane;

	private:
		void updateCameraProperties();
};

#endif
