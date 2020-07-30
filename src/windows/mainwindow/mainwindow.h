#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow> 
#include <qpointer.h>

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

    private:
        QPointer<QScreen> _screen;
};

#endif