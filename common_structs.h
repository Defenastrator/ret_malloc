#ifndef __RET_MALLOC_COMMON_STRUCTURES_H__
#define __RET_MALLOC_COMMON_STRUCTURES_H__
#include <stddef.h>

#define ARCH_ADDRESS_LINES 48
#define POINTER_ALIGNMENT_BITS 3
#define PTR_BITS (sizeof(uintptr_t) * 8)
#define CHUNK_SIZE_BITS (ARCH_ADDRESS_LINES - POINTER_ALIGNMENT_BITS)
#define ALIGNMENT_MASK ((((size_t)1) << POINTER_ALIGNMENT_BITS) - 1)

typedef size_t asize_t: CHUNK_SIZE_BITS;

typedef struct {
	asize_t size;
} footer_t;

typedef struct {
	asize_t size;
	unsigned int prev_in_use: 1;
} header_t;

typedef struct {
	footer_t pfoot;
	header_t header;
	union {
		char alloc;
		struct {
			chunk_t * prev;
			chunk_t * next;
		};
	};
	
} chunk_t;

#define MIN_CHUNK_SIZE ((sizeof uintptr_t) * 4)

#endif