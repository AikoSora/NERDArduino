#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->data_id->hide();
    ui->category_id->hide();
    ui->stackedWidget->setCurrentWidget(ui->page);
    this->add_buttons();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page);
    MainWindow::clearLayout(ui->category_lessons->layout());
    delete ui->category_lessons->layout();
}


void MainWindow::on_left_button_clicked()
{
    QList<CategoryData> category_data = load_json_data();

    CategoryData data;
    bool stop = false;

    foreach (data, category_data) {
        if (stop)
            break;
        ArduinoData adata;
        foreach (adata, data.lessons) {
            if (adata.id == ui->data_id->text().toInt() - 1 && data.id == ui->category_id->text().toInt()) {
                if (adata.id == 1)
                    ui->left_button->setDisabled(true);
                else
                    ui->left_button->setDisabled(false);

                if (adata.id == data.lessons.count())
                    ui->right_button->setDisabled(true);
                else
                    ui->right_button->setDisabled(false);

                QString markdown_text = adata.example_code;
                QString description = adata.description;
                QString name = adata.name;
                QString id = QString::number(adata.id);

                ui->markdown->setMarkdown(QString("```c++\n%1").arg(markdown_text));
                ui->description->setText(description);
                ui->name->setText(name);
                ui->lesson_name->setText(name);
                ui->category_button->setText(data.name);
                ui->data_id->setText(id);
                stop = !stop;
                break;
            }
        }
    }
}


void MainWindow::on_right_button_clicked()
{
    QList<CategoryData> category_data = load_json_data();

    CategoryData data;
    bool stop = false;

    foreach (data, category_data) {
        if (stop)
            break;
        ArduinoData adata;
        foreach (adata, data.lessons) {
            if (adata.id == ui->data_id->text().toInt() + 1 && data.id == ui->category_id->text().toInt()) {
                if (adata.id == 1)
                    ui->left_button->setDisabled(true);
                else
                    ui->left_button->setDisabled(false);

                if (adata.id == data.lessons.count())
                    ui->right_button->setDisabled(true);
                else
                    ui->right_button->setDisabled(false);

                QString markdown_text = adata.example_code;
                QString description = adata.description;
                QString name = adata.name;
                QString id = QString::number(adata.id);

                ui->markdown->setMarkdown(QString("```c++\n%1").arg(markdown_text));
                ui->description->setText(description);
                ui->name->setText(name);
                ui->lesson_name->setText(name);
                ui->category_button->setText(data.name);
                ui->data_id->setText(id);
                stop = !stop;
                break;
            }
        }
    }
}




void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page);
    MainWindow::clearLayout(ui->category_lessons->layout());
    delete ui->category_lessons->layout();
}


void MainWindow::on_category_button_clicked()
{
    MainWindow::clearLayout(ui->category_lessons->layout());
    delete ui->category_lessons->layout();

    QList<CategoryData> category_data = load_json_data();

    CategoryData data;

    foreach (data, category_data) {
        ArduinoData adata;
        foreach (adata, data.lessons) {
            if (data.id == ui->category_id->text().toInt()) {
                ui->category_name_in_menu->setText(data.name);

                ArduinoData adata;
                QVBoxLayout *layout = new QVBoxLayout;

                foreach (adata, data.lessons) {
                    QDynamicButton *button = new QDynamicButton(this);

                    button->setText(adata.name);
                    button->setID(adata.id);
                    button->setCategoryID(data.id);
                    button->setStyleSheet("border: none;\nborder-bottom: 1px solid rgb(85, 255, 255);\nfont-size: 15px;\nmargin-left: 20%;text-align: left;");
                    button->setCursor(QCursor(Qt::PointingHandCursor));

                    connect(button, &QPushButton::clicked, this, &MainWindow::category_menu_button_clicked);
                    layout->addWidget(button);
                }

                layout->addItem(new QSpacerItem(0,1000, QSizePolicy::Expanding, QSizePolicy::Expanding));
                ui->category_lessons->setLayout(layout);
                ui->stackedWidget->setCurrentWidget(ui->page_3);
                break;
            }
        }
    }

    ui->stackedWidget->setCurrentWidget(ui->page_3);
}


