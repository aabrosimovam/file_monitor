#include "checkstatus.h"

CheckStatus::CheckStatus ()
{}

bool CheckStatus::AddFile(const QString & filename) //добавление файла в монитор
{
    StateFile temp(filename); // новый файл для проверки на наличие нужного файла
    if (objects.contains(temp))
    {
        return false;
    }
    objects.append(temp); //если файла нет в списке, то добавляем
    emit FileAddMon(temp); //имит. сигнал о добавлении файла
}

bool CheckStatus::DeleteFile()
{
    StateFile temp(filename); // новый файл для проверки
    if (objects.contains(temp))
    {
        objects.removeOne(temp); //если файл есть в списке, то удаляем
        emit FileDeleteMon(temp); //имит. сигнал об удалении файла
        return true;
    }
    return false;
}

void CheckStatus::udFile()
{
    for (int i=0; i<objects.size(); i++)
    {
        switch (objects[i].udFile())
        {
        case 0:
            emit FileCreate(objects[i].getFName(),objects[i].getFSize());
            //сигнал о создании файла
            break;
        case 1:
            emit FileChange(objects[i].getFName(),objects[i].getFSize());
            //сигнал об изменение файла
            break;
        case 2:
            emit fileDelete(objects[i].getFName(),objects[i].getFSize());
            //сигнал об удалении файла
            break;
        case 3:
            break; //ничего не поменялось
        };

    }
}

// нужен ли геттер на список файлов?? скорее нет, но подумать
