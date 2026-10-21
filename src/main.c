#include "tiles.h"
#include "defaults.h"
#include "canvas.h"
#include <stdio.h>

void test_canvas() {
    printf("Running Canvas tests...\n");
    print_canvas();
    init_canvas(WIDTH, HEIGHT);
    print_canvas();
    init_canvas(WIDTH, HEIGHT);
    destroy_canvas();
    print_canvas();
    printf("Canvas tests completed\n-----\n\n");
}

int run_tests() {
    
    test_canvas();

}

int main() {
    printf("DEBUG: program start\n");
    
    run_tests();

    return 0;   /* exit successfully */
}