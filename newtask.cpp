#include "newtask.h"
#include "ui_newtask.h"

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
    auto instancePtr = init(parent);
    auto instance = *instancePtr;

    instance->exec();

    QString taskName = instance->ui->taskName->text();
    if (taskName.length() == 0)
        return nullptr;

    Task *task = new Task;
    task->setTaskName(taskName);

    delete instance;
    *instancePtr = nullptr;
    return task;
}

NewTask **NewTask::init(QWidget *parent)
{
    static NewTask *instance = nullptr;
    if (instance == nullptr)
        instance = new NewTask(parent);
    return &instance;
}

void NewTask::on_okButton_clicked()
{
    accept();
}

