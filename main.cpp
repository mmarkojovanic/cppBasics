#include<iostream>
#include <pthread.h>
#define NUM_THREADS 10

using namespace std;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
bool lock = false;

void *PrintHello(void *threadid) {
   	long tid = (long)threadid;
//	while(pthread_mutex_lock(&mutex));
	while(lock); lock = true;
   	cout << "Hello World! Thread ID, " << tid << endl;
   	lock = false;
//   	pthread_mutex_unlock(&mutex);
   	pthread_exit(NULL);
}

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
   	 	
   	
   	pthread_exit(NULL);
}
