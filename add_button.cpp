#include <qdynamicbutton.h>

#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::add_buttons()
{
    QList<CategoryData> category_data = load_json_data();

    if (category_data.count() > 0) {

        CategoryData data;
        QVBoxLayout *layout = new QVBoxLayout;

        foreach (data, category_data) {
            QDynamicButton *button = new QDynamicButton(this);

            button->setText(data.name);
            button->setID(data.id);
            button->setStyleSheet("border: none;\nborder-bottom: 1px solid rgb(85, 255, 255);\nfont-size: 15px;\nmargin-left: 20%;");
            button->setCursor(QCursor(Qt::PointingHandCursor));

            connect(button, &QPushButton::clicked, this, &MainWindow::menu_button_clicked);
            layout->addWidget(button);
        }
        layout->addItem(new QSpacerItem(0,1000, QSizePolicy::Expanding, QSizePolicy::Expanding));
        ui->main_text_layout->setLayout(layout);
    }
}
