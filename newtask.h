#ifndef NEWTASK_H
#define NEWTASK_H

#include <QDialog>
#include "task.h"

namespace Ui {
class NewTask;
}

class NewTask : public QDialog
{
    Q_OBJECT

private:
    explicit NewTask(QWidget *parent = nullptr);
    ~NewTask();

public:
    static Task *newTask(QWidget *parent);
    static NewTask **init(QWidget *parent);

private slots:
    void on_okButton_clicked();

private:
    Ui::NewTask *ui;
};

#endif // NEWTASK_H
