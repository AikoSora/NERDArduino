
#ifndef ARDUINODATA_H
#define ARDUINODATA_H

#include <QMainWindow>

class ArduinoData
{
public:
    ArduinoData() {};

    ArduinoData(int id, QString name, QString description, QString example_code)
    {
        this->id = id;
        this->name = name;
        this->description = description;
        this->example_code = example_code;
    }

public:
    int id;
    QString name;
    QString description;
    QString example_code;

};

#endif // ARDUINODATA_H


