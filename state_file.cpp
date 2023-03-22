#include "state_file.h"
#include <QFile>
#include <QFileInfo>


StateFile::StateFile() //конструктор по умолчанию на всякий случай...
{
    FName="";
    FSize=0;
    ExistStatus=0;
}


StateFile::StateFile(const QString &filename)
{
    FName=filename; //Обзываем файл
    QFile file(FName); //Создаем объект QFile
    FSize = file.size(); //определяем размер файла
    ExistStatus = file.exist(); //проверяем существование

}
//     возможно потребуется перезагрузить    =   !!! подумать


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


//update file data
void udFile()
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
            emit FCreate(FName, FSize); // имитирую сигнал о создании файла
        }
        else if (file.size!=FSize) //сейчас существует, раньше существовал, но размер файла изменился
        {
            FSize=file.size;
            emit FChange(FName, FSize); //имитирую сигнал о изменении файла
        }
    }

    else
        if (ExitStatus) //ситуация: сейчас не существует, но раньше существовал
        {
            ExistStatus=false;
            emit FDelete(FName); //имитирую сигнал об удалении файла
        }

}
