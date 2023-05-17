#include "state_file.h"
#include <QFile>
#include <QFileInfo>


StateFile::StateFile(const QString &filename)
{
    FName=filename; //Называем файл
    QFile file(FName); //Создаем объект QFile
    FSize = file.size(); //определяем размер файла
    ExistStatus = file.exist(); //проверяем существование

}

//геттеры имени, размера, факта существования

QString StateFile::getFName() const
{
    return FName;
}

QString StateFile::getFSize() const
{
    return FSize;
}

QString StateFile::getExistStatus() const
{
    return ExistStatus;
}


//перегрузки операторов
StateFile::StateFile(const StateFile& temp) //копирования
{
    FName = temp.FName;
    FSize = temp.FSize;
    ExistStatus = temp.ExistStatus;
}

bool StateFile::operator==(const StateFile& temp) const // сравнения
{
    return FName = temp.FName &&
           FSize = temp.FSize &&
           ExistStatus = temp.ExistStatus;
}

StateFile& StateFile::operator =(const StateFile& temp) //присваивания
{
    FName = temp.FName;
    FSize = temp.FSize;
    ExistStatus = temp.ExistStatus;
    return *this;
}


//update file data
// int, т.к в checkstatus я буду использовать switch case
int udFile()
{
    /* существует ли файл сейчас?
     * если нет, но раньше да -> сигнал +
     * если да, но раньше нет -> сигнал +
     * если да, но размер отличается -> сигнал +
     */
    QFile file(FName); //Создаем объект QFile
    bool exist = file.exist();

    if (exist) //сейчас файл существует
    {
        if (!ExistStatus) // а раньше нет
        {
            FSize=file.size();
            ExistStatus=true;
            return 0;
        }
        else if (file.size!=FSize) //сейчас существует, раньше существовал, но размер файла изменился
        {
            FSize=file.size;
            return 1;
    }

    else
        if (ExitStatus) //ситуация: сейчас не существует, но раньше существовал
        {
            ExistStatus=false;
            return 2;
        }

    return 3;
}
