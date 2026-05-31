#include <stdio.h>

#define LEFT -1
#define RIGHT 1

void printPermutation(int permutation[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", permutation[i]);
    printf("\n");
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int permutation[n], dir[n];

    for (int i = 0; i < n; i++) {
        permutation[i] = i + 1;
        dir[i] = LEFT;
    }

    printPermutation(permutation, n);

    while (1) {
        int largestMobileIndex = -1;

        for (int i = 0; i < n; i++) {
            int next = i + dir[i];

            if (next >= 0 && next < n &&
                permutation[i] > permutation[next]) {

                if (largestMobileIndex == -1 ||
                    permutation[i] > permutation[largestMobileIndex]) {
                    largestMobileIndex = i;
                }
            }
        }

        if (largestMobileIndex == -1)
            break;

        int swapIndex = largestMobileIndex + dir[largestMobileIndex];

        int temp = permutation[largestMobileIndex];
        permutation[largestMobileIndex] = permutation[swapIndex];
        permutation[swapIndex] = temp;

        temp = dir[largestMobileIndex];
        dir[largestMobileIndex] = dir[swapIndex];
        dir[swapIndex] = temp;

        int mobileValue = permutation[swapIndex];

        for (int i = 0; i < n; i++) {
            if (permutation[i] > mobileValue)
                dir[i] = -dir[i];
        }

        printPermutation(permutation, n);
    }

    return 0;
}
