#include "Widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    auto signal1 = static_cast<void (QSpinBox::*)(int)>
            (&QSpinBox::valueChanged);

    connect(ui->spinBox, signal1, ui->spinBox_2, &QSpinBox::setValue);
    connect(ui->spinBox_2, signal1, ui->spinBox, &QSpinBox::setValue);
}

Widget::~Widget()
{
    delete ui;
}
