#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

float * DataBase(char *data, int* x_pos, int* y_pos); 
void PrintDataBase(float arr[], int size, int total_size); 
void Swap(float* x_pos, float* y_pos); 
void SelectionSort(float arr[], int n); 
float median(float arr[], int size);
double mean(float arr[], int size); 
double stddev(float arr[], int size); 

int main(int argc, char *argv[]) { 
    
    // Argument checking 
    if(argc != 2) { 
        printf("Usage: %s <filename>\n", argv[0]); 
    } else { 
        
        int data_count = 0; 
        int array_size = 20; 
        float *dataset; 

        dataset = DataBase(argv[1], &data_count, &array_size); 
        SelectionSort(dataset, data_count);
        PrintDataBase(dataset, data_count, array_size);
    }
}

float *DataBase(char* data_file, int* data_count, int* array_size) { 
    int n = 20; 

    float *dataset = (float*)malloc(n *sizeof(float)); 

    // Memory check
    if(dataset == NULL) { 
        printf("Unable to allocate memory.\n"); 
        exit(0); 
    }

    int counter = 0; 
    float data = 0; 
    FILE *file; 
    file = fopen(data_file, "r"); 

    char buffer[100]; 
    while(fgets(buffer, sizeof(buffer), file)) {
        data = strtof(buffer, NULL); 
        dataset[counter] = data;
        counter++;

        if(counter == n) {
            n = n*2; 
            float* dataset_temp = (float*)malloc(n *sizeof(float));
            
            // Memory Check 
            if(dataset_temp == NULL) {
                printf("Unable to allocate memory.\n");
            }

            memcpy(dataset_temp, dataset, n*sizeof(float)); 
            free(dataset);
            dataset = (float*)malloc(n * sizeof(float));
            memcpy(dataset, dataset_temp, n * sizeof(float));
            free(dataset_temp);
        }
    }

    if(feof(file)) { 
        fclose(file); 
    }

    *array_size = n;
    *data_count = counter; 
    return dataset; 
}

void PrintDataBase(float arr[], int n, int total_size) { 
        printf("\nResults:\n");
        printf("-----------\n");
        printf("Num Values:\t\t%d\n", n);
        printf("Mean\t\t\t%lf\n", mean(arr, n));
        printf("Median:\t\t\t%f\n", median(arr, n));
        printf("Stddev:\t\t\t%lf\n", stddev(arr, n));
        printf("Unused Array Capacity:\t%d\n\n", (total_size-n));}

void Swap(float *x_pos, float *y_pos) { 
    float temp = *x_pos; 
    *x_pos = *y_pos;
    *y_pos = temp; 
}

void SelectionSort(float arr[], int n) { 
    int i, j, min_idx; 
    
    for(i = 0; i < n - 1; i++) { 
        
        min_idx = i; 

        for(j = i + 1; j < n; j++) { 
            if(arr[j] < arr[min_idx]) { 
                min_idx = j;
            }
        } Swap(&arr[min_idx], &arr[i]); 
    }
}

float median(float arr[], int size) {
    
    float median = 0; 

    if(size % 2 == 0) { 
        median = (arr[(size-1)/2] + arr[size/2])/2.0;
    } else { 
        median = arr[size/2];
    }
    return median; 
}

double mean(float arr[], int size) { 
    int counter; 
    float sum; 
    double avg;

    sum = avg = 0; 

    for(counter = 0; counter < size; counter++) { 
        sum = sum + arr[counter];
    }

    avg = (double)sum / size; 

    return avg; 
}

double stddev(float arr[], int size) { 
    int counter; 
//    int i;
//    float sum = 0.0;
    double avg;
    double stddev = 0.0;
    
    avg = mean(arr, size); 

    for(counter = 0; counter < size; counter++) {
        stddev += pow(arr[counter] - avg, 2); 
    }
    

    return (double) sqrt(stddev/size); 
}
