typedef struct DLLNode   * DLListNode;
typedef struct DLListRep * DLList;

void       PrintDLList         (DLList list);
void       FreeDLList          (DLList list);
void       DLListNodeDelete    (DLList list , int index);
void       InsertNodeAfter     (DLList list , int index, char * value);
void       InsertNodeBefore    (DLList list , int index, char * value);
DLList     CreateDLList        (void);
DLList     NewDLList           (void);
DLListNode NewDLListNode       (char * value);
