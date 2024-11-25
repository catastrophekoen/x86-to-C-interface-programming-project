#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Assembly function prototype
extern void compute_accelerations(int num_cars, double* input_matrix, int* output_results);

int main() {
    int num_cars;
    int i;
    printf("Enter the number of cars: ");
    scanf("%d", &num_cars);

    // Allocate memory for the input matrix and output results
    double* input_matrix = (double*)malloc(num_cars * 3 * sizeof(double));
    int* output_results = (int*)malloc(num_cars * sizeof(int));

    if (!input_matrix || !output_results) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input data for each car
    printf("Enter the matrix values (Initial Velocity, Final Velocity, Time):\n");
    for (i = 0; i < num_cars; i++) {
        printf("Car %d: ", i + 1);
        scanf("%lf,%lf,%lf", &input_matrix[i * 3], &input_matrix[i * 3 + 1], &input_matrix[i * 3 + 2]);
    }

    // Call the assembly function
    clock_t start = clock();
    compute_accelerations(num_cars, input_matrix, output_results);
    clock_t end = clock();

    // Display results
    printf("Accelerations (m/s^2):\n");
    for (i = 0; i < num_cars; i++) {
        if (output_results[i] == -1) { // Sentinel value for overflow
            printf("Car %d: Overflow detected\n", i + 1);
        } else {
            printf("Car %d: %d\n", i + 1, output_results[i]);
        }
    }

    // Display execution time
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time: %.6f seconds\n", time_spent);

    // Free allocated memory
    free(input_matrix);
    free(output_results);

    return 0;
}
