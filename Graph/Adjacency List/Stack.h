typedef struct StackNode * SNode;
typedef struct StackRep  * Stack;

typedef struct StackNode {
    int value;
    SNode next;
} StackNode;

typedef struct StackRep {
    int size;
    SNode top;
} StackRep;

Stack newStack     (void);
Stack Push         (Stack s , int value);
SNode newSNode     (int value);
void  PrintStack   (Stack s);
void  FreeStack    (Stack s);
bool  StackIsEmpty (Stack s);
int   Pop          (Stack s);
