#!/usr/bin
gcc -std=c99 server.c /usr/local/lib/libopen62541.a /opt/openssl/lib/libcrypto.a /opt/openssl/lib/libssl.a -o myServer
