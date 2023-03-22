#ifndef CHECKSTATUS_H
#define CHECKSTATUS_H
#include "state_file.h"

class CheckStatus : public QObject
{
    //Q_OBJECT
private:
    QList<StateFile> objects; // список самих филе


public:
    CheckStatus(); //конструктор по умолчанию
    ~CheckStatus(); //деструктор

    //добавить и удалить файлы из списка
    void AddFile();
    void DeleteFile();


    //посылать сигналы когда файл добавили под наблюдение или удалили
    //как лучше??..
};


#endif // CHECKSTATUS_H
