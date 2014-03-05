#include "LinkedList.h"
#include <stdio.h>
#include <malloc.h>



LinkedList *createLinkedList(){
	LinkedList *list = malloc(sizeof(LinkedList));
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
	
	return list;
}

Element *List_removeLast(LinkedList *list){
	Element *elem;
	
	elem = list->tail;
	
	//if head = tail, nothing can be removed so it is null
	if(list->head == list->tail){
		list->head = NULL;
		list->tail = NULL;
		
		}
	
	//if head doesnt equal to tail then remove 
	else {
		*(list->tail)=*(list->tail)--;
		(list->tail)->next = NULL;
		
		}
	
	//check if length is 0, if 0 do not decrement, otherwise minus 1
	if(list->length == 0){
		return 0;
	}
	
	else
	list->length = (list->length) -1;
	
	return elem;
}
