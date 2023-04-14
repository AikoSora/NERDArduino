#ifndef QDYNAMICBUTTON_H
#define QDYNAMICBUTTON_H

#include <QPushButton>


class QDynamicButton : public QPushButton
{
    Q_OBJECT

public:
    explicit QDynamicButton(QWidget *parent = 0);
    ~QDynamicButton();

    int getID();
    void setID(int id);
    int getCategoryID();
    void setCategoryID(int id);

public slots:

private:
    int buttonID = 0;
    int categoryID = 0;
};

#endif
