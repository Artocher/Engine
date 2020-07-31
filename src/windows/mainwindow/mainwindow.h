#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow> 
#include <qpointer.h>
#include <QResizeEvent>

#include "openglwindow.h"

class FileDock;

class MainWindow : public QMainWindow{
    public:
        //Constructors
        explicit MainWindow();
        
        //Destructors
        virtual ~MainWindow();

        MainWindow(const MainWindow&) = delete;
	    MainWindow(MainWindow&&) = delete;
        MainWindow& operator = (const MainWindow&) = delete;
	    MainWindow& operator = (MainWindow&&) = delete; 

        void resizeEvent(QResizeEvent* event);

    private:
        QPointer<QScreen> _screen;
        FileDock* _fileDock;
        OpenGLWindow* _openGLWindow;
};

#endif