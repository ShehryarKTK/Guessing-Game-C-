#include<iostream>
#include<unistd.h>
#include<pthread.h>
#include<cstdlib>
#include<chrono>
#include<algorithm>
#include<vector>

using namespace std;
using namespace std::chrono;

// function to calculate factorial
long long int factorial(int n){
long long int fact = 1;
int i;
   for(i=1; i<n; i++){
   fact = fact * i;
   }
   return fact;
}

//function to check if number is prime or not
int check_prime(int n){
int i;
bool is_prime = true;

  

  // 0 and 1 are not prime numbers
  if (n == 0 || n == 1) {
    is_prime = false;
  }

  // loop to check if n is prime
  for (i = 2; i <= n/2; ++i) {
    if (n % i == 0) {
      is_prime = false;
      break;
    }
  }

  if (is_prime)
    cout << n << " is a prime number\n";
  else
    cout << n << " is not a prime number\n";

  return 0;

}

// routine for thread 1 to perform
void *thread1(void* arg)
{
int *array=(int *) arg;
long long int fact;
 for(int i=0;i<100;i++){
  
      fact=factorial(array[i]);
      cout << "Factorial of a Number "<<array[i]<<" is " <<fact<<endl;
      }

}
// routine for thread 2 to perfrom    void *t
void *thread2(void* arg)
{
int *array=(int *) arg;
 for(int i=0;i<100;i++){
  
      check_prime(array[i]);
      cout << endl;
      }

}


int main(){
int randArray[100];
   for(int n=0;n<100;n++){
      randArray[n]=rand()%100;  //Generate number between 0 to 99
  }
  
  //Now to find the execution time for main 
  auto start = high_resolution_clock::now();
    long long int fact;
   for(int i=0;i<100;i++){
  
      fact=factorial(randArray[i]);
      cout << "Factorial of Number "<<randArray[i]<< " is " <<fact<<endl;
      }
      
    for(int i=0;i<100;i++){
  
      check_prime(randArray[i]);
      cout << endl;
      }
      
    auto stop = high_resolution_clock::now();  
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by Main: " << duration.count() << " microseconds" << endl;
    
      //Main Program Ends
      
    
     //Now to do the above task with Threads
   auto start_t = high_resolution_clock::now();
    pthread_t  t1;
    pthread_t  t2;
   
    
    
    pthread_create(&t1,NULL,thread1,(void*)randArray);
    pthread_create(&t2,NULL,thread2,(void*)randArray);
    
    
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    auto stop_t = high_resolution_clock::now();
    auto duration_t = duration_cast<microseconds>(stop_t - start_t);
    //Now to find the time taken by threads to finish the task
    cout << "\nTime taken by Threads: "<< duration_t.count() << " microseconds" << endl;
    
    
      return 0;
      }

