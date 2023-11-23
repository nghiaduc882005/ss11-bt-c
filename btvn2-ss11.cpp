#include <stdio.h>
void printMatrix(int matrix[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}
void sortArrayAscending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void sortMatrixByRow(int matrix[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        sortArrayAscending(matrix[i], cols);
    }
}
void sortMatrixByColumn(int matrix[][100], int rows, int cols) {
    for (int j = 0; j < cols; j++) {
        int column[100];
        for (int i = 0; i < rows; i++) {
            column[i] = matrix[i][j];
        }
        sortArrayAscending(column, rows);
        for (int i = 0; i < rows; i++) {
            matrix[i][j] = column[rows - i - 1];
        }
    }
}

int main() {
    int rows, cols;
    printf("Nhap so dong cua mang: ");
    scanf("%d", &rows);
    printf("Nhap so cot cua mang: ");
    scanf("%d", &cols);
    int matrix[100][100];
    printf("Nhap gia tri cho cac phan tu cua mang:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    int choice;
    do {
        // In menu
        printf("\nMENU\n");
        printf("1. In gia tri mang theo ma tran\n");
        printf("2. Sap xep mang theo dong tang dan\n");
        printf("3. Sap xep mang theo cot giam dan\n");
        printf("4. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Gia tri cua mang theo ma tran:\n");
                printMatrix(matrix, rows, cols);
                break;
            case 2:
                sortMatrixByRow(matrix, rows, cols);
                printf("Mang sau khi sap xep theo dong tang dan:\n");
                printMatrix(matrix, rows, cols);
                break;

            case 3:
                sortMatrixByColumn(matrix, rows, cols);
                printf("Mang sau khi sap xep theo cot giam dan:\n");
                printMatrix(matrix, rows, cols);
                break;

            case 4:
                printf("Ket thuc chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}

