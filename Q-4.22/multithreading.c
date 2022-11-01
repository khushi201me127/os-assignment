#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include<stdbool.h>
#include<math.h>

//Global variables
int n;    // variable for storing no of data elements passed on command line
int *arr; // array for storing arguments from command line

// average , minimum, maximum, median and standard deviation (std_dev) variables stored globally.
float average;
int minimum;
int maximum;
float median;
float std_dev;

//Thread1 for calculating average
void *avg()
{
    int i;
    float sum = 0;

    for (i =0; i< n; i++)
    {
        sum = sum + arr[i];
    }
    average = sum/n;
    
    pthread_exit(NULL);
}

//Thread2 for calculating minimum value
void *min()
{
    int i;
    minimum = arr[0];

    for (i =0; i< n;i++)
    {
        if (minimum > arr[i])
            minimum = arr[i];
    }
    
    pthread_exit(NULL);
}

//Thread3 for calculating maximum value
void *max()
{
    int i;
    maximum = arr[0];

    for (i=0; i< n; i++)
    {
        if (maximum < arr[i])
            maximum = arr[i];
    }
    
    pthread_exit(NULL);
}

//Thread4 for calculating median value
void *med()
{
    int i;
    int j;
    int temp;
    int *tp = (int*) arr;

    for(i=n-1;i>=1;i--)
    {
        bool idx = true;

        for(j=1;j<=i;j++)
        { 
               if(tp[j-1] > tp[j])
                {
                    temp = tp[j];
                    tp[j]= tp[j-1];
                    tp[j-1]= temp;
                }
                    idx = false;
                
                if(idx)
                    break;
        }
    }

    // To calculate median
    if( (n+1)%2 == 0) //for odd
    {
        median = tp[ ((n+1)/2) - 1 ];
    }
    else //for even
    {
        median =  (tp[ n/2 ]  +   tp[n/2 - 1]) / 2.0;
    }
    
    pthread_exit(NULL);
}


//Thread5 for calculating standard deviation
void *standard()
{
    int i;
    float var;
    for(i=0; i<n ; i++)
    {
        var += pow(arr[i] - average,2);
    }

    var = var/n;

    std_dev = sqrt(var);
    
    pthread_exit(NULL);
}


//main function
void main(int argc, char *argv[])
{
    int i;
    //The data elements passed on the command line.
    n = argc-1;

    //creating a dynamic array to store n elements.
    arr = (int *) malloc(sizeof(int)*n);

    //Converting the command line argument from string into integer.
    for (i=1; i < argc; i++)
    {   
        arr[i-1] = atoi(argv[i]);
    }   

    printf("\nThe number of elements passed on the command line are: %d\n",n);
    printf("\nThe entered elements are: \n");
    for (i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
 
    printf("\n\n");

    // Declaring five worker threads t1,t2,t3,t4,t5.
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;
    pthread_t t4;
    pthread_t t5;

    //creating threads
    pthread_create(&t1,NULL,&avg,NULL);
    pthread_join(t1,NULL);

    pthread_create(&t2,NULL,&min,NULL);
    pthread_join(t2,NULL);

    pthread_create(&t3,NULL,&max,NULL);
    pthread_join(t3,NULL);
    
    pthread_create(&t4,NULL,&med,NULL);
    pthread_join(t4,NULL);

    pthread_create(&t5,NULL,&standard,NULL);
    pthread_join(t5,NULL);


    //main of the parent thread
    /*The parent thread will output the result once the workers
    have exited*/

    printf("The average value is %f\n",average);
    printf("The minimum value is %d\n",minimum);
    printf("The maximum value is %d\n",maximum);
    printf("The median  value is %0.2f\n",median);    
    printf("The standard deviation  value is %0.3f\n",std_dev); 
    printf("\n\n");
}
