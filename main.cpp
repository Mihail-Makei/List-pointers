#include <stdlib.h>
#include <stdio.h>
#include "MyList_Pointers.h"

void test();

int main()
{
    test();
    return 0;
}

void test()
{
    list_ptr_t list =  {};

    {
        ListPtrCreate(&list);
        ListPtrPushBack(&list, 10);
        ListPtrPushBack(&list, 20);
        ListPtrPushBack(&list, 30);
        printf("VALUE\t%d\n", ListPtrPopBack(&list));
        ListPtrPushBack(&list, 30);
        ListPtrPushBack(&list, 40);
        ListPtrPushBack(&list, 50);
        printf("VALUE\t%d\n", ListPtrPopBack(&list));
        printf("VALUE\t%d\n", ListPtrPopBack(&list));
        printf("VALUE\t%d\n", ListPtrTopBack(&list));
        printf("VALUE\t%d\n", ListPtrTopBack(&list));
        printf("VALUE\t%d\n", ListPtrTopBack(&list));
        ListPtrPushFront(&list, 5);
        ListPtrInsertAfter(&list, 3, 31);
        ListPtrInsertAfter(&list, 3, 32);
        ListPtrInsertAfter(&list, 3, 33);
        ListPtrInsertAfter(&list, 6, 31);
        ListPtrInsertAfter(&list, 8, 39);
        ListPtrInsertAfter(&list, 9, 10);
        printf("VALUE\t%d\n", ListPtrDeleteAfter(&list, 8));
        printf("VALUE\t%d\n", ListPtrDeleteAfter(&list, 8));
        ListPtrInsertAfter(&list, 8, 39);
        printf("INDEX\t%d\n", ListPtrSearch(&list, 32));
        printf("INDEX\t%d\n", ListPtrSearch(&list, 31));
        printf("INDEX\t%d\n", ListPtrSearch(&list, 33));
        printf("INDEX\t%d\n", ListPtrSearch(&list, 34));
        printf("INDEX\t%d\n", ListPtrSearch(&list, 39));
        printf("NUMBER\t%d\n", ListPtrElementNum(&list, 31));
        ListPtrInsertAfter(&list, 3, 39);
        printf("NUMBER\t%d\n", ListPtrElementNum(&list, 39));
        ListPtrPushBack(&list, 10);
        ListPtrPushBack(&list, 10);
        ListPtrPushBack(&list, 10);
        ListPtrPushBack(&list, 10);
        ListPtrPushBack(&list, 10);
        ListPtrPushBack(&list, 10);
        ListPtrPushBack(&list, 10);
        ListPtrPushBack(&list, 10);
        printf("NUMBER\t%d\n", ListPtrElementNum(&list, 10));



        ListPtrDump(list);
        ListPtrDestruct(&list);
    }
}