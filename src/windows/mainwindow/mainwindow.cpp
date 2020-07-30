#include "mainwindow.h"

#include <QScreen>
#include <QGuiApplication>   

MainWindow::MainWindow(){
    //MainWindow intel
    _screen = QGuiApplication::primaryScreen();
    setPalette(QPalette(QColor(60,60,60)));       
 
    //Setting up the central widget 

    //Setting up the docks

    //Setting up the menu

    //Setting up toolbars
} 

MainWindow::~MainWindow(){

}  