#include <cborg/bloom.h>

bloom_filter_t *cb_bloom_new(uint64_t (*h1)(const void *, size_t),
                          uint64_t (*h2)(const void *, size_t), size_t len) {
  bloom_filter_t *bloom = (bloom_filter_t *)malloc(sizeof(bloom_filter_t));
  bloom->bs = cb_bitset_new(len);
  bloom->len = len;
  bloom->h1 = h1;
  bloom->h2 = h2;
  return bloom;
}

void cb_bloom_delete(bloom_filter_t **bloom) {
  cb_bitset_delete((*bloom)->bs);
  free(*bloom);
  *bloom = NULL;
}

void cb_bloom_insert(bloom_filter_t *bloom, void *buf, size_t len) {
  cb_bitset_set(bloom->bs, bloom->h1(buf, len) % bloom->len, true);
  cb_bitset_set(bloom->bs, bloom->h2(buf, len) % bloom->len, true);
}

bool cb_bloom_get(bloom_filter_t *bloom, void *buf, size_t len) {
  return cb_bitset_test(bloom->bs, bloom->h1(buf, len) % bloom->len) &&
         cb_bitset_test(bloom->bs, bloom->h2(buf, len) % bloom->len);
}
