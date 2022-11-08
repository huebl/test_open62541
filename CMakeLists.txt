cmake_minimum_required(VERSION 3.1...3.12)
project (myserver)

option(USE_OPENSSL "Use openssl library" OFF)
option(USE_MBEDTLS "Use mbedtsl library" OFF)

MESSAGE(STATUS "USE_OPENSSL: ${USE_OPENSSL}")
MESSAGE(STATUS "USE_MBEDTLS: ${USE_MBEDTLS}")

add_executable(
    myserver
    server.c
)

add_executable(
    myclient
    client.c
)

if(USE_OPENSSL)
    set(
        ENCRYPTION_LIB
        /opt/openssl/lib/libcrypto.a 
        /opt/openssl/lib/libssl.a
    )
elseif(USE_MBEDTLS)
    set(
        ENCRYPTION_LIB
        mbedcrypto
        /lib/x86_64-linux-gnu/libmbedtls.a
        /lib/x86_64-linux-gnu/libmbedx509.a
        /lib/x86_64-linux-gnu/libmbedcrypto.a
    )
endif()

target_link_libraries(
    myserver
	/usr/local/lib/libopen62541.a
	${ENCRYPTION_LIB}
)

target_link_libraries(
    myclient
	/usr/local/lib/libopen62541.a
	${ENCRYPTION_LIB}
)
