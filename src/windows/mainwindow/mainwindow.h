#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow> 
#include <qpointer.h>
#include <QResizeEvent>

class FileDock;
class MainOpenGLWindow;
class MenuBar;

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
        QDockWidget* _toolDock;
        MainOpenGLWindow* _mainOpenGLWindow;
        MenuBar* _menuBar;
};

#endif