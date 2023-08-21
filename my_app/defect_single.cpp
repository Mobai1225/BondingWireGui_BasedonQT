#include "defect_single.h"
#include "ui_defect_single.h"

defect_single::defect_single(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::defect_single)
{
    ui->setupUi(this);
}

defect_single::~defect_single()
{
    delete ui;
}
