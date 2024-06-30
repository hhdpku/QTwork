#include "yuedubaogao.h"
#include "ui_yuedubaogao.h"

yuedubaogao::yuedubaogao(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::yuedubaogao)
{
    ui->setupUi(this);
}

yuedubaogao::~yuedubaogao()
{
    delete ui;
}
