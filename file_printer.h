#ifndef FILE_PRINTER_H
#define FILE_PRINTER_H
#include "checkstatus.h"
#include <iostream>

using namespace std;

class FilePrinter : public QObject
{
    Q_OBJECT

private:
    Monitor &mm; // монитор для принтера
public:
    //Соединяем сигналы и слоты
    FilePrinter(Monitor & monitor) : mm(monitor)
    {
        //соединение сигнал-слот: файл добавлен в монитор
        connect(&mm, &Monitor::FileAddMon, this, &FilePrinter::FP_FileAddMon);
        //сигнал-слот: файл удален из монитора
        connect(&mm, &Monitor::FileDeleteMon, this, &FilePrinter::FP_FileDeleteMon);
        //сигнал-слот: файл был изменен
        connect(&mm, &Monitor::fileChange, this, &FilePrinter::FP_fileChange);
        //сигнал-слот: файл был создан
        connect(&mm, &Monitor::fileCreate, this, &FilePrinter::FP_fileCreate);
        //сигнал-слот: файл был удален
        connect(&mm, &Monitor::fileDelete, this, &FilePrinter::FP_fileDelete);
    }

public slots:

    static void FP_FileAddMon(StateFile file); // файл добавлен под наблюдение
    static void FP_FileDeleteMon(StateFile file); // файл удален из под наблюдения
    static void FP_fileCreate(const QString &FName, qint64 FSize); // файл создали
    static void FP_fileChange(const QString &FName, qint64 FSize); // файл изменили
    static void FP_fileDelete(const QString &FName); // файл удалили

};


#endif // FILE_PRINTER_H
