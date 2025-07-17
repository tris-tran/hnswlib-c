#include <stdio.h>
#include "../hnsw_c.h"

int main() {
    
    printf("Starting...\n");
    hnsw_index_t index = hnsw_create_new_index("COSINE", 4);
    if (index == NULL) {
        printf("ERROR: Creating index\n");
        return -1;
    }
    printf("Index created...\n");

    int err = hnws_set_ef(index, 0);
    if (index == NULL) {
        printf("ERROR: set ef (%d)\n", err);
        return -1;
    }
    printf("EF setted...\n");


    err = hnws_init_new_index(index, 10, 16, 200, 100);
    if (err != 0) {
        printf("Failed to init the index (%d)...\n", err);
        return -1;
    }
    printf("Index initialized...\n");
    float vec[4] = {0.1f, 0.2f, 0.3f, 0.4f};

    err = hnws_add_item_to_index(vec, 0, 1, index);
    if (err != 0) {
        printf("Failed to add new item (%d)...\n", err);
        return -1;
    }
    printf("Added one item...\n");

    err = hnws_clear_index(index);
    if (err != 0) {
        printf("Error while cleaning up (%d)...", err);
    }
    printf("Everything cleaned up...");
    return 0;
}
