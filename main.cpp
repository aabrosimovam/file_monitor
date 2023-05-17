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
    CheckStatus& monitor= new CheckStatus();
    FilePrinter out;

    QObject::connect(&monitor, &CheckStatus::fileChange, &out, &FilePrinter::Resize);
    QObject::connect(&monitor, &CheckStatus::fileCreate, &out, &FilePrinter::Exist);
    QObject::connect(&monitor, &CheckStatus::fileDelete, &out, &FilePrinter::NonExist);

    monitor.AddFile('D:\3 year\software development technology\file_monitor\a.txt');
    monitor.AddFile('D:\3 year\software development technology\file_monitor\b.txt');
    monitor.AddFile('D:\3 year\software development technology\file_monitor\c.txt');
    //monitor.AddFile('d.txt');


    while(true)
    {
       //бесконечный цикл с проверкой состояния файла каждую секунду
       QThread::msleep(1000);
       monitor.udFile();
    }

    return a.exec();

}
