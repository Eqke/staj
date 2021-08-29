#include "data.h"

void Data::CheckSymbols(std::string data)
{
    if (data.length() > 64)
    {
        throw std::length_error("length must be less then 64");
    }
    for (auto i = 0; i < data.length(); i++)
    {
        if ((data[i] < '0') || (data[i] > '9'))
        {
            throw std::invalid_argument("data can have only figures");
        }
    }
}

std::string Data::GetData()
{
    return this->_data;
}

void Data::SetData(std::string data)
{
    try
    {
        CheckSymbols(data);
        this->_data = data;
    }
    catch (std::exception err)
    {
        std::cout << err.what() << std::endl;
    }
}

void Data::Sort()
{
    int arr[10];
    std::string sortData;
    for (auto i = 0; i < 10; i++)
    {
        arr[i] = 0;
    }
    for (auto i = 0; i < this->_data.length(); i++)
    {
        arr[this->_data[i] - '0']++;
    }
    for (auto i = 9; i >= 0; i--)
    {
        while (arr[i] != 0)
        {
            if (i % 2 != 0)
            {
                sortData += i + '0';
            }
            else
            {
                sortData += "KB";
            }
            arr[i]--;
        }
    }
    this->_data = sortData;
}

void Data::ShowData()
{
    std::cout << this->_data << std::endl;
}

void Data::ClearData()
{
    this->_data.clear();
}

void Data::EmitSignalAboutWritten()
{
    emit isWritted();
}

Data::Data()
{

}

Data::~Data()
{

}


