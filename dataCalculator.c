#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Calculate minimum value in the data set */
float findMaximum(float **data, int setIndex, int *size){
    int i = 0;
    float max = *(*(data + setIndex) + 0);

    for(i = 1; i < *size; i++){
   	 if( max < (*(*(data + setIndex) + i)) ){
   		 max = *(*(data + setIndex) + i);
   	 }
    }
    return max;
}

/* Calculate maximum value in the data set */
float findMinimum(float **data, int setIndex, int *size){
    int i = 0;
    float min = *(*(data + setIndex) + 0);

    for(i = 1; i < *size; i++){
   	 if(min > *(*(data + setIndex) + i)){
   		 min = *(*(data + setIndex) + i);
   	 }
    }
    return min;
}

/* Calculate the sum for the data set */
float findSum(float **data, int setIndex, int *size){
    float sum = 0.0;
    int i = 0;
    for(i = 0; i < *size; i++){
   	 sum = sum + *(*(data + setIndex) + i);
    }
    return sum;
}

/* Calculate the average for the data set */
float findAverage(float **data, int setIndex, int *size){
    float sum = 0.0;
    int i = 0;
    float average = 0.0;
    for(i = 0; i < *size;i++){
   	 sum = sum + *(*(data + setIndex) + i);
    }
    average = sum / (*size);
}

/* swap value function */
void swap(float *a, float *b){
    float temp = *a;
    *a = *b;
    *b = temp;
}

/* implement insertion sort algorithm to sort data array */
void insertionSort(float **data, int setIndex, int *size){
    int i = 0;

    /* insert A[i] in A[0...i-1] */
    /* maintain A[0] <= A[1] <= A[2] <=....<=A[i] */
    for(i = 0; i < *size ; i++){
   	 int j = i;

   	 /* insert A[i] to sorted array */
   	 /* A[j-1] > A[j], swap the values */
   	 while(j > 0 &&  *(*(data + setIndex) + j - 1 ) > *(*(data + setIndex) + j) ){
   		 swap( (*(data + setIndex) + j - 1 ) , (*(data + setIndex) + j) );
   		 j = j - 1;
   	 }
    }
    
    /* output the sorted data set */
    printf("The sorted data set is: \n");
    for(i = 0; i < *size; i++){
   	 printf("%.2f\t",*(*(data + setIndex) + i));
    }
    printf("\n");
   	 
}

/* free allocated space for the dynamic data set */
void freeAllocatedMemory(float **data, int size){
    int i = 0;
    for(i = 0; i < size; i++){
   	 free(data[i]);
    }
    free(data);

}

