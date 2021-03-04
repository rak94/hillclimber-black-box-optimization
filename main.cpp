#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>

using namespace std;

// function given by eval.o
double eval(int *pj);

// helper functions
void printArray(int* iArray);
void increment(int* iArray);
void init(int* iArray);
void copy(int* fromArray, int* toArray);

int bestArray [100];
double bestFit = 0.0;

void hillClimber();

int main(){
  hillClimber();
  // print out the best array once the threads are finished
  cout << "Best Fit: " << bestFit << endl;
  printArray(bestArray);
}

void copy(int* fromArray, int* toArray){
  for (int i = 0; i < 100; i++){
    toArray[i] = fromArray[i];
  }
}

void init(int* iArray){
  for (int i = 0; i < 100; i++){
    iArray[i] = 0;
  }
}

void increment(int* iArray){
  int i = 0;
  while(iArray[i] == 1 && iArray[i] < 100){
    i++;
  }
  iArray[i] = 1;
}

void printArray(int* iArray){
  cout << "[";
  for (int i = 0; i < 99; i++){
    cout << iArray[i] << "'";
  }
  cout << iArray[99];
  cout << "]" << endl;
}

void hillClimber(){
  long randomCounter = 0;

  // increment
  double oldFit = 0;
  int oldArray[100];
  double newFit = 0;
  int newArray[100];

  while (randomCounter < 100){
    // finding a new random starting point
    init(newArray);
    oldFit = 0;
    newFit = eval(newArray);
    // keep climbing while the new point is high
    while(newFit >= oldFit){
      copy(newArray, oldArray);
      oldFit = newFit;
      increment(newArray);
      newFit = eval(newArray);
    }
    // save if the local maximum is better than the best known maximum
    if(oldFit > bestFit){
      copy(oldArray, bestArray);
      bestFit = oldFit;
      cout << "New Maximum: " << oldFit << endl;
      if(bestFit == 100){
        randomCounter = 100;
      }
    }
    randomCounter++;
  }
}