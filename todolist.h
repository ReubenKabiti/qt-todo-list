#ifndef TODOLIST_H
#define TODOLIST_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class TodoList; }
QT_END_NAMESPACE

class TodoList : public QMainWindow
{
    Q_OBJECT

public:
    TodoList(QWidget *parent = nullptr);
    ~TodoList();

private slots:
    void on_newButton_clicked();
    void deleteButtonPressed();

private:
    Ui::TodoList *ui;
};
#endif // TODOLIST_H
