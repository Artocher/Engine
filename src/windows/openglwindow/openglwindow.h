#ifndef OPENGLWINDOW_H
#define OPENGLWINDOW_H

#include <QOpenGLWidget>
 
class OpenGLWindow : public QOpenGLWidget{  
    public:
        OpenGLWindow(QWidget* widget = nullptr);  

        OpenGLWindow(const OpenGLWindow&) = delete;
        OpenGLWindow(OpenGLWindow&&) = delete;
        OpenGLWindow& operator = (const OpenGLWindow&) = delete;
        OpenGLWindow& operator = (OpenGLWindow&&) = delete;

        virtual ~OpenGLWindow();

        //GL render functions
	    void initializeGL() override; 
	    void resizeGL(int w, int h) override;
	    void paintGL() override;

        //Events
	    void keyPressEvent(QKeyEvent* event) override; 
	    void keyReleaseEvent(QKeyEvent* event) override;
	    void mousePressEvent(QMouseEvent* event) override;
	    void mouseMoveEvent(QMouseEvent* event) override; 
};

#endif 
