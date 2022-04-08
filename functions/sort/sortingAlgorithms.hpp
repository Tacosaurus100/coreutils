#ifndef SORTING_ALGORITHMS
#define SORTING_ALGORITHMS

#include <coreutils/functions/sort/sortHelpers.hpp>
#include <coreutils/functions/debug/print.hpp>

namespace coreutils 
{
   namespace functions
   {
      namespace sort {
			template<typename T>
         inline int* insertionSort (T* arrayPtr, int size){
            int smallestIndex;
            int index;
            int index2;
            int* order = new int[size];
            for (int i = 0; i < size; i++) {
               order[i] = i;
            }
            for (int i = 0; i < size; i++) {
               smallestIndex = i;
               for (int j = i + 1; j < size; j++) {
                  if (arrayPtr [smallestIndex] > arrayPtr [j]){
                     smallestIndex = j;
                  }
               }
               sort::swap(&arrayPtr [i], &arrayPtr [smallestIndex]);
               sort::swap(&order[i], &order[smallestIndex]);
            }
            return order;
         }

         template<typename T>
         inline void merge(T *Arr, int start, int mid, int end) {
            // create a temp array
            T temp[end - start + 1];

            // crawlers for both intervals and for temp
            int i = start, j = mid+1, k = 0;

            // traverse both arrays and in each iteration add smaller of both elements in temp 
            while(i <= mid && j <= end) {
               if(Arr[i] <= Arr[j]) {
                  temp[k] = Arr[i];
                  k += 1; i += 1;
               }
               else {
                  temp[k] = Arr[j];
                  k += 1; j += 1;
               }
            }

            // add elements left in the first interval 
            while(i <= mid) {
               temp[k] = Arr[i];
               k += 1; i += 1;
            }

            // add elements left in the second interval 
            while(j <= end) {
               temp[k] = Arr[j];
               k += 1; j += 1;
            }

            // copy temp to original interval
            for(i = start; i <= end; i += 1) {
               Arr[i] = temp[i - start];
            }
         }

         // Arr is an array of integer type
         // start and end are the starting and ending index of current interval of Arr
         template<typename T>
         inline void mergeSort(T *Arr, int start, int end) {
            if(start < end) {
               int mid = (start + end) / 2;
               mergeSort(Arr, start, mid);
               mergeSort(Arr, mid+1, end);
               merge(Arr, start, mid, end);
            }
         }
		}
   }
}

#endif