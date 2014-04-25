#include "assoc_list.h"

#include <stdlib.h>
#include <assert.h>

// This implementation removes old key-value pairs while update.
// So while foreach only last value for each key is processed.

typedef struct _ListNode {
	struct _ListNode *next;
	void *key;
	void *value;
} ListNode;

struct _AssocList {
	ListNode *head;
	CmpFunc cmp;
	DestroyFunc destroy_entry;
};

AssocList * alist_create(CmpFunc cmp, DestroyFunc destroy_entry) {
	AssocList *alist = (AssocList*)malloc(sizeof(AssocList));
	if (alist == NULL) {
		return NULL;
	}
	alist->head = NULL;
	alist->cmp = cmp;
	alist->destroy_entry = destroy_entry;
	return alist;
}

void alist_destroy(AssocList *alist) {
	ListNode *node = alist->head;
	while (node != NULL) {
		ListNode *temp = node;
		node = node->next;
		(alist->destroy_entry)(temp->key, temp->value);
		free(temp);
	}
	free(alist);
}

static void alist_delete(AssocList *alist, void *key) {
    ListNode *prev = NULL;
    ListNode *node = alist->head;
    while (node != NULL && (alist->cmp)(node->key, key) != 0) {
        prev = node;
        node = node->next;
    }
    if (node != NULL) {
        if (prev == NULL) {
            assert(alist->head == node);
            alist->head = node->next;
        } else {
            prev->next = node->next;
        }
        (alist->destroy_entry)(node->key, node->value);
        free(node);
    }
}

/* Value cannot be NULL. */
void alist_put(AssocList *alist, void *key, void *value) {
	assert(value != NULL);

    alist_delete(alist, key);

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
