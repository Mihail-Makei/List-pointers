#ifndef LIST_POINTERS_MYLIST_POINTERS_H
#define LIST_POINTERS_MYLIST_POINTERS_H


#include <assert.h>
#include "Config.h"


typedef int elem_t;


typedef struct ListElem_t
{
    elem_t data;
    ListElem_t* next;
    ListElem_t* prev;
} list_elem_t;


typedef struct MyListPtr
{
    int kan1;
    list_elem_t* head;
    list_elem_t* tail;
    int size;
    int err;
    int kan2;
} list_ptr_t;


void ListPtrCreate(list_ptr_t* list)
{
    list->kan1 = KAN1;
    list->kan2 = KAN2;

    list->size = 0;
    list->err = 0;

    list->head = nullptr;
    list->tail = nullptr;
}


bool verificator(list_ptr_t* list)
{
    if (list->kan1 != KAN1)
    {
        list->err = ERR_KAN;
        return false;
    }

    if (list->kan1 != KAN1)
    {
        list->err = ERR_KAN;
        return false;
    }

    if (list->size < 0)
    {
        list->err = ERR_SIZE;
        return false;
    }

    return true;
}


int ListPtrPushBack(list_ptr_t* list, elem_t value)
{
    assert(verificator(list));

    list_elem_t* temp = (list_elem_t*) calloc(1, sizeof(list_elem_t));
    if (!temp)
    {
        list->err = ERR_ALLOC;
        return -1;
    }

    list->size++;

    temp->data = value;
    temp->next = nullptr;
    temp->prev = list->tail;

    list->tail = temp;
    if (list->size == 1)
        list->head = temp;
    else
        list->tail->prev->next = temp;

    return 1;
}


elem_t ListPtrPopBack(list_ptr_t* list)
{
    assert(verificator(list));
    if (list->size == 0)
    {
        list->err = ERR_EMPTY;
        return 0;
    }

    elem_t data = list->tail->data;

    list->size--;

    list_elem_t* temp = list->tail->prev;
    free(list->tail);
    list->tail = temp;

    if (list->size == 0)
        list->head = nullptr;
    else
        list->tail->next = nullptr;

    return data;
};


elem_t ListPtrTopBack(list_ptr_t* list)
{
    assert(verificator(list));
    if (list->size == 0)
    {
        list->err = ERR_EMPTY;
        return 0;
    }

    return list->tail->data;
}


int ListPtrPushFront(list_ptr_t* list, elem_t value)
{
    assert(verificator(list));

    list_elem_t* temp = (list_elem_t*) calloc(1, sizeof(list_elem_t));
    list->size++;

    temp->data = value;
    temp->next = list->head;
    temp->prev = nullptr;

    list->head = temp;
    if (list->size == 1)
        list->tail = temp;
    else
        list->head->next->prev = temp;

    return 1;
}


elem_t ListPtrPopFront(list_ptr_t* list)
{
    assert(verificator(list));
    if (list->size == 0)
    {
        list->err = ERR_EMPTY;
        return 0;
    }

    elem_t data = list->head->data;

    list->size--;

    list_elem_t* temp = list->head->next;
    free(list->head);
    list->head = temp;

    if (list->size == 0)
        list->tail = nullptr;
    else
        list->head->prev = nullptr;

    return data;
};


elem_t ListPtrTopFront(list_ptr_t* list)
{
    assert(verificator(list));
    if (list->size == 0)
    {
        list->err = ERR_EMPTY;
        return 0;
    }

    return list->head->data;
}


