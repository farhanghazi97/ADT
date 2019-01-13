typedef struct textbuffer * TB;

typedef struct textbuffer {
	char * text;
	TB next;
	TB prev;
} textbuffer;

void PrintBuffer     (TB head);
void BufferTraverser (TB head);
void HelpInterface   ();
void FreeBuffer		 (TB head);
TB   NewTBNode       (char * text);
TB   CreateTBList    (char * text);



