#include "state_file.h"
#include <QFile>
#include <QFileInfo>


StateFile::StateFile() //конструктор по умолчанию на всякий случай...
{
    FName="";
    FSize=0;
    ExistStatus=0;
}

//добавить ли конструктор с путем файла???
//подумать


StateFile::StateFile(const QString &filename)
{
    FName=filename; //Обзываем файл
    QFile watched_file(FName);
    FSize = watched_file.size(); //определяем размер файла
    ExistStatus = watched_file.exist(); //проверяем существование

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
    /*!! существует ли файл сейчас? !!
     * если нет, но раньше да -> сигнал
     * если да, но раньше нет -> сигнал
     * если да, но размер отличается -> сигнал
     */
}
