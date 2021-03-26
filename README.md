# libcborg-bloom

## Build and Install

```sh
$ git clone --recurse-submodules https://github.com/abenhlal/bloom.git
$ cd bloom
$ mkdir build
$ cd build
$ cmake ..
$ make
$ make test
$ sudo make install
```

## Uninstall

```sh
$ sudo make uninstall
```

## Usage and build

```sh
$ gcc example.c -o example.bin -L/usr/local/lib/cborg -lcborg-bloom -lcborg-bitset -lcborg-hash
$ ./example.bin
```

```C
#include <stdio.h>
#include <cborg/bloom.h>
#include <cborg/hash.h>

int main() {
  bloom_filter_t *b1 = cb_bloom_new(cb_hash_fnv1a, cb_hash_murmur2_64a, 1000);
  cb_bloom_insert(b1, "hello", 6);
  cb_bloom_insert(b1, "hello world!", 12);
  cb_bloom_delete(&b1);
  return 0;
}

```

## License

[MIT](LICENSE)