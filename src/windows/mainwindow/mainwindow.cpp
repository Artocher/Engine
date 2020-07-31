#include "mainwindow.h"

#include <QScreen>
#include <QGuiApplication>   

#include "filedock.h"
#include "openglwindow.h"

MainWindow::MainWindow(){
    //MainWindow intel
    _screen = QGuiApplication::primaryScreen();
    setMinimumSize(1280, 800);
    setPalette(QPalette(QColor(60,60,60)));       
 
    //Setting up the central widget 
    _openGLWindow = new OpenGLWindow(this);  
    setCentralWidget(_openGLWindow);

    //Setting up the docks
    _fileDock = new FileDock();
    addDockWidget(Qt::BottomDockWidgetArea, _fileDock);    

    //Setting up the menu

    //Setting up toolbars
} 

MainWindow::~MainWindow(){

}  

void MainWindow::resizeEvent(QResizeEvent* event){
    _fileDock->setMinimumHeight(event->size().height() / 4);
}