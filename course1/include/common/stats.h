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
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief prints all the statistic of the funtions developed 
 *
 * Given an array print the statistics 
 *
 * @param array input to calculate statistics
 * @param size  array size 
 *
 */
void print_statistics(unsigned char *array, unsigned int size);


/**
 * @brief prints the current array 
 *
 * Given an array of data and a length, prints the array to the screen 
 *
 * @param array pointer to array to calculate statistics
 * @param size  array size 
 *
 */
void print_array(unsigned char *array, unsigned int size);


/**
 * @brief Calculates the median of an array 
 *
 * Given an array of data and a length, calculates the median
 *
 * @param array pointer to array to calculate statistics
 * @param size  array size 
 *
 * @return the 4 bytes of array media 
 */
unsigned char find_median(unsigned char *array, unsigned int size);

/**
 * @brief Calculates the mean of an array 
 *
 * Given an array of data and a length, calculates the mean
 *
 * @param array pointer to array to calculate statistics
 * @param size  array size 
 *
 * @return the 4 bytes of array media 
 */
float find_mean(unsigned char *array, unsigned int size);

/**
 * @brief Calcuates the maximum of an array 
 *
 * Given an array of data and a length, calculates the maximum
 *
 * @param array pointer to array to calculate statistics
 * @param size  array size 
 *
 * @return the 4 bytes of mean 
 */
unsigned char find_maximum( unsigned char *array, unsigned int size);


/**
 * @brief Calculates the minimum 
 *
 * Given an array of data and a length, calculates the minimum
 *
 * @param array pointer to array to calculate statistics
 * @param size  array size 
 *
 * @return the 4 bytes of mean 
 */
unsigned char find_minimum( unsigned char *array, unsigned int size);


/**
 * @brief short the input array form largest to smallest 
 *
 * Given an array of data and a length, sorts the array from largest to smallest. 
 *
 * @param array pointer to array
 * @param size  array size 
 *
 */
void sort_array ( unsigned char *array, unsigned int size);

#endif /* __STATS_H__ */
