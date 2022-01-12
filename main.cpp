#include <QVBoxLayout>
#include <QApplication>
#include <QWidget>
#include "mybutton.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto *button = new MyButton();
    button->show();
    return a.exec();
}
