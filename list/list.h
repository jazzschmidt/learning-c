
typedef struct {
    long size;
    int* elements;
} intlist;

intlist il_create();

long il_add(intlist*, int);

int il_get(intlist*, long);

void il_remove(intlist*, long);
