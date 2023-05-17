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

    monitor.AddFile("A.txt");
    monitor.AddFile("AA.txt");
    monitor.AddFile("AAA.txt");

    return a.exec();
}
