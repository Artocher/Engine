#ifndef ENGINE_H
#define ENGINE_H

#include <QOpenGLFunctions>

#include <QKeyEvent>
#include <QMouseEvent>

class Camera;
class BaseShaderProgram;

class Engine : protected QOpenGLFunctions{
    public:
        Engine();

        virtual ~Engine();

        Engine(const Engine&) = delete;
        Engine(Engine&&) = delete;
        Engine& operator = (const Engine&) = delete;
        Engine& operator = (Engine&&) = delete; 

        virtual void init() = 0;
        void setViewportWidth(int viewportWidth);
        void setViewportHeight(int viewportHeight); 

        virtual void render() = 0; 

        virtual void keyPress(QKeyEvent* event) = 0;
        virtual void keyRelease(QKeyEvent* event) = 0;
        virtual void mousePress(QMouseEvent* event) = 0;
        virtual void mouseMove(QMouseEvent* event, QPoint offset) = 0;

    private:  
        virtual void initShaders() = 0;
        virtual void initModels() = 0;
        virtual void sendDataToShader() = 0;

    protected:
        unsigned int _viewportWidth;
        unsigned int _viewportHeight;

        BaseShaderProgram* _shaderProgram; 

        Camera* _camera;
        
        QMap<int, bool> _keys; 
};

#endif