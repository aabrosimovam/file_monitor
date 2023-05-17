#include "file_printer.h"

// добавление файла в монитор(!)
void FilePrinter :: FP_FileAddMon(StateFile file)
{
    cout<<"Файл [ "<<file.getFName().toStdString()<< " ] был добавлен в наблюдение. Его размер = "<<file.getFSize()<<endl;
    if (file.getExistStatus())
    {
        cout<<"Файл существует"<<endl;
    }
    else cout<<"Файл не существует"<<endl;
}

//удаление файла из монитора(!)
void FilePrinter :: FP_FileDeleteMon(StateFile file)
{
    cout<<"Файл [ "<<file.getFName().toStdString()<<" ] был удален из наблюдения"<<endl;
}

//изменение размера файла
void FilePrinter :: FP_fileChange(const QString &FName, qint64 FSize)
{
    cout<<"Размер файла [ "<<FName.toStdString()<<" ] был изменен. Новый размер = "<<FSize<<endl;
}

//при создании файла
void FilePrinter :: FP_fileCreate(const QString &FName, qint64 FSize)
{
    cout<<"Файл [ "<<FName.toStdString()<<" ] был создан. Его размер = "<<FSize<<endl;
}

//при удалении файла
vois FilePrinter :: FP_fileDelete(const QString &FName)
{
    cout<<"Файл [ "<<FName<<" ] был удален"<<endl;
}
