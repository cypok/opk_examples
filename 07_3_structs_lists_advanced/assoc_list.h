#pragma once

typedef struct _AssocList AssocList;

typedef int (*CmpFunc)(void *, void *);
typedef void (*ForeachFunc)(void *, void *);
typedef void (*DestroyFunc)(void *, void *);

AssocList * alist_create(CmpFunc cmp, DestroyFunc destroy_entry);
void alist_destroy(AssocList *alist);

/* Value cannot be NULL. */
void alist_put(AssocList *alist, void *key, void *value);

/* Returns NULL if key not found. */
void* alist_get(AssocList *alist, void *key);

void alist_foreach(AssocList *alist, ForeachFunc f);