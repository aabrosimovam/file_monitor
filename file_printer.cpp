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
















void FilePrinter:: Exist(QString fname, qint64 size)
{
    std::cout<< "File "<<fname.toStdString().c_str()<< " exists, size: "<< size<<std::endl;
}

void FilePrinter:: NonExist(QString fname)
{
    std::cout<< "File "<<fname.toStdString().c_str()<< " doesn't exists "<<std::endl;
}

void FilePrinter:: Resize(QString fname, qint64 size)
{
    std::cout<< "File "<<fname.toStdString().c_str()<< " size changed, new size: "<< size<<std::endl;
}

/*
void FilePrinter::FirstOut(QString path, qint64 size, bool ExistStatus)//первый вывод информации о файле
{
    if (ExistStatus)
    {
        std::cout<<"File "<< path.toStdString().c_str()<<" exist, size: " <<size<<std::endl;

    }
    else
    {
        std::cout<<"File "<<path.toStdString().c_str()<<" does not exist"<<std::endl;

    }
}
*/
