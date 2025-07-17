#ifndef HNSW_C_H
#define HNSW_C_H

#ifdef __cplusplus
extern "C" {
#endif

#define RESULT_SUCCESSFUL 0
#define RESULT_EXCEPTION_THROWN 1
#define RESULT_INDEX_ALREADY_INITIALIZED 2
#define RESULT_QUERY_CANNOT_RETURN 3
#define RESULT_ITEM_CANNOT_BE_INSERTED_INTO_THE_VECTOR_SPACE 4
#define RESULT_ONCE_INDEX_IS_CLEARED_IT_CANNOT_BE_REUSED 5
#define RESULT_GET_DATA_FAILED 6
#define RESULT_ID_NOT_IN_INDEX 7
#define RESULT_INDEX_NOT_INITIALIZED 8


typedef void* hnsw_index_t;

hnsw_index_t hnsw_create_new_index(char* spaceName,
				   int dimension);
int hnws_init_new_index(hnsw_index_t index,
			int maxNumberOfElements,
			int M,
			int efConstruction,
			int randomSeed);

int hnws_set_ef(hnsw_index_t index,
		int ef);

int hnws_clear_index(hnsw_index_t idx);

int hnws_add_item_to_index(float* item,
			   int size,
			   int normalized,
			   int label,
			   hnsw_index_t index);

void hnsw_add_point(hnsw_index_t index, const float* vector, int label);
  
int hnws_knn_query(hnsw_index_t index,
		   float* input,
		   int normalized,
		   int k,
		   int* indices /* output */,
		   float* coefficients /* output */);

int hnws_save_index(hnsw_index_t index, char* path);
int hnws_load_index(hnsw_index_t idx, size_t maxNumberOfElements, char* path);

#ifdef __cplusplus
}
#endif

#endif // HNSW_C_H
