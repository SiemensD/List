#pragma once
class printer
{
private:
    struct Element 
    {
        char* workstation_name; 
        int rank;    
        Element* next;
        Element* prev;
    };
    Element* _head;
    Element* _tail;
    int max_size;    
    int current_size; 
public:
    printer();
    bool isfull();  
    void add(const char* name, int rating);
    void* getElementByIndex(int index);
    void getqueue();  
    void* extractElement(); 
    ~printer();
};