int main(){

    int number = 0; /* the number of data set */
    float **data;    /* initialize 2-D data set array */
    int *sizeOfDataSet, selectIndex; /* the size of sach data size and the selected index of data set */
    int numberOfData = 0; /* the number of elements in the data set */
    int i = 0, j = 0; /* i, j are counters */
    float max = 0, min = 0, sum = 0, average = 0; /* initialize values for min, max, sum and average */
    float value; /* store user's input for each value in the data set */
    int option = 0;    /* user's option */


    /* prompt user to enter the number of data sets */
    while(1){
   	 printf("Please enter the number of data set: \n");
   	 scanf("%d", &number);
   	 if(number > 0){
   		 break;
   	 }else{
   		 printf("Please enter an integer greater than 1\n");
   	 }
    }


    /* allocate memory for the number of data sets */
    data = (float**)malloc(number * sizeof(float*));

    /* check whether the allocation fails or not */
    if(data == 0){
   	 printf("The memory cannot be allocated, the null pointer found!");
   	 free(data); /* free allocated storage */
   	 return 1;
    }

    /* allocate memory for the size of each data set */
    sizeOfDataSet = malloc(number * sizeof(int));
    /* check whether the allocation fails or not */
    if(sizeOfDataSet == 0){
   	 printf("The memory cannot be allocated, the null pointer found!");
   	 free(sizeOfDataSet); /* free allocated storage */
   	 return 1;
    }


    /* prompt user to enter the number of floating point values to the data set */
    printf("Enter the number of values, followed by the values on the same line:\n");

    for(i = 0;i < number; i++){
   	 
   	 scanf("%d", &numberOfData);

   	 /* assign values for the size of each data set */
   	 *(sizeOfDataSet + i) = numberOfData;
   	 
   	 /* allocate memory for each value in the data set */
   	 *(data + i) = malloc(numberOfData * sizeof(float));

   	 /* check whether the allocation fails or not */
   	 if(*(data + i) == 0){
   		 printf("The memory cannot be allocated, the null pointer found!");
   		 free(*(data + i)); /* free allocated storage */
   		 return 1;
   	 }

   	 /* read values for each data set and store them into the dynamic array */
   	 for(j = 0; j < numberOfData; j++){
   		 scanf("%f", &value);
   		 *(*(data + i) + j) = value;
   	 }
    
    }

    
    /* prompt the user to select one of the data sets by number */
    while(1){
   	 printf("Enter the number of data set on which you wish to do calculations\n");
   	 scanf("%d", &selectIndex);
   	 if(selectIndex > 0 && selectIndex <= number){
   		 break;
   	 }else{
   		 printf("Invalid input, please enter the number within the available number of data sets\n");
   	 }
    }

    while(1){
    
   	 /* repeatly prompt the user to choose one of the following options based on the chosen data set */
   	 printf("\nPlease select an option for a calculation based on the chosen data set\n\n");
   	 printf("1.Find the minimum value.\n");
   	 printf("2.Find the maximum value.\n");
   	 printf("3.Calculate the sum of all the values.\n");
   	 printf("4.Calculate the average of all the values.\n");
   	 printf("5.Sort the values in ascending order (from smallest to largest.\n");
   	 printf("6.Select a different data set.\n");
   	 printf("7.Exit the program.\n\n");

   	 /* read and store user's option */
   	 scanf("%d", &option);
   	 
   	 /* Exit the program */
   	 if(option == 7){
   		 printf("Exit the program\n");

   		 /* free the dynamically allocated space for each of the data sets */
   		 freeAllocatedMemory(data, number);
   		 free(sizeOfDataSet);
   		 break;
   	 }else{
   		 switch(option){

   		 /* Find the minimum value in the data set */
   		 case 1:
   			 min = findMinimum(data, selectIndex - 1, sizeOfDataSet + selectIndex - 1);
   			 printf("The minimum value in the data set is: %.2f\n", min);   		   
   			 break;
   		 /* Find the maximum value in the data set*/
   		 case 2:
   		     	max = findMaximum(data, selectIndex - 1, sizeOfDataSet + selectIndex - 1);
   			 printf("The maximum value in the data set is: %.2f\n", max);
   			 break;
   		 /* Calculate the sum of all the values */
   		 case 3:
   			 sum = findSum(data, selectIndex - 1, sizeOfDataSet + selectIndex - 1);
   			 printf("The sum of the data set is: %.2f\n", sum);
   			 break;
   		 /* Calculate the average of all the values */
   		 case 4:
   			 average = findAverage(data, selectIndex - 1, sizeOfDataSet + selectIndex - 1);
   			 printf("The average of the data set is: %.2f\n", average);
   			 break;
   		 /* Sort the values in ascending order (from smallest to largest) */
   		 case 5:
   			 insertionSort(data, selectIndex - 1, sizeOfDataSet + selectIndex - 1);
   			 break;

   		 /* Select a different data set */
   		 case 6:    
   			 while(1){
   				 printf("Please select a data set to do the calculation: \n");
   				 scanf("%d", &selectIndex);
   				 if(selectIndex > 0 && selectIndex <= number){
   					 break;
   				 }else{
   					 printf("The number you enter exceed the number of data sets !\n");
   				 }
   			 }
   			 break;
   		 /* Deal with invalid input */
   		 default:
   			 printf("Invaild option, please enter available option from 1 to 7\n");
   			 break;
   		 }
   	 }
    }    

return 0;
}
