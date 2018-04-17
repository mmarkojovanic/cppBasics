#include<iostream>
#include <pthread.h>
#define NUM_THREADS 10

using namespace std;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int total_sum = 0;
bool lock = false;
int*A;
int*B;
int*C;

struct arg_struct {
	int threadid;
    int* arg1;
    int* arg2;
    int* arg3;
};

void *PrintHello(void *threadid) {
   	long tid = (long)threadid;
//	while(pthread_mutex_lock(&mutex));
	while(lock); lock = true;
   	cout << "Hello World! Thread ID, " << tid << endl;
   	lock = false;
//   	pthread_mutex_unlock(&mutex);
   	pthread_exit(NULL);
}
//void *SUM(void *args)
//{
//	arg_struct args1 = (arg_struct)(*args);
//	int tid = args1.threadid;
//	int* A = args1.arg1;
//	int* B = args1.arg2;
//	int* C = args1.arg3;
////   	long tid = (long)threadid;
//	int sum = 0;
//	for(int i = 0; i<100; i++)
//	{
//		while(lock); lock = true;
//   		cout << "Hello World! Thread ID, " << tid << " iteration: " << i << endl;
//   		lock = false;
//		C[tid*100+i]=A[tid*100+i]+B[tid*100+i];
//		sum+=C[tid*100+i];
//	}
//	while(pthread_mutex_lock(&mutex));
//	total_sum += sum;
//	pthread_mutex_unlock(&mutex);
//	pthread_exit(NULL);
//}

int main () {
	pthread_t threads[NUM_THREADS];
   	int rc;
   	int i;
   	for( i = 0; i < NUM_THREADS; i++ ) {
  	//	while(pthread_mutex_lock(&mutex));
  		while(lock); lock = true;
      	cout << "main() : creating thread, " << i << endl;
      	lock = false;
    //  	pthread_mutex_unlock(&mutex);
      	rc = pthread_create(&threads[i], NULL, PrintHello, (void *)i);
      	if (rc) {
        	 cout << "Error:unable to create thread," << rc << endl;
        	 exit(-1);
      	}
   	}
  // 	while(pthread_mutex_lock(&mutex));
  	while(lock); lock = true;
   	cout << "Hello World from main thread!" << endl;
   	lock = false;
//   	pthread_mutex_unlock(&mutex);
   	for( i = 0; i < NUM_THREADS; i++ )
   		pthread_join(threads[i], NULL);
   	
//   	for(int i=0; i<1000; i++)
//   	{
//		A[i]= i;
//		B[i]= A[i]+i;
//	}
//	// now we want to A+B; and find total sum
//	A = new int[100*NUM_THREADS];
//	B = new int[100*NUM_THREADS];
//	C = new int[100*NUM_THREADS];
//	for(i=0; i<NUM_THREADS; i++)
//	{
//		arg_struct* args; args->arg1 = A; args->arg2 = B; args->arg3 = C; args->threadid = i;
//		void* params = (void*)(args);
//   		rc = pthread_create(&threads[i], NULL, SUM, params);
//   		if (rc) {
//        	 cout << "Error:unable to create thread," << rc << endl;
//        	 exit(-1);
//      	}
//   	}
//	for(i = 0; i < NUM_THREADS; i++)
//   		pthread_join(threads[i], NULL);
//   		
//   	cout << "Total sum: " << total_sum << endl;

   	
   	
   	pthread_exit(NULL);
}