int ListPtrInsertAfter(list_ptr_t* list, int num, elem_t value)
{
    assert(verificator(list));
    if (num > list->size)
    {
        list->err = ERR_ELEMENT;
        return -1;
    }

    list_elem_t* temp = list->head;
    list_elem_t* tempcpy = nullptr;

    for (int i = 2; i <= num; i++)
    {
        tempcpy = temp->next;
        temp = tempcpy;
    }

    list_elem_t* temp_elem_t = (list_elem_t*) calloc(1, sizeof(list_elem_t));
    temp_elem_t->data = value;
    temp_elem_t->prev = temp;

    if (num < list->size)
    {
        temp_elem_t->next = temp->next;
        temp->next->prev = temp_elem_t;
    }
    else
    {
        temp_elem_t->next = nullptr;
        list->tail = temp_elem_t;
    }

    temp->next = temp_elem_t;

    list->size++;

    return 1;
}


int ListPtrDeleteAfter(list_ptr_t* list, int num)
{
    assert(verificator(list));
    if (list->size == 0)
    {
        list->err = ERR_EMPTY;
        return 0;
    }
    if (list->size == 1)
    {
        list->err = ERR_ELEMENT;
        return 0;
    }

    list_elem_t* temp = list->head;
    list_elem_t* tempcpy = nullptr;

    for (int i = 2; i <= num; i++)
    {
        tempcpy = temp->next;
        temp = tempcpy;
    }

    elem_t data = temp->next->data;

    tempcpy = temp->next;

    list->size--;

    if (num == list->size)
        list->tail = temp;
        else
        {
            temp->next = tempcpy->next;
            temp->next->prev = temp;
        }

    free(tempcpy);

    return data;
}


int ListPtrSearch(list_ptr_t* list, elem_t value)
{
    assert(verificator(list));

    int num = 1;
    list_elem_t* temp = list->head;
    list_elem_t* tempcpy = nullptr;

    while (num <= list->size)
    {
        if (temp->data == value)
            return num;

        tempcpy = temp->next;
        temp = tempcpy;

        num++;
    }

    return -1;
}


int ListPtrElementNum(list_ptr_t* list, elem_t value)
{
    assert(verificator(list));

    int counter = 0;
    list_elem_t* temp = list->head;
    list_elem_t* tempcpy = nullptr;

    for (int i = 1; i <= list->size; i++)
    {
        if (temp->data == value)
            counter++;
        tempcpy = temp->next;
        temp = tempcpy;
    }

    return counter;
}


void ListPtrDump(list_ptr_t list)
{
    printf("SIZE\t%d\n", list.size);
    list_elem_t* temp = list.head;
    list_elem_t* tempcpy = nullptr;
    for (int i = 0; i < list.size; i++)
    {
        printf("ELEMENT\t%d\tVALUE\t%d\n", i + 1, temp->data);
        tempcpy = temp->next;
        temp = tempcpy;
    }
}


void ErrPrint(list_ptr_t list)
{
    switch (list.err)
    {
        case ERR_KAN:
            printf("Error %d. List is spoilt\n", list.err);
            if (DUMP)
                ListPtrDump(list);
            break;

        case ERR_ALLOC:
            printf("Error %d. Allocation error\n", list.err);
            if (DUMP)
                ListPtrDump(list);
            break;

        case ERR_EMPTY:
            printf("Error %d. List is empty\n", list.err);
            if (DUMP)
                ListPtrDump(list);
            break;

        case ERR_SIZE:
            printf("Error %d. List size is below zero\n", list.err);
            if (DUMP)
                ListPtrDump(list);
            break;

        case ERR_ELEMENT:
            printf("Error %d. Element not found\n", list.err);
            if (DUMP)
                ListPtrDump(list);
            break;
    }
}


void ListPtrDestruct(list_ptr_t* list)
{
    list_elem_t* temp = list->head;
    list_elem_t* tempcpy = temp;
    for (int i = 1; i <= list->size; i++)
    {
        tempcpy = temp->next;
        free(temp);
        temp = tempcpy;
    }

    list->size = 0;
    list->head = nullptr;
    list->tail = nullptr;

    list->err = 0;
}
#endif //LIST_POINTERS_MYLIST_POINTERS_H
