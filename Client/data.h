#ifndef DATA_H
#define DATA_H

#include <QObject>
#include <iostream>
#include <exception>

class Data : public QObject
{
    Q_OBJECT

private:

    std::string _data;

    void CheckSymbols(std::string data);

public:
    std::string GetData();

    void SetData(std::string data);

    void Sort();

    void ShowData();

    void ClearData();

    void EmitSignalAboutWritten();

    Data();

    ~Data();
signals:
    void isWritted();
};

#endif // DATA_H
