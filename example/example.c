#include <stdio.h>
#include "../hnsw_c.h"

int main() {
    printf("DEBUG: Starting\n");
    hnsw_index_t index = hnsw_create_new_index("COSINE", 4);
    if (index == NULL) {
        printf("DEBUG: ERROR: Creating index\n");
        return -1;
    }
    printf("DEBUG: Index created\n");

    int err = hnws_set_ef(index, 1);
    if (index == NULL) {
        printf("ERROR: set ef (%d)\n", err);
        return -1;
    }
    printf("DEBUG: EF setted\n");

    err = hnws_init_new_index(index, 10, 16, 200, 100);
    if (err != 0) {
        printf("ERROR: Failed to init the index (%d)\n", err);
        return -1;
    }
    printf("DEBUG: Index initialized\n");
    float vec[4] = {0.1f, 0.2f, 0.3f, 0.4f};

    err = hnws_add_item_to_index(vec, 4, 0, 8, index);
    if (err != 0) {
        printf("ERROR: Failed to add new item (%d)\n", err);
        return -1;
    }
    printf("DEBUG: Added one item\n");

    float qvec[4] = {-2.0f, 1.0f, 0.0f, 0.0f};
    int result[1] = { 9 };
    float coefficients[1] = { 9.0f };
    err = hnws_knn_query(index, qvec, 0, 1, result, coefficients);
    if (err != 0) {
      printf("ERROR: Error while doing query\n");
      return -1;
    }
    printf("DEBUG: Query (%d) coeficient (%f)\n", result[0], coefficients[0]);

    char* path = "/home/eochoa/Borrar/hnsw_index";
    err = hnws_save_index(index, path);
    if (err != 0) {
      printf("ERROR: Error while saving index (%d)\n", err);
    }
    printf("DEBUG: Index saved\n");

    err = hnws_clear_index(index);
    if (err != 0) {
        printf("ERROR: Error while cleaning up (%d)", err);
    }
    printf("DEBUG: Everything cleaned up\n");


    /////LOADING THE INDEX AGAIN

    index = hnsw_create_new_index("COSINE", 4);
    err = hnws_init_new_index(index, 10, 16, 200, 100);
    if (err != 0) {
      printf("ERROR: Failed to init the index (%d)\n", err);
      return -1;
    }
    printf("DEBUG: Index initialized\n");

    err = hnws_load_index(index, 4, path);
    if (err != 0) {
      printf("ERROR: Error loading index (%d)\n", err);
      return -1;
    }
    printf("DEBUG: Index loaded\n");

    err = hnws_set_ef(index, 1);
    if (index == NULL) {
      printf("ERROR: ERROR: set ef (%d)\n", err);
      return -1;
    }
    printf("DEBUG: EF setted\n");
    
    /////INDEX LOADED AND INITIALIZED

    err = hnws_knn_query(index, qvec, 0, 1, result, coefficients);
    if (err != 0) {
      printf("ERROR: Error while doing query (%d)\n", err);
      return -1;
    }
    printf("DEBUG: Query (%d) coeficient (%f)\n", result[0], coefficients[0]);

    return 0;
}
