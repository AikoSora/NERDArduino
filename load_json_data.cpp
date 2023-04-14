#include <QFile>

#include "mainwindow.h"

QList<CategoryData> MainWindow::load_json_data()
{
    QString json_file_string_text = "";
    QFile json_file(":/json/data/data.json");
    QList<CategoryData> category;

    if (json_file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qInfo("Json file loaded.");

        json_file_string_text = json_file.readAll();
    }

    json_file.close();

    if (json_file_string_text.length() > 0)
    {
        QJsonDocument json_document = QJsonDocument::fromJson(json_file_string_text.toUtf8());
        QJsonObject json = json_document.object();
        QJsonArray json_array = json["category"].toArray();
        QJsonValue json_object;
        int category_index = 1;
        foreach (json_object, json_array)
        {
            QList<ArduinoData> array_data;
            QJsonArray json_data = json_object["lessons"].toArray();
            QJsonValue json_data_object;

            foreach (json_data_object, json_data) {
                ArduinoData data(
                    json_data_object["id"].toInt(),
                    json_data_object["name"].toString(),
                    json_data_object["description"].toString(),
                    json_data_object["example_code"].toString()
                );

                array_data << data;
            }

            CategoryData data(
                category_index,
                json_object["name"].toString(),
                array_data
            );

            category << data;
            category_index += 1;
        }

    }
    else
    {
        qWarning("Json file not loaded!");
    }

    return category;
}
