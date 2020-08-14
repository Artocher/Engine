#ifndef MODELDISPLAYENGINE_H
#define MODELDISPLAYENGINE_H

#include "engine.h"

class ModelDisplayEngine : public Engine{
    public:
        //Constructors 
        ModelDisplayEngine();

        //Destructors
        ~ModelDisplayEngine() override; 

        //
        ModelDisplayEngine(const ModelDisplayEngine&) = delete;
        ModelDisplayEngine(ModelDisplayEngine&&) = delete;
        ModelDisplayEngine& operator = (const ModelDisplayEngine&) = delete;
        ModelDisplayEngine& operator = (ModelDisplayEngine&&) = delete;

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
};

#endif