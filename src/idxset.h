#ifndef fooidxsethfoo
#define fooidxsethfoo

#include <inttypes.h>

#define IDXSET_INVALID ((uint32_t) -1)

struct idxset;

struct idxset* idxset_new(unsigned (*hash_func) (void *p), int (*compare_func) (void*a, void*b));
void idxset_free(struct idxset *s, void (*free_func) (void *p, void *userdata), void *userdata);

int idxset_put(struct idxset*s, void *p, uint32_t *index);

void* idxset_get_by_index(struct idxset*s, uint32_t index);
void* idxset_get_by_data(struct idxset*s, void *p, uint32_t *index);

void* idxset_remove_by_index(struct idxset*s, uint32_t index);
void* idxset_remove_by_data(struct idxset*s, void *p, uint32_t *index);

void* idxset_rrobin(struct idxset *s, uint32_t *index);

int idxset_foreach(struct idxset*s, int (*func)(void *p, uint32_t index, int *del, void*userdata), void *userdata);

unsigned idxset_ncontents(struct idxset*s);
int idxset_isempty(struct idxset *s);

#endif
