#include<iostream>
#include<pthread.h>
#include<stdlib.h>
using namespace std;


pthread_mutex_t mutex;
int counter=0;

void *thread1(void* args){
///CS1////
//lock
pthread_mutex_lock(&mutex);
for(int i=0;i<=5000000;i++){
counter++;
if(counter%1000000==0){
cout<<"Value  of Counter from Thread 1 is "<<counter<<endl;

}
}
//unlock
pthread_mutex_unlock(&mutex);


//lock
pthread_mutex_lock(&mutex);
for(int i=0;i<=5000000;i++){
counter++;
if(counter%1000000==0){
cout<<"Value  of Counter from Thread 1 is "<<counter<<endl;

}
}
//unlock
pthread_mutex_unlock(&mutex);


//lock
pthread_mutex_lock(&mutex);
for(int i=0;i<=5000000;i++){
counter++;
if(counter%1000000==0){
cout<<"Value  of Counter from Thread 1 is "<<counter<<endl;

}
}
//unlock
pthread_mutex_unlock(&mutex);
}




void *thread2(void* args){

//lock
pthread_mutex_lock(&mutex);
for(int i=0;i<=5000000;i++){
counter--;
if(counter%1000000==0){
cout<<"Value  of Counter from Thread 2 is "<<counter<<endl;

}
}
//unlock
pthread_mutex_unlock(&mutex);


}
int main(){
pthread_t t1,t2;
pthread_mutex_init(&mutex,NULL);
pthread_create(&t1,NULL,thread1,NULL);
pthread_create(&t2,NULL,thread2,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
pthread_mutex_destroy(&mutex);
cout<<"Final value of counter is: "<<counter<<endl;


return 0;
}
