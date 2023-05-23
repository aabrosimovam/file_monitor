#ifndef FILE_PRINTER_H
#define FILE_PRINTER_H
#include "checkstatus.h"
#include <iostream>

using namespace std;

class FilePrinter : public QObject
{
    Q_OBJECT

private:
    CheckStatus &mm; // монитор для принтера
public:
    //Соединяем сигналы и слоты
    FilePrinter(CheckStatus & monitor) : mm(monitor)
    {
        //соединение сигнал-слот: файл добавлен в монитор
        connect(&mm, &CheckStatus::FileAddMon, this, &FilePrinter::FP_FileAddMon);
        //сигнал-слот: файл удален из монитора
        connect(&mm, &CheckStatus::FileDeleteMon, this, &FilePrinter::FP_FileDeleteMon);
        //сигнал-слот: файл был изменен
        connect(&mm, &CheckStatus::fileChange, this, &FilePrinter::FP_fileChange);
        //сигнал-слот: файл был создан
        connect(&mm, &CheckStatus::fileCreate, this, &FilePrinter::FP_fileCreate);
        //сигнал-слот: файл был удален
        connect(&mm, &CheckStatus::fileDelete, this, &FilePrinter::FP_fileDelete);
    }

public slots:

    void FP_FileAddMon(StateFile file); // файл добавлен под наблюдение
    void FP_FileDeleteMon(StateFile file); // файл удален из под наблюдения
    void FP_fileCreate(const QString &FName, qint64 FSize); // файл создали
    void FP_fileChange(const QString &FName, qint64 FSize); // файл изменили
    void FP_fileDelete(const QString &FName); // файл удалили

};


#endif // FILE_PRINTER_H
