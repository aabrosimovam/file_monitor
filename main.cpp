#include <QTimer>
#include <QThread>
#include <iostream>
#include <QCoreApplication>
#include "checkstatus.h"
#include "file_printer.h"
#include "state_file.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CheckStatus monitor;
    FilePrinter testprinter(monitor);

    monitor.AddFile("D:\a.txt");
    monitor.AddFile("D:\b.txt");
    monitor.AddFile("D:\c.txt");
    //monitor.AddFile('d.txt');

    while(true)
    {
       //бесконечный цикл с проверкой состояния файла каждую секунду
       QThread::msleep(1000);
       monitor.udFile();
    }

    return a.exec();

}
