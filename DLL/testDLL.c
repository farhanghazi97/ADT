#include <stdio.h>
#include "DLL.h"

int main(void) {

    int sum = 0;
    DLList list = CreateDLList();
    PrintDLList(list);

    /* TEST BED FOR ADT */

    FreeDLList(list);
}
