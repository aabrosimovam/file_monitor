#ifndef FILE_PRINTER_H
#define FILE_PRINTER_H
#include "checkstatus.h"
#include <iostream>

using namespace std;

class FilePrinter : public QObject
{
    Q_OBJECT

//private:


public slots:
    /*
    void OnFileAddedToMonitor(StateFile file); //при добавлении файла в монитор
    void OnFileDeletedFromMonitor(StateFile file);  //при удалении файла из монитора
    void OnFileChanged(const QString &file_name, qint64 file_size); //при изменении размера файла
    void OnFileCreated(const QString &file_name, qint64 file_size); //при создании файла
    void OnFileDeleted(const QString &file_name); //при удалении файла
    */

    void Exist(QString fname,qint64 size);
    void NonExist(QString fname);
    void Resize(QString fname, qint64 size);
    //void FirstOut(QString path, qint64 size,bool ExistStatus);

};


#endif // FILE_PRINTER_H