void MainWindow::on_category_left_clicked()
{
    QList<CategoryData> category_data = load_json_data();

    CategoryData data;
    bool stop = false;

    foreach (data, category_data) {
        if (stop)
            break;
        ArduinoData adata;
        foreach (adata, data.lessons) {
            if (data.id == ui->category_id->text().toInt() - 1 && adata.id == 1) {
                if (adata.id == 1)
                    ui->left_button->setDisabled(true);
                else
                    ui->left_button->setDisabled(false);

                if (adata.id == data.lessons.count())
                    ui->right_button->setDisabled(true);
                else
                    ui->right_button->setDisabled(false);

                if (data.id == 1)
                    ui->category_left->setDisabled(true);
                else
                    ui->category_left->setDisabled(false);

                if (data.id == category_data.count())
                    ui->category_right->setDisabled(true);
                else
                    ui->category_right->setDisabled(false);

                QString markdown_text = adata.example_code;
                QString description = adata.description;
                QString name = adata.name;
                QString id = QString::number(adata.id);
                QString category_id = QString::number(data.id);

                ui->markdown->setMarkdown(QString("```c++\n%1").arg(markdown_text));
                ui->description->setText(description);
                ui->name->setText(name);
                ui->lesson_name->setText(name);
                ui->category_button->setText(data.name);
                ui->stackedWidget->setCurrentWidget(ui->page_2);
                ui->data_id->setText(id);
                ui->category_id->setText(category_id);
                stop = !stop;
                break;
            }
        }

        if (data.lessons.count() == 0) {
            MainWindow::clearLayout(ui->category_lessons->layout());
            delete ui->category_lessons->layout();

            ui->stackedWidget->setCurrentWidget(ui->page_3);
            ui->category_name_in_menu->setText(data.name);
        }
    }
}


void MainWindow::on_category_right_clicked()
{
    QList<CategoryData> category_data = load_json_data();

    CategoryData data;
    bool stop = false;

    foreach (data, category_data) {
        if (stop)
            break;
        ArduinoData adata;
        foreach (adata, data.lessons) {
            if (data.id == ui->category_id->text().toInt() + 1 && adata.id == 1) {
                if (adata.id == 1)
                    ui->left_button->setDisabled(true);
                else
                    ui->left_button->setDisabled(false);

                if (adata.id == data.lessons.count())
                    ui->right_button->setDisabled(true);
                else
                    ui->right_button->setDisabled(false);

                if (data.id == 1)
                    ui->category_left->setDisabled(true);
                else
                    ui->category_left->setDisabled(false);

                if (data.id == category_data.count())
                    ui->category_right->setDisabled(true);
                else
                    ui->category_right->setDisabled(false);

                QString markdown_text = adata.example_code;
                QString description = adata.description;
                QString name = adata.name;
                QString id = QString::number(adata.id);
                QString category_id = QString::number(data.id);

                ui->markdown->setMarkdown(QString("```c++\n%1").arg(markdown_text));
                ui->description->setText(description);
                ui->name->setText(name);
                ui->lesson_name->setText(name);
                ui->category_button->setText(data.name);
                ui->stackedWidget->setCurrentWidget(ui->page_2);
                ui->data_id->setText(id);
                ui->category_id->setText(category_id);
                stop = !stop;
                break;
            }
        }

        if (data.lessons.count() == 0) {
            MainWindow::clearLayout(ui->category_lessons->layout());
            delete ui->category_lessons->layout();

            ui->stackedWidget->setCurrentWidget(ui->page_3);
            ui->category_name_in_menu->setText(data.name);
        }
    }
}

