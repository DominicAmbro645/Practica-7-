


#ifndef  LIST_INC
#define  LIST_INC

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct
{
   int   index;
   float weight;
} Data;

typedef struct Node
{
//   int data;
   Data data;

   struct Node* next;
   struct Node* prev;
} Node;

typedef struct
{
   Node* first;
   Node* last;
   Node* cursor;
} List;

List* List_New();
void List_Delete( List** p_list );

void List_Push_back( List* list, int index, float weight );
void List_Pop_back( List* list );

void List_Push_front( List* list, int index, float weight );
void List_Pop_front( List* list );

bool List_Is_empty( List* list );

/**
 * @brief Busca la primer ocurrencia con la llave key y si la encuentra coloca ah� al cursor.
 *
 * @param list Referencia a una lista.
 * @param key La llave de b�squeda.
 *
 * @return true si encontr� el elemento; false en caso contrario.
 * @post Si hubo una ocurrencia el cursor es movido a esa posici�n; en caso contrario el cursor no se mueve.
 */
bool List_Find( List* list, int key );

bool List_Remove( List* list, int key );

void List_Cursor_front( List* list );
void List_Cursor_back( List* list );
bool List_Cursor_next( List* list );
bool List_Cursor_prev( List* list );
bool List_Cursor_end( List* list );

/**
 * @brief Devuelve una copia del elemento apuntado por el cursor.
 *
 * @param list Referencia a una lista.
 *
 * @pre El cursor debe apuntar a una posici�n v�lida.
 */
Data List_Cursor_get( List* list );

/**
 * @brief Elimina el elemento apuntado por el cursor.
 *
 * @param list Referencia a una lista.
 *
 * @pre El cursor debe apuntar a una posici�n v�lida.
 * @post El cursor queda apuntando al elemento a la derecha del elemento eliminado; si
 * este hubiese sido el �ltimo, entonces el cursor apunta al primer elemento de la lista.
 */
void List_Cursor_erase( List* list );

/**
 * @brief Aplica la funci�n fn() a cada elemento de la lista. La funci�n fn() es una funci�n unaria.
 *
 * @param list Una lista.
 * @param fn Funci�n unaria que ser� aplicada a cada elemento de la lista.
 */
void List_For_each( List* list, void (*fn)( int, float ) );

#endif   /* ----- #ifndef LIST_INC  ----- */
