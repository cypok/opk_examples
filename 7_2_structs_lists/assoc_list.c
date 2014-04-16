#include "assoc_list.h"

#include <stdlib.h>
#include <assert.h>

// This implementation does not remove old key-value pairs while update.
// So while foreach all old values for each key is processed.

typedef struct _ListNode {
	struct _ListNode *next;
	void *key;
	void *value;
} ListNode;

struct _AssocList {
	ListNode *head;
	CmpFunc cmp;
};

AssocList * alist_create(CmpFunc cmp) {
	AssocList *alist = (AssocList*)malloc(sizeof(AssocList));
	if (alist == NULL) {
		return NULL;
	}
	alist->head = NULL;
	alist->cmp = cmp;
	return alist;
}

void alist_destroy(AssocList *alist) {
	ListNode *node = alist->head;
	while (node != NULL) {
		ListNode *temp = node;
		node = node->next;
		free(temp);
	}
	free(alist);
}

/* Value cannot be NULL. */
void alist_put(AssocList *alist, void *key, void *value) {
	assert(value != NULL);

	ListNode *node = (ListNode*)malloc(sizeof(ListNode));
	if (node == NULL) {
		return;
	}
	node->next = alist->head;
	node->key = key;
	node->value = value;

	alist->head = node;
}

/* Returns NULL if key not found. */
void* alist_get(AssocList *alist, void *key) {
	ListNode *node = alist->head;
	while (node != NULL) {
		if ((alist->cmp)(node->key, key) == 0) {
			return node->value;
		}
		node = node->next;
	}
	return NULL;
}

void alist_foreach(AssocList *alist, ForeachFunc f) {
	ListNode *node = alist->head;
	while (node != NULL) {
		f(node->key, node->value);
		node = node->next;
	}
}
