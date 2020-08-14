#include "mainwindow.h"

#include <QScreen>
#include <QGuiApplication>   

#include "filedock.h"
#include "mainopenglwindow.h"
#include "menubar.h"

MainWindow::MainWindow(){
    //MainWindow intel
    _screen = QGuiApplication::primaryScreen();
    setMinimumSize(1280, 800);
    setPalette(QPalette(QColor(60,60,60)));       
 
    //Setting up the central widget 
    _mainOpenGLWindow = new MainOpenGLWindow(this, QPoint(500,500));  
    setCentralWidget(_mainOpenGLWindow);

    //Setting up the docks
    _fileDock = new FileDock();
    _toolDock = new QDockWidget();
    _toolDock->setMinimumWidth(200);

    addDockWidget(Qt::BottomDockWidgetArea, _fileDock);  
    addDockWidget(Qt::LeftDockWidgetArea, _toolDock);  

    //Setting up the menu
    _menuBar = new MenuBar();
    setMenuBar(_menuBar);

    //Setting up toolbars

} 

MainWindow::~MainWindow(){

}  

void MainWindow::resizeEvent(QResizeEvent* event){
    _fileDock->setMinimumHeight(event->size().height() / 4);
}