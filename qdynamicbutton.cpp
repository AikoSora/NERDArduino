
#include "qdynamicbutton.h"

QDynamicButton::QDynamicButton(QWidget *parent) :
    QPushButton(parent) {}

QDynamicButton::~QDynamicButton() {}

int QDynamicButton::getID() {
    return buttonID;
}

void QDynamicButton::setID(int id) {
    buttonID = id;
}

int QDynamicButton::getCategoryID() {
    return categoryID;
}

void QDynamicButton::setCategoryID(int id) {
    categoryID = id;
}
