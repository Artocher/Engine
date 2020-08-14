#ifndef MODELDISPLAYWIDGET_H
#define MODELDISPLAYWIDGET_H  

#include "openglwindow.h"
#include <QTimerEvent>

class ModelDisplayWidget : public OpenGLWindow{ 
    public:
        //Constructors
        explicit ModelDisplayWidget(QWidget* widget = nullptr); 

        //
        ModelDisplayWidget(const ModelDisplayWidget&) = delete;  
        ModelDisplayWidget(ModelDisplayWidget&&) = delete;
        ModelDisplayWidget& operator = (const ModelDisplayWidget&) = delete;
        ModelDisplayWidget& operator = (ModelDisplayWidget&&) = delete; 
        
        //Destructors
        virtual ~ModelDisplayWidget(); 

        void keyPressEvent(QKeyEvent* event) override;   
		void timerEvent(QTimerEvent*) override;
		void keyReleaseEvent(QKeyEvent* event) override;
		void mousePressEvent(QMouseEvent* event) override;
		void mouseMoveEvent(QMouseEvent* event) override;
};

#endif 