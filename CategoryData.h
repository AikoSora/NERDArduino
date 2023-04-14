
#ifndef CATEGORYDATA_H
#define CATEGORYDATA_H

#include "ArduinoData.h"
#include <QMainWindow>

class CategoryData
{
public:
    CategoryData() {};

    CategoryData(int id, QString name, QList<ArduinoData> lessons)
    {
        this->id = id;
        this->name = name;
        this->lessons = lessons;
    }

public:
    int id;
    QString name;
    QList<ArduinoData> lessons;

};
#endif // CATEGORYDATA_H
