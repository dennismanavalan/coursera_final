/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief Print the statistics of an array from an array
 *
 * <Add Extended Description Here>
 *
 * @author Dennis Manavalan
 * @date 28 March
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void print_statistics(unsigned char *array, unsigned int size){
	print_array(array,size);
	find_maximum(array, size);
	find_minimum(array, size);
	find_mean(array, size);
	find_median(array, size);
	sort_array(array,size);
}

void print_array(unsigned char *array, unsigned int size){
	printf("Array = \n");
	for (unsigned int i = 0; i < size; i++){
		printf("%d \t", array[i]);
	} 	
	printf ("\n");
}

unsigned char find_median(unsigned char *array, unsigned int size)
{
    int i,j,temp;
  for(j=0; j<=size; ++j)
  {
    for(i=j+1; i<=size; ++i)
     {
      if(array[j]<array[i])
      {
        temp=array[j];
        array[j]=array[i];
        array[i]=temp;
      }
     }
   }
  int med=(array[21]+array[20])/2;
  printf("median= %d\n\n",med);
}

float find_mean(unsigned char *array, unsigned int size){
	float mean = 0;
	float m;	
	//float mean = array[0];	
	for (unsigned int i = 0; i < size; i++){
		mean += array[i];
	}

	m = mean/size;
	printf("Mean = %f\n", m);
}

unsigned char find_maximum( unsigned char *array, unsigned int size){
	unsigned int max = 0;	
	for (unsigned int i = 0; i < size; i++){
		if (max < array[i]){
			max = array[i];	
		}
	} 	

	printf("Mamimum = %d\n", max);
}

unsigned char find_minimum( unsigned char *array, unsigned int size){
	unsigned int min = array [0];	
	for (unsigned int i = 1; i < size; i++){
		if (min > array[i]){
			min = array[i];	
		}
	}
	printf("Minimum = %d\n", min);
}

void sort_array ( unsigned char *array, unsigned int size)
{
  unsigned int i,j,temp;
  for(j=0; j<=size; ++j)
  {
    for(i=j+1;i<=size;++i)
     {
      if(array[j]<array[i])
      {
        temp=array[j];
        array[j]=array[i];
        array[i]=temp;
      }
     }
   }
   printf("sort_array=[");
   for(i=0; i<=size; i++)
    {
        printf("%d,",array[i]);
    }
    printf("]\n\n");
}

int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
	print_statistics(test, SIZE);
	return 0;
}

/* Add other Implementation File Code Here */
