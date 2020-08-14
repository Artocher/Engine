#include "filedock.h"

#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QListWidget>
#include <QListWidgetItem>

FileDock::FileDock(){
    setAllowedAreas(Qt::BottomDockWidgetArea);   
    setFeatures(QDockWidget::NoDockWidgetFeatures);  
    setFixedHeight(200);

    //ListWidget


    //TreeWidget
    QTreeWidgetItem* item = new QTreeWidgetItem();
    item->setText(0, QString::fromStdString("Project"));

    QTreeWidget* treeWidget = new QTreeWidget();
    treeWidget->resize(500,250);
    treeWidget->setHeaderItem(item);

    QTreeWidgetItem* item2 = new QTreeWidgetItem(treeWidget);
    item2->setIcon(0, QIcon(QPixmap("textures/close.png")));
    item2->setText(0, QString::fromStdString("textures"));

    QTreeWidgetItem* item3 = new QTreeWidgetItem(treeWidget); 
    item3->setIcon(0, QIcon(QPixmap("textures/close.png"))); 
    item3->setText(0, QString::fromStdString("models"));

    QTreeWidgetItem* item4 = new QTreeWidgetItem(treeWidget);
    item4->setIcon(0, QIcon(QPixmap("textures/close.png")));
    item4->setText(0, QString::fromStdString("maps"));
}