#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void compute_accelerations(int num_cars, double* input_matrix, int* output_results);

int main() {
    int num_cars = 1000;
    int num_runs = 30;
    int i, j;

    double* input_matrix = (double*)malloc(num_cars * 3 * sizeof(double));
    int* output_results = (int*)malloc(num_cars * sizeof(int));

    if (!input_matrix || !output_results) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < num_cars; i++) {
        input_matrix[i * 3] = 30.0;
        input_matrix[i * 3 + 1] = 160.7;
        input_matrix[i * 3 + 2] = 7.8;
    }

    double total_time = 0.0;

    for (j = 0; j < num_runs; j++) {
        clock_t start = clock();
        compute_accelerations(num_cars, input_matrix, output_results);
        clock_t end = clock();
        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }

    double average_time = total_time / num_runs;

    printf("Accelerations (m/s^2):\n");
    for (i = 0; i < num_cars; i++) {
        if (output_results[i] == -1) {
            printf("Car %d: Overflow detected\n", i + 1);
        } else {
            printf("Car %d: %d\n", i + 1, output_results[i]);
        }
    }

    printf("Average execution time: %.5f seconds\n", average_time);

    free(input_matrix);
    free(output_results);

    return 0;
}
