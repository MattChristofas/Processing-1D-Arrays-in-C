#include <time.h>
#include <stdio.h>
#include <stdlib.h>

/*
Matthew Christofas
February 14, 2023
Computer Systems & LL Programming
Lab 04 1D Arrays
Mission: To design and implement functions to process 1D Arrays.  
*/

#define RAND_MIN 0
#define RAND_MAXIMUM 100
#define SIZE 40
int i,lowrange,highrange,lowrange2,highrange2,tom,jerry;


void fillArray(int array[], int size);
void findWithRange(int b[], size_t size);
void reverseArray(int array[], int first, int last);
void reverseSelectedRangeWithinArray(int array[], size_t size, int first, int last);
void findSequence(int array[],size_t size);

int main(int argc, const char * argv[]){

    srand(time(NULL));
    int array[SIZE];
    

    fillArray(array, SIZE);
    findWithRange(array,SIZE);
    reverseArray(array,0,SIZE-1);
    reverseSelectedRangeWithinArray(array,SIZE,0,SIZE-1);
    findSequence(array,SIZE);
    

}

void fillArray(int array[], int size){
    printf("\n******* FILL ARRAY *******\n");
    
    for (size_t i = 0; i < SIZE; ++i){
        array[i] = rand() % (RAND_MAXIMUM+1)+ RAND_MIN;

    }
    puts("   Element      Value");
    for (size_t i = 0; i < SIZE; ++i){
        printf("%7d%13d\n",i, array[i]);

    }
    puts("\n");
}

void findWithRange(int b[], size_t size){
    printf("\n******* FIND WITH RANGE *******\n");
    int max = b[0];

    printf("Enter a low range: ");
    scanf("%d",&lowrange);
    if (lowrange < 0 || lowrange >= size){
        printf("Invalid input, please enter a number within the specified range (0 - 40)");
        scanf("%d",&lowrange);
    }
    
    printf("Enter a high range: ");
    scanf("%d",&highrange);
    if (highrange < 0 || highrange >= size){
        printf("Invalid input, please enter a number within the specified range (0 - 40)");
        scanf("%d",&highrange);
    }

    for (size_t i = lowrange; i <= highrange; ++i){
        if(b[i] > max){
            max = b[i];
        }
        
    }
    printf("Largest element: %d\n",max);


}

void reverseArray(int array[], int first, int last){
    printf("\n******* REVERSE ARRAY *******\n");
    int temp;
    while (first <= last){
        temp = array[first];
        array[first] = array[last];
        array[last] = temp;
        first++;
        last--;
    }

    for (size_t i = 0; i < SIZE; ++i){
        printf("%7d%13d\n",i, array[i]);

    }
    puts("\n");


}

void reverseSelectedRangeWithinArray(int array[], size_t size, int first, int last){
    printf("\n******* REVERSE RANGE *******\n");
    printf("Enter a low range: ");
    scanf("%d",&lowrange2);
    while (lowrange2 < 0 || lowrange2 >= size){
        printf("Invalid input, please enter a number within the specified range (0 - 40)");
        scanf("%d",&lowrange2);
    }
    
    printf("Enter a high range: ");
    scanf("%d",&highrange2);
    while (highrange2 < 0 || highrange2 >= size){
        printf("Invalid input, please enter a number within the specified range (0 - 40)");
        scanf("%d",&highrange2);
    }

    int temp;

        while (lowrange2 < highrange2){
            temp = array[lowrange2];
            array[lowrange2] = array[highrange2];
            array[highrange2] = temp;
            lowrange2++;
            highrange2--;
    
    }
    
    for (size_t i = 0; i < SIZE; ++i){
        printf("%7d%13d\n",i, array[i]);

    }
    puts("\n");
}

void findSequence(int array[],size_t size){
    printf("\n******* FIND SEQUENCE *******\n");
    int z;
    printf("Enter two integers from 0 to 100: ");
    scanf("%d %d", &tom, &jerry);
    printf("TOM: %d\nJerry: %d",tom,jerry);
    for(size_t i = 0; i<SIZE; i++){
        if(array[i] == tom && array[i+1] == jerry){
            printf("\nSequence found at index %d\n",i);
            int z = 1;
            exit(0);
        }
    }
    printf("\nSeqence not found\n");
}