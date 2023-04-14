#include "mainwindow.h"
#include <QMainWindow>
#include "ui_mainwindow.h"


void MainWindow::clearLayout(QLayout *layout) {
    if (!layout) return;

    QLayoutItem *item;
    QLayout *sublayout;
    QWidget *widget;

    while ((item = layout->takeAt(0)) != nullptr) {
        if ((sublayout = item->layout()) != nullptr)
            MainWindow::clearLayout(sublayout);

        if ((widget = item->widget()) != nullptr) {
            widget->hide();
            delete widget;
        }

        delete item;
    }
}