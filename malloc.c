#include <malloc.h>
#include <stddef.h>

inline chunk_t* to_chunk(void * ptr) {
	return (chunk_t*)(ptr - offsetof(chunk_t, alloc));
}

inline void* from_chunk(chunk_t* chunk) {
	return ((void*)chunk) + offsetof(chunk_t, alloc);
}

inline asize_t to_alloc_size_index(size_t size) {
	size_t aligned = (size + (sizeof header_t) + ALIGNMENT_MASK) & (~ALIGNMENET_MASK);
	return (asize_t)((aligned - MIN_CHUNK_SIZE) >> ALIGNMENT_BITS);
}

inline from_alloc_size_index(asize_t size) {
	return ((size_t)size)<<ALIGNMENT_BITS + MIN_CHUNK_SIZE;
}

void ret_malloc_internal_free(chunk_t* chunk) {

}

chunk_t* ret_malloc_internal_malloc(asize_t size) {

}

chunk_t* ret_malloc_internal_realloc(chunk_t*chunk, asize_t size) {

}

void * malloc(size_t size) {
	return from_chunk(ret_malloc_internal_malloc(to_alloc_size_index(size)));
}

void free(void * ptr) {
	ret_malloc_internal_free(to_chunk(ptr));
}

void * calloc(size_t nitems, size_t size) {
	size_t alloc_size = nitems * size;
	char * ptr = (char*)malloc(alloc_size);
	for(size_t i = 0; i < alloc_size;++i) 
		ptr[i] = 0;
}

void * realloc(void * ptr, size_t size) {
	return from_chunk(ret_malloc_internal_realloc(to_chunk(ptr), to_alloc_size_index(size)));
}asd