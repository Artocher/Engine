#ifndef MAINOPENGLWINDOW_H
#define MAINOPENGLWINDOW_H

#include "openglwindow.h"
#include <QTimerEvent>

class MainOpenGLWindow : public OpenGLWindow{
    public:
        explicit MainOpenGLWindow();
        MainOpenGLWindow(QWidget* widget, QPoint lockCoordinates);

        MainOpenGLWindow(const MainOpenGLWindow&) = delete;
        MainOpenGLWindow(MainOpenGLWindow&&) = delete;
        MainOpenGLWindow& operator = (const MainOpenGLWindow&) = delete;
        MainOpenGLWindow& operator = (MainOpenGLWindow&&) = delete;

        virtual ~MainOpenGLWindow();

        void keyPressEvent(QKeyEvent* event) override; 
		void timerEvent(QTimerEvent*) override;
		void keyReleaseEvent(QKeyEvent* event) override;
		void mousePressEvent(QMouseEvent* event) override;
		void mouseMoveEvent(QMouseEvent* event) override;

    private:
        bool _mouseLock;
        QPoint _lockCoordinates;
};

#endif 