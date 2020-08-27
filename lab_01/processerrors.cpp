#include "processerrors.h"

std::string processErrors(error_t er)
{
    std::string message = "Ошибка\n";

    switch (er)
    {
    case(MEM_ERR):
        message = "Ошибка памяти\n";
        break;

    case(MEM_ERR_INDEX):
        message = "Ошибка памяти\n";
        break;

    case(MEM_ERR_POINT):
        message = "Ошибка памяти\n";
        break;

    case(OPEN_ERR):
        message = "Ошибка при открытии файла\n";
        break;

    case(INCORRECT_DATA):
        message = "Некорректные данные\n";
        break;

    case(NOT_LOADED):
        message = "Модель не была загружена\n";
        break;

    default:
        break;
    }

    return message;
}
