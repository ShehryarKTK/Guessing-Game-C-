#include<iostream>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>
using namespace std;


sem_t semaphore;
int counter=0;

void *thread1(void* args){
///CS1////
//lock
sem_wait(&semaphore);
for(int i=0;i<=5000000;i++){
counter++;
if(counter%1000000==0){
cout<<"Value  of Counter from Thread 1 is "<<counter<<endl;

}
}
//unlock
sem_post(&semaphore);


//lock
sem_wait(&semaphore);
for(int i=0;i<=5000000;i++){
counter++;
if(counter%1000000==0){
cout<<"Value  of Counter from Thread 1 is "<<counter<<endl;

}
}
//unlock
sem_post(&semaphore);


//lock
sem_wait(&semaphore);
for(int i=0;i<=5000000;i++){
counter++;
if(counter%1000000==0){
cout<<"Value  of Counter from Thread 1 is "<<counter<<endl;

}
}
//unlock
sem_post(&semaphore);
}




void *thread2(void* args){

//lock
sem_wait(&semaphore);
for(int i=0;i<=5000000;i++){
counter--;
if(counter%1000000==0){
cout<<"Value  of Counter from Thread 2 is "<<counter<<endl;

}
}
//unlock
sem_post(&semaphore);


}
int main(){
pthread_t t1,t2;

//initialize Semaphore
sem_init(&semaphore,0,1);
pthread_create(&t1,NULL,thread1,NULL);
pthread_create(&t2,NULL,thread2,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);

//Destroy  Semaphore 
sem_destroy(&semaphore);
cout<<"Final value of counter is: "<<counter<<endl;


return 0;
}
