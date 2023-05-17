#include "file_printer.h"

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
