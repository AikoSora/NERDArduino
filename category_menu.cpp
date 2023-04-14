#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::category_menu_button_clicked() {
    QDynamicButton* button = qobject_cast<QDynamicButton*>(sender());
    QList<CategoryData> category_data = load_json_data();

    CategoryData data;
    bool stop = false;

    foreach (data, category_data) {
        if (stop)
            break;
        ArduinoData adata;
        foreach (adata, data.lessons) {
            if (adata.id == button->getID() && data.id == button->getCategoryID()) {
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
    }
}
