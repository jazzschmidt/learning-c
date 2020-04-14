
typedef struct {
    long size;
    int* elements;
} intlist;

/**
 * Creates an empty list
 */
intlist il_create();

/**
 * Appends a value to a list and returns its index
 *
 * @return index of the item
 */
long il_push(intlist*, int);

/**
 * Retrieves a value by its index
 *
 * @return item of the list
 */
int il_get(intlist*, long);

/**
 * Removes the last element
 */
void il_pop(intlist*);
