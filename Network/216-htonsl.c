#include <stdint.h>

uint16_t my_htons(uint16_t hostshort) {
    #if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        return ((hostshort & 0xFF) << 8) | ((hostshort & 0xFF00) >> 8);
    #else
        return hostshort;
    #endif
}

uint32_t my_htonl(uint32_t hostlong) {
    #if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        return ((hostlong & 0xFF) << 24) | ((hostlong & 0xFF00) << 8) |
               ((hostlong & 0xFF0000) >> 8) | ((hostlong & 0xFF000000) >> 24);
    #else
        return hostlong;
    #endif
}

