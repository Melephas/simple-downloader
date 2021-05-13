#include "libsd.h"

#include <stdlib.h>

#include <sys/socket.h>

/* Definition of the sd module
typedef struct {
    sd_stream* (*new_stream)(char* address);
    void (*destroy_stream)(sd_stream* stream);
    uint8_t (*read_byte_from_stream)(sd_stream* stream);
    void (*fill_buffer_from_stream)(sd_stream* stream, void* buffer, uint64_t length);
} sd_m;
*/

struct sd_stream_s {
    const char* address;
    uint16_t port;
    int32_t socket_fd;
};

// Module functions
static uint8_t get_byte();

// Module API functions
sd_m* sd_init_module() {
    sd_m* module = malloc(sizeof(sd_m));
    module->get_byte = get_byte;
    module->get_word = get_word;

    return module;
}

void sd_destroy_module(sd_m* module) {
    free(module);
}

static uint8_t get_byte() {
    return 8;
}

static uint64_t get_word() {
    return 64;
}
