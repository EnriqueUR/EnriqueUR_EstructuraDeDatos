#include <QtCore/QCoreApplication>
#include <iostream>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "HOLA MUNDO";

    return a.exec();
}
