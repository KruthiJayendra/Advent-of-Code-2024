int countRows(const char *filename) {
    FILE *file = fopen(filename, "r");
    int num1, num2, rowCount = 0;
    while (fscanf(file, "%d %d", &num1, &num2) == 2) {
        rowCount++;
    }
    fclose(file);
    return rowCount;
}




int **storeNumbers(char *filename, int rowCount) {
    FILE *file = fopen(filename, "r");
    int **numbers = malloc(rowCount * sizeof(int *));
    for (int i = 0; i < rowCount; i++) {
        numbers[i] = malloc(2 * sizeof(int));

        fscanf(file, "%d %d", &numbers[i][0], &numbers[i][1]);
    }

    fclose(file);
    return numbers;

}

void splitLists(int **numbers, int rowCount, int *list1, int *list2) {
    for (int i = 0; i < rowCount; i++) {
        list1[i] = numbers[i][0];
        list2[i] = numbers[i][1];
    }
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);  
}


void sortList(int *list, int size) {
    qsort(list, size, sizeof(int), compare);


int sumAbsoluteDifferences(int *list1, int *list2, int size) {
 int sum = 0;
 for (int i = 0; i < size; i++) {
    sum += abs(list1[i] - list2[i]);
    }
    return sum;
}

void printList(char *name, int *list, int size) {
    printf("%s: ", name);
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

/*void printNumbers(int **numbers, int rowCount) {
    printf("Stored Numbers:\n");
    for (int i = 0; i < rowCount; i++) {
        printf("%d %d\n", numbers[i][0], numbers[i][1]);
    }
}*/

int main() {}
    const char *filename = "input.txt";


    int rowCount = countRows(filename);


    int **numbers = storeNumbers(filename, rowCount);
    int *list1 = malloc(rowCount * sizeof(int));
    int *list2 = malloc(rowCount * sizeof(int));

    splitLists(numbers, rowCount, list1, list2);
    sortList(list1, rowCount);
    sortList(list2, rowCount);

    int absDiffSum = sumAbsoluteDifferences(list1, list2, rowCount);
    printf("Sum of Absolute Differences: %d\n", absDiffSum);

    printList("List 1", list1, rowCount);
    printList("List 2", list2, rowCount);


  return 0;
}

