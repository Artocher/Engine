#include "menubar.h"

MenuBar::MenuBar(){
    //Actions
    _newProjectAction = new QAction("New project");
    _loadProjectAction = new QAction("Load project");
    _saveProjectAction = new QAction("Save project");

    //Menus
    _fileMenu = new QMenu("Project");
    _settingsMenu = new QMenu("Settings");

    _fileMenu->addAction(_newProjectAction);
    _fileMenu->addAction(_loadProjectAction);
    _fileMenu->addAction(_saveProjectAction);

    addMenu(_fileMenu); 
    addMenu(_settingsMenu);
}

MenuBar::~MenuBar(){
    
}