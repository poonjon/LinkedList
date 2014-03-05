#include "unity.h"
#include "LinkedList.h"

void setUp(){}
void tearDown(){}

void test_remove_last(){
	LinkedList *list = createLinkedList();
	Element arrayElem[] = {{.next = NULL, .data = 1}};
	
	list->length = 1;
	list->head = &arrayElem[0];
	list->tail = &arrayElem[0];
	
	List_removeLast(list);
	
	TEST_ASSERT_NULL(list->head);
	TEST_ASSERT_NULL(list->tail);
	TEST_ASSERT_EQUAL(0, list->length);
}

void test_remove_last_2_element(){
	LinkedList *list = createLinkedList();
	Element arrayElem[] = {{.next = &arrayElem[1], .data = 1},
						   {.next = NULL, .data = 2}};
	
	list->length = 2;
	list->head = &arrayElem[0];
	list->tail = &arrayElem[1];
	
	List_removeLast(list);
	
	TEST_ASSERT_EQUAL_PTR(&arrayElem[0], list->head);
	TEST_ASSERT_EQUAL_PTR(&arrayElem[0], list->tail);
	TEST_ASSERT_NULL(arrayElem[0].next);
	TEST_ASSERT_EQUAL(1, list->length);
}

void test_remove_last_null_head_and_tail_should_be_null(){
	LinkedList *list = createLinkedList();
	
	Element arrayElem[] = {{.next = NULL, .data = 0}};
	
	list->length = 0;
	list->head = NULL;
	list->tail = NULL;
	
	List_removeLast(list);
	
	TEST_ASSERT_EQUAL_PTR(NULL, list->head);
	TEST_ASSERT_EQUAL_PTR(NULL, list->tail);
	TEST_ASSERT_NULL(arrayElem[0].next);
	TEST_ASSERT_EQUAL(0, list->length);

}





