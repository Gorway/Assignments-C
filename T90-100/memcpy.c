#include <stddef.h>

void *my_memcpy(void *dest, const void *src, size_t n) {
   
   char *char_dest = (char *)dest;          
   
   const char *char_src = (const char *)src; 

    for (size_t i = 0; i < n; ++i) {
        char_dest[i] = char_src[i];  
    }

    return dest; 
}

