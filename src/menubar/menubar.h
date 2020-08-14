#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>
#include <QAction>
#include <QMenu>

class MenuBar : public QMenuBar{
    public:
        MenuBar();
        ~MenuBar();
    private:
        QMenu* _fileMenu;
        QMenu* _settingsMenu;
        
        QAction* _newProjectAction;
        QAction* _loadProjectAction;
        QAction* _saveProjectAction;
};

#endif 