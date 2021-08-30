#include "printer.h"
#include "string.h"
#include <iostream>

using namespace std;


printer::printer() : current_size(0), _head(nullptr), _tail(nullptr), max_size(10)
{
}

bool printer::isfull()
{
    return current_size == max_size;
}

void* printer::getElementByIndex(int index)
{
    Element* result = _head;
    for (int i = 1; i < index; i++)
    {
        result = result->next;
    }
    return result;
}

void printer::getqueue()
{
    for (int i = 0; i < current_size+1; i++)
    {
        Element* current = (Element*)getElementByIndex(i);
        cout << current->workstation_name << endl;
    }
}

void printer::add(const char* name, int rating)
{
    if (isfull()) { return; }
    if (current_size == 0)
    {
        Element* newElement = new Element;
        newElement->rank = rating;
        newElement->next = nullptr;
        newElement->prev = nullptr;
        _head = _tail = newElement;
        int nameLenght = strlen(name) + 1;
        newElement->workstation_name = new char[nameLenght];
        strcpy_s(newElement->workstation_name, nameLenght, name);
        ++current_size;
        return;
    }
    if (current_size > 0)
    {
        Element* newElement = new Element;
        newElement->rank = rating;
        newElement->next = nullptr;
        newElement->prev = nullptr;
        int nameLenght = strlen(name) + 1;
        newElement->workstation_name = new char[nameLenght];
        strcpy_s(newElement->workstation_name, nameLenght, name);
        if (newElement->rank <= _tail->rank)
        {
            _tail->next = newElement;
            newElement->prev = _tail;
            newElement->next = nullptr;
            _tail = newElement;
            ++current_size;
            return;
        }
        if (newElement->rank > _head->rank)
        {
            _head->prev = newElement;
            newElement->next = _head;
            newElement->prev = nullptr;
            _head = newElement;
            ++current_size;
            return;
        }
        if (newElement->rank <= _head->rank && newElement->rank > _tail->rank)
        {
            Element* current;
            Element* prev;
            for (int i = current_size - 1; i > 0; i--)
            {
                current = (Element*)getElementByIndex(i);
                prev = (Element*)getElementByIndex(i - 1);
                if (newElement->rank > current->rank && newElement->rank <= prev->rank)
                {
                    newElement->next = current;
                    current->prev = newElement;
                    newElement->prev = prev;
                    prev->next = newElement;
                }
                break;
            }
            return;
        }
    }

    ++current_size;

}

void* printer::extractElement()  
{
    Element* current = _head;
    _head = current->next;
    _head->prev = nullptr;
    --current_size;
    return current;
}


printer::~printer()
{
    if (_head == nullptr) {
        return;
    }
    Element* current = _head;
    Element* next = _head->next;
    while (current != nullptr)
    {
        next = current->next;
        delete current;
        current = next;
    }
    _head = _tail = nullptr;
    current_size = 0;
}
