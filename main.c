#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

/*int countRows(const char *filename) {
    FILE *file = fopen(filename, "r");  // Open the file for reading
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return -1;
    }

    int count = 0;
    int num1, num2;

    // Count the number of lines by reading two integers per line
    while (fscanf(file, "%d %d", &num1, &num2) == 2) {
        count++;
    }

    fclose(file);  // Close the file
    return count;
}*/

void splitLists(int arr[][2], int size, int list1[], int list2[]) {
    for (int i = 0; i < size; i++) {
        list1[i] = arr[i][0];
        list2[i] = arr[i][1];
    }
}

void printList(int list[], int size, const char *name) {
    printf("%s: ", name);
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
/* void printAbsoluteDifferences(int list1[], int list2[], int size) {
    printf("Absolute Differences: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", abs(list1[i] - list2[i])); // abs() ensures non-negative differences
    }
    printf("\n");

 }*/

 int sumAbsoluteDifferences(int list1[], int list2[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += abs(list1[i] - list2[i]); // Compute absolute difference and add to sum
    }
    return sum;
 }
int main() {
    FILE *file = fopen("input.txt", "r");  // Open file for reading
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    int numbers[SIZE][2];
    int i = 0;

    // Read file line by line
    while (i < SIZE && fscanf(file, "%d %d", &numbers[i][0], &numbers[i][1]) == 2) {
        i++;
    }

    fclose(file); // Close file after reading

    int list1[SIZE], list2[SIZE];
    splitLists(numbers, SIZE, list1, list2);

   /* printList(list1, SIZE, "List 1");
    printList(list2, SIZE, "List 2");*/

     int size = sizeof(list1) / sizeof(list1[0]); // Get size of list1

    // Sort both lists
    qsort(list1, size, sizeof(int), compare);
    qsort(list2, size, sizeof(int), compare);

    // Print sorted lists
   /* printf("Sorted Lists:\n");
    printList(list1, size, "List 1");
    printList(list2, size, "List 2"); */

    // printAbsoluteDifferences(list1, list2, size);//
     int totalDifference = sumAbsoluteDifferences(list1, list2, size);
    printf("Sum of Absolute Differences: %d\n", totalDifference);



  return 0;
}



/* #include <stdio.h>

int countRows(const char *filename) {
    FILE *file = fopen(filename, "r");  // Open the file for reading
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return -1;
    }

    int count = 0;
    int num1, num2;

    // Count the number of lines by reading two integers per line
    while (fscanf(file, "%d %d", &num1, &num2) == 2) {
        count++;
    }

    fclose(file);  // Close the file
    return count;
}

int main() {
    const char *filename = "input.txt";  // File name
    int rowCount = countRows(filename);

    if (rowCount >= 0) {
        printf("Number of rows in file: %d\n", rowCount);
    }

    return 0;
} */
