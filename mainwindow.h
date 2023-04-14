
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include "CategoryData.h"
#include <qdynamicbutton.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT
public:
    QList<CategoryData> load_json_data();
    void add_buttons();
    void menu_button_clicked();
    void category_menu_button_clicked();
    void clearLayout(QLayout *layout);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_left_button_clicked();

    void on_right_button_clicked();

    void on_pushButton_2_clicked();

    void on_category_button_clicked();

    void on_category_left_clicked();

    void on_category_right_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
