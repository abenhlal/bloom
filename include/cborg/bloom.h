#ifndef _CBORG_BLOOM_H
#define _CBORG_BLOOM_H

#include <stdbool.h>
#include <stdlib.h>
#include <cborg/bitset.h>

/**
 *  TODO: see the document below to make the bloom filter more efficient with
 * two hash functions
 * - link: https://www.eecs.harvard.edu/~michaelm/postscripts/rsa2008.pdf
 */

typedef struct bloom_filter_t {
  uint64_t (*h1)(const void *, size_t);
  uint64_t (*h2)(const void *, size_t);
  size_t len;
  bitset_t *bs;
} bloom_filter_t;

/**
 * Allocate new bloom filter (need bloom_delete after use)
 * @param h1 Hash function 1
 * @param h2 Hash function 2
 * @param len Length of bloom array
 * @return Pointer of bloom filter structure
 */ 
bloom_filter_t *cb_bloom_new(uint64_t (*h1)(const void *, size_t),
                          uint64_t (*h2)(const void *, size_t), size_t len);

void cb_bloom_delete(bloom_filter_t **bloom);

void cb_bloom_insert(bloom_filter_t *bloom, void *buf, size_t len);

void cb_bloom_intersection();

bool cb_bloom_get(bloom_filter_t *bloom, void *buf, size_t len);

#endif
