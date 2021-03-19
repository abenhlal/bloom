#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

#include "cborg/bloom.h"
#include "cborg/hash.h"

void test_bloom_new() {
  bloom_filter_t *b1 = bloom_new(hash_fnv1a, hash_murmur2_64a, 1000);
  assert(b1->len == 1000);
  bloom_delete(&b1);

  bloom_filter_t *b2 = bloom_new(hash_fnv1a, hash_murmur2_64a, 5);
  assert(b2->len == 5);
  bloom_delete(&b2);
}

void test_bloom_delete() {
  bloom_filter_t *b1 = bloom_new(hash_fnv1a, hash_murmur2_64a, 1000);
  assert(b1 != NULL);
  bloom_delete(&b1);
  assert(b1 == NULL);

  bloom_filter_t *b2 = bloom_new(hash_fnv1a, hash_murmur2_64a, 5);
  assert(b2 != NULL);
  bloom_delete(&b2);
  assert(b2 == NULL);
}

void test_bloom_insert() {
  bloom_filter_t *b1 = bloom_new(hash_fnv1a, hash_murmur2_64a, 1000);
  bloom_insert(b1, "hello", 6);
  bloom_insert(b1, "hello world!", 12);
  // TODO: Test hash equal true in b1->array
  bloom_delete(&b1);
}

void test_bloom_get() {
  bloom_filter_t *b1 = bloom_new(hash_fnv1a, hash_murmur2_64a, 1000);
  bloom_insert(b1, "hello", 6);
  bloom_insert(b1, "hello world!", 12);
  assert(bloom_get(b1, "hello", 6) == true);
  assert(bloom_get(b1, "hello world!", 12) == true);
  bloom_delete(&b1);
}

int main() {
  test_bloom_new();
  test_bloom_delete();
  test_bloom_insert();
  test_bloom_get();

  return EXIT_SUCCESS;
}
