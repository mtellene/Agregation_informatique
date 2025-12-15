#ifndef ENTRY_H
#define ENTRY_H

typedef struct Entry{
	char *key;
	int val;
	struct Entry *next;
} entry;

#endif

