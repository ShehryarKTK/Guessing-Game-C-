#include<iostream>
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>


int main(){

key_t child1=ftok("shmfile",1);
int child1_id=shmget(child1,100,0666|IPC_CREAT);

int* c1=(int*) shmat(child1_id,(void*)0,0);


pid_t a = fork();

if(a>0){
wait(NULL);
}
else if(a==0){

key_t child1=ftok("shmfile",1);
int child1_id=shmget(child1,100,0666|IPC_CREAT);

int *c1=(int*) shmat(child1_id,(void*)0,0);
srand((unsigned int)time(NULL));
int random=rand() % 10;
int num;
int check=0;
int losses=0;
std::cout << "Now Turn for Child Process 1: \n" <<'\n';
while(check==0){
std::cout << "Guess the Number!: "<<'\n';
std::cin >> num;
if(num==random){
check=1;
std::cout << "You guessed Correctly!"<<'\n';
}
else{
losses+=1;
}
}
*c1=losses;
shmdt(c1);
exit(NULL);
}

int losses = *c1;
shmdt(c1);
shmctl(child1,IPC_RMID,NULL);


//Second Process

key_t child2=ftok("shmfile",2);
int child2_id=shmget(child2,100,0666|IPC_CREAT);

int* c2=(int*) shmat(child2_id,(void*)0,0);
pid_t b = fork();

if(b>0){
wait(NULL);
}
else if(b==0){

key_t child2=ftok("shmfile",1);
int child2_id=shmget(child2,100,0666|IPC_CREAT);

int *c2=(int*) shmat(child2_id,(void*)0,0);
srand((unsigned int)time(NULL));
int random=rand() % 10;
int num;
int check=0;
int losses=0;
std::cout << "Now Turn for Child Process 2:" <<'\n';
while(check==0){
std::cout << "Guess the Number! : "<<'\n';
std::cin >> num;
if(num==random){
check=1;
std::cout << "You guessed Correctly!\n"<<'\n';
}
else{
losses+=1;
}
}
*c2=losses;
shmdt(c1);
exit(NULL);
}

int losses2 = *c1;
shmdt(c2);
shmctl(child2,IPC_RMID,NULL);

//Third  Process

key_t child3=ftok("shmfile",3);
int child3_id=shmget(child3,100,0666|IPC_CREAT);

int* c3=(int*) shmat(child3_id,(void*)0,0);
pid_t c = fork();

if(c>0){
wait(NULL);
}
else if(c==0){

key_t child3=ftok("shmfile",3);
int child3_id=shmget(child3,100,0666|IPC_CREAT);

int *c3=(int*) shmat(child3_id,(void*)0,0);
srand((unsigned int)time(NULL));
int random=rand() % 10;
int num;
int check=0;
int losses=0;
std::cout << "Now Turn for Child Process 3: "<<'\n';
while(check==0){
std::cout << "Guess the Number! : "<<'\n';
std::cin >> num;
if(num==random){
check=1;
std::cout << "You guessed Correctly!\n"<<'\n';
}
else{
losses+=1;
}
}
*c3=losses;
shmdt(c3);
exit(NULL);
}

int losses3 = *c3;
shmdt(c3);
shmctl(child3,IPC_RMID,NULL);


if(losses<losses2 && losses<losses3){
std::cout << "Child Process 1  is the Winner!"<<'\n';
}

if(losses2<losses && losses2<losses3){
std::cout << "Child Process 2  is the Winner!"<<'\n';
}

if(losses3<losses2 && losses3<losses){
std::cout << "Child Process 3  is the Winner!"<<'\n';
}



return 0;
}



