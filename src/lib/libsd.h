#pragma once

#include <stdint.h>


typedef struct sd_stream_s sd_stream;

typedef struct {
    sd_stream* (*new_stream)(char* address);
    void (*destroy_stream)(sd_stream* stream);
    uint8_t (*read_byte_from_stream)(sd_stream* stream);
    void (*fill_buffer_from_stream)(sd_stream* stream, void* buffer, uint64_t length);
} sd_m;

sd_m* sd_init_module();
void sd_destroy_module(sd_m* module);
