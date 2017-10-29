# File-indexer

2017 Unique Studio lab assignment 1

A simple file indexer.

## Usage

### To make index for a dir.

```
./make_index [path]
```

The data will be saved in a hidden file named `.index.dat`

### Do efficent searching in this file

```
./indexed_search .index.dat [a world]
```

The word should only contain number, letter and underline.

## Feature

Using Multi - threaded programming method to increase the efficiency.

Using Queue and Hash table, easily saving and searching words.

## Example

```shell
sh$./make_index /usr/include
Done. Used 8.546137s
Data saved to .index.dat
sh$./indexed_search .index.dat sha256
Searching in .index.dat
File Numes:39968
/usr/include/openssl-1.0/openssl/obj_mac.h:4
/usr/include/openssl/obj_mac.h:4
/usr/include/nettle/hmac.h:1
/usr/include/libcryptsetup.h:1
/usr/include/ostree-1/ostree-core.h:3
/usr/include/ostree-1/ostree-repo.h:4
/usr/include/autoopts/usage-txt.h:1
/usr/include/autoopts/options.h:1
/usr/include/mbedtls/entropy.h:1
/usr/include/mbedtls/ssl_internal.h:1
/usr/include/mbedtls/sha256.h:1
/usr/include/mbedtls/config.h:1
/usr/include/mbedtls/compat-1.3.h:1
/usr/include/ext2fs/ext2fs.h:1
Done. Used 0.262550s
```
