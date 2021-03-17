# bloom

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
$ gcc example.c -o example.bin -L/usr/local/lib/cborg -lbloom -lbitset -lhash
$ ./example.bin
```

```C
#include <stdio.h>
#include <cborg/bloom.h>
#include <cborg/hash.h>

int main() {
  bloom_filter_t *b1 = bloom_new(hash_fnv1a, hash_murmur2_64a, 1000);
  bloom_insert(b1, "hello", 6);
  bloom_insert(b1, "hello world!", 12);
  bloom_delete(&b1);
  return 0;
}

```

## License

[MIT](LICENSE)