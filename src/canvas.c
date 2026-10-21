#include <stdlib.h>
#include <stdio.h>

int* canvas;
int width = 0;
int height = 0;

void set_cell_contents(int xOffset, int yOffset, int contents) {
    int offset = (yOffset * width) + width;
    *(canvas+offset) = contents;
    
}

void init_canvas(int w, int h) {
    if(canvas == NULL) {
        width = w;
        height = h;
        canvas = malloc(width*height*sizeof(int));  /* allocate space to hold the canvas array */
        /* initialise canvas to -1 in each cell */
        for(int y = 0; y < height; y++) {   /* for each row */
            for(int x = 0; x < width; x++) {
                set_cell_contents(x, y, -1);
            }
        }
    } else {
        fprintf(stderr, "ERROR: Canvas already initialised!\n");
    }
}

void destroy_canvas() {
    if(canvas != NULL) {
        free(canvas);
        canvas = NULL;
    }
}

void print_position(int xOffset, int yOffset) {
    int offset = (yOffset * width) + width;
    int contents = *(canvas+offset);
    printf("%d ", contents);
}

void print_canvas() {
    if(canvas == NULL) {
        printf("DEBUG: canvas not initialised!\n");
    } else {
        printf("DEBUG: print canvas: width=%d, height=%d\n", width, height);
        for(int y = 0; y < height; y++) {   /* for each row */
            for(int x = 0; x < width; x++) {
                print_position(x, y);
            }
            printf("\n");
        }
    }
}