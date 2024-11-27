#include <stdio.h>
#include <stdlib.h>

extern void compute_accelerations(int num_cars, double* input_matrix, int* output_results);

int main() {
    int num_cars;
    int i;
    
    //printf("Enter the number of cars: ");
    scanf("%d", &num_cars);

    // Allocate memory for the input matrix and output results
    double* input_matrix = (double*)malloc(num_cars * 3 * sizeof(double));
    int* output_results = (int*)malloc(num_cars * sizeof(int));

    if (!input_matrix || !output_results) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    //printf("Enter the matrix values (Initial Velocity, Final Velocity, Time):\n");
    for (i = 0; i < num_cars; i++) {
        //printf("Car %d: ", i + 1);
        scanf("%lf,%lf,%lf", &input_matrix[i * 3], &input_matrix[i * 3 + 1], &input_matrix[i * 3 + 2]);
    }

    compute_accelerations(num_cars, input_matrix, output_results);

    // Display results
    printf("Accelerations (m/s^2):\n");
    for (i = 0; i < num_cars; i++) {
            //printf("Car %d: %d\n", i + 1, output_results[i]);
            printf("%d\n", output_results[i]);
    }

    // Free allocated memory
    free(input_matrix);
    free(output_results);

    return 0;
}
