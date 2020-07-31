#include "filedock.h"

FileDock::FileDock(){
    setMinimumHeight(250);
    setAllowedAreas(Qt::BottomDockWidgetArea);   
    setFeatures(QDockWidget::NoDockWidgetFeatures);  
}