#include "todolist.h"
#include "ui_todolist.h"
#include "newtask.h"
#include "task.h"
#include "ui_task.h"
#include <QDebug>


TodoList::TodoList(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TodoList)
{
    ui->setupUi(this);
}

TodoList::~TodoList()
{
    delete ui;
}


void TodoList::on_newButton_clicked()
{
    Task * task = NewTask::newTask(this);
    if (task == nullptr)
        return;

    task->setParent(this);
    ui->tasks->insertWidget(0, task);
    connect(task->getUi()->deleteButton, &QPushButton::pressed, this, &TodoList::deleteButtonPressed);
}

void TodoList::deleteButtonPressed()
{
    auto task = (Task *)(QObject::sender()->parent());
    ui->tasks->removeWidget(task);
    delete task;
}

