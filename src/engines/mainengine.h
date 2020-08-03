#ifndef MAINENGINE_H
#define MAINENGINE_H

#include "engine.h"

class Model;

class MainEngine : public Engine{
    public:
        MainEngine();

        virtual ~MainEngine();

        MainEngine(const MainEngine&) = delete;
        MainEngine(Engine&&) = delete;
        MainEngine& operator = (const MainEngine&) = delete;
        MainEngine& operator = (MainEngine&&) = delete;

        void init(); 
        void render();

        void keyPress(QKeyEvent* event); 
        void keyRelease(QKeyEvent* event);
        void mousePress(QMouseEvent* event);
        void mouseMove(QMouseEvent* event, QPoint offset); 

    private:
        void initShaders();
        void sendDataToShader();
        void initModels();

        std::vector<Model*> models;
};

#endif