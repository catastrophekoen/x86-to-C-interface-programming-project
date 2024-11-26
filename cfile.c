#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void compute_accelerations(int num_cars, double* input_matrix, int* output_results);

int main() {
    int num_cars = 10000;  
    int i;

    // Allocate memory for the input matrix and output results
    double* input_matrix = (double*)malloc(num_cars * 3 * sizeof(double));
    int* output_results = (int*)malloc(num_cars * sizeof(int));

    if (!input_matrix || !output_results) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    srand(time(NULL));

    for (i = 0; i < num_cars; i++) {
        
        // Random Initial Velocity (0 to 100 km/h)
        input_matrix[i * 3] = (rand() % 101);
        // Random Final Velocity (50 to 250 km/h)
        input_matrix[i * 3 + 1] = (rand() % 201) + 50;
        // Random Time (1 to 10 seconds)
        input_matrix[i * 3 + 2] = (rand() % 10) + 1;
        
    }

    clock_t start = clock();
    compute_accelerations(num_cars, input_matrix, output_results);
    clock_t end = clock();

    // Display results (only for the first 10 cars to avoid cluttering the output)
    printf("First 10 Car Accelerations (m/s^2):\n");
    for (i = 0; i < 10 && i < num_cars; i++) {
        printf("Car %d: %d\n", i + 1, output_results[i]);
    }

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time for %d cars: %.6f seconds\n", num_cars, time_spent);

    free(input_matrix);
    free(output_results);

    return 0;
}
