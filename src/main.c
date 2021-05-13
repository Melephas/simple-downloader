#include <stdlib.h>
#include <stdio.h>

#include <libsd.h>


int main(int argc, char** argv) {
    printf("Getting libsd module\n");

    sd_m* module = sd_init_module();

    if (!module) {
        printf("Failed to get libsd module\n");
        exit(EXIT_FAILURE);
    }

    if (module->get_byte() != 8) {
        printf("Error in libsd module (sd::get_byte): invalid return value\n");
        sd_destroy_module(module);
        exit(EXIT_FAILURE);
    }

    if (module->get_word() != 64) {
        printf("Error in libsd module (sd::get_word): invalid return value\n");
        sd_destroy_module(module);
        exit(EXIT_FAILURE);
    }

    printf("All libsd module test successful\n");
    sd_destroy_module(module);
    return EXIT_SUCCESS;
}
