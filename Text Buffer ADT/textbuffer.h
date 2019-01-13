typedef struct textbuffer * TB;

typedef struct textbuffer {
	char * text;
	TB next;
	TB prev;
} textbuffer;

void printBuffer     (TB head);
void BufferTraverser (TB head);
void HelpInterface   ();
TB   newTBNode       (char * text);
TB   createTBList    (char * text);
void freeBuffer		 (TB head);


