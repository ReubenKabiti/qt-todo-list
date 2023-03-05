#include "newtask.h"
#include "ui_newtask.h"
#include <QDebug>

NewTask::NewTask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewTask)
{
    ui->setupUi(this);
}

NewTask::~NewTask()
{
    delete ui;
}

Task *NewTask::newTask(QWidget *parent)
{
    auto instance = init(parent);
    int status = instance->exec();
    if (status == 0)
        return nullptr;

    QString taskName = instance->ui->taskName->text();
    Task *task = new Task;
    task->setTaskName(taskName);

    return task;
}

NewTask *NewTask::init(QWidget *parent)
{
    static NewTask *instance = nullptr;
    if (instance == nullptr)
        instance = new NewTask(parent);
    return instance;
}

void NewTask::on_okButton_clicked()
{
    accept();
}


void NewTask::on_cancelButton_clicked()
{
    reject();
}

