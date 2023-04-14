#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::menu_button_clicked() {
    QDynamicButton* button = qobject_cast<QDynamicButton*>(sender());
    QList<CategoryData> json_data = load_json_data();

    if (json_data.count() > 0) {
        CategoryData data;

        foreach (data, json_data) {
            if (data.id == button->getID()) {
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
}
