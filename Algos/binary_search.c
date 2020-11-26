#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<stdbool.h>

bool linearSearch(int * arr, int size, int target) {
	bool flag = false;
	for(int i = 0; i < size; i++) {
		if(arr[i] == target) {
			flag = true;
			break;
		}
	}
	return flag;
}

int find(int * arr, int target, int size) {
   
   int lowerBound = 0;
   int upperBound = size - 1;
   int midPoint = -1;
   int comparisons = 0;      
   int index = -1;
	
   while(lowerBound <= upperBound) {
      printf("Comparison %d\n" , (comparisons +1) );
      printf("lowerBound : %d, intArray[%d] = %d\n",lowerBound,lowerBound, arr[lowerBound]);
      printf("upperBound : %d, intArray[%d] = %d\n",upperBound,upperBound, arr[upperBound]);
      comparisons++;
		
      // compute the mid point
      // midPoint = (lowerBound + upperBound) / 2;
      midPoint = lowerBound + (upperBound - lowerBound) / 2;	
		
      // data found
      if(arr[midPoint] == target) {
         index = midPoint;
         break;
      } else {
         // if data is larger 
         if(arr[midPoint] < target) {
            // data is in upper half
            lowerBound = midPoint + 1;
         }
         // data is smaller 
         else {
            // data is in lower half 
            upperBound = midPoint -1;
         }
      }               
   }
   printf("Total comparisons made: %d" , comparisons);
   return index;
}

void bubbleSort(int * arr, int size) {
	// O(n^2) - super bad
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size - i - 1; j++) {
			if(arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void merge(int * arr, int start, int mid, int end) {
	
	int temp[end - start + 1];
	
	int i = start;
	int j = mid + 1;
	int k = 0;

	while(i <= mid && j <= end) {
		if(arr[i] <= arr[j]) {
			temp[k] = arr[i];
			k += 1; 
			i += 1;
		}
		else {
			temp[k] = arr[j];
			k += 1; 
			j += 1;
		}
	}

	// add elements left in the first interval 
	while(i <= mid) {
		temp[k] = arr[i];
		k += 1; 
		i += 1;
	}

	// add elements left in the second interval 
	while(j <= end) {
		temp[k] = arr[j];
		k += 1; 
		j += 1;
	}

	// copy temp to original interval
	for(i = start; i <= end; i += 1) {
		arr[i] = temp[i - start];
	}

}

void mergeSort(int * arr, int start, int end) {
	// O(n log n)
	if(start < end) {
		int mid = (start + end) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

void printArray(int * arr, int size) {
	for(int i = 0; i < size; i++) {
		printf("%d\n" , arr[i]);
	}
}

int main(void) {

	int SIZE = 0;

	printf("Enter size of array: ");
	scanf("%d", &SIZE);

	int  * nums = malloc(SIZE * sizeof(int));

	srand(time(0));

	int upper = 0;
	int lower = 0;

	printf("Enter upper bound: ");
	scanf("%d" , &upper);

	printf("Enter lower bound: ");
	scanf("%d", &lower);

	for(int i = 0; i < SIZE; i++) {
		nums[i] = (rand() % (upper - lower + 1)) + lower;
	}

	mergeSort(nums, 0, SIZE);
	printArray(nums, SIZE);

	int target = 0;
	printf("Enter target value to find: ");
	scanf("%d", &target);

	int location = find(nums, target, SIZE);
	if(location != -1)
      printf("\nElement found at location: %d\n" ,(location+1));
    else
      printf("\nElement not found.\n");
	
	mergeSort(nums , 0, SIZE);
	//bubbleSort(nums, SIZE);
	
	//printArray(nums, SIZE);

	// bool found = linearSearch(nums, SIZE, 41256);
	// found ? printf("Found\n") : printf("Not found\n");

	free(nums);

}
