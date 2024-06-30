#ifndef YUEDUBAOGAO_H
#define YUEDUBAOGAO_H

#include <QMainWindow>

namespace Ui {
class yuedubaogao;
}

class yuedubaogao : public QMainWindow
{
    Q_OBJECT

public:
    explicit yuedubaogao(QWidget *parent = nullptr);
    ~yuedubaogao();

private:
    Ui::yuedubaogao *ui;
};

#endif // YUEDUBAOGAO_H
