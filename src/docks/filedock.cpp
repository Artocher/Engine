#include "filedock.h"

FileDock::FileDock(){
    setAllowedAreas(Qt::BottomDockWidgetArea);   
    setFeatures(QDockWidget::NoDockWidgetFeatures);  
    setFixedHeight(200);
}