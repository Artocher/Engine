#include "mainopenglwindow.h"
#include "mainengine.h"

#include <QCursor>

MainOpenGLWindow::MainOpenGLWindow() : OpenGLWindow(nullptr){ 
    _engine = new MainEngine();
    setFocusPolicy(Qt::StrongFocus);
    startTimer(1000/200);
 
    setMouseTracking(true);
    _mouseLock = false; 
    _lockCoordinates = QPoint(0,0);
}

MainOpenGLWindow::MainOpenGLWindow(QWidget* widget, QPoint lockCoordinates) : OpenGLWindow(widget){
    _engine = new MainEngine();
    setFocusPolicy(Qt::StrongFocus);
    startTimer(1000/200);

    setMouseTracking(true);

    _mouseLock = true;
    _lockCoordinates = lockCoordinates;  

    QCursor c = cursor();
    c.setShape(Qt::BlankCursor);
    setCursor(c);
}

MainOpenGLWindow::~MainOpenGLWindow(){

}

void MainOpenGLWindow::keyPressEvent(QKeyEvent* event){
    _engine->keyPress(event);
    if(event->key() == Qt::Key_Escape){
        _mouseLock = false;
        QCursor c = cursor();
        c.setShape(Qt::ArrowCursor);
        setCursor(c);
    }

    if(event->key() == Qt::Key_Space){
        _mouseLock = true;
        QCursor c = cursor(); 
        c.setShape(Qt::BlankCursor); 
        setCursor(c);
    }
}

void MainOpenGLWindow::keyReleaseEvent(QKeyEvent* event){
    _engine->keyRelease(event);
}

void MainOpenGLWindow::mousePressEvent(QMouseEvent* event){
    _engine->mousePress(event);
}

void MainOpenGLWindow::mouseMoveEvent(QMouseEvent* event){
    if(_mouseLock)
        _engine->mouseMove(event, _lockCoordinates - this->mapToGlobal(QPoint(0,0)));
}

void MainOpenGLWindow::timerEvent(QTimerEvent*){
    if(_mouseLock){
        QCursor c = cursor();
        c.setPos(_lockCoordinates.x(), _lockCoordinates.y());
        setCursor(c);
        update(); 
    }
}