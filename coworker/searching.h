#ifndef SEARCHING_H
#define SEARCHING_H

#include <QWidget>
#include<QVBoxLayout>

namespace Ui {
class Searching;
}

class Searching : public QWidget
{
    Q_OBJECT

public:
    explicit Searching(QWidget *parent = nullptr);
    ~Searching();

signals:
    void diaryButtonClicked(const QString &title);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Searching *ui;
    void clearSearchResults();
    QVBoxLayout *diaryLayout;
};

#endif // SEARCHING_H
