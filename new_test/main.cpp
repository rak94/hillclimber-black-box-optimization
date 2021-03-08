// Student Name - Rakshith Kothanur Harish
// Email - rak94@live.missouristate.edu
// Instructor - Dr. Siming Liu
// Problem - Hill Climber Black Box Optimization

#include <iostream>

using namespace std;

double eval (int *pj);
void modify (int *pj, int index);

//main hillclimber function
int main(){
  int size = 100; //size of pj
  int pj[size]; //current best solution
  double fit = 0; //current fitness
  double new_fit = 0; //new fitness
  int index = 0; //position in string
  int p_index = 0;

  for(index = 0; index < size; index++){
    pj[index] = 0;
  }
  fit = eval(pj);
  cout << "Initail Fitness = " << fit << endl;
  index=0;
  do{
    modify(pj, index);
    new_fit = eval(pj);
    //keep new solution if it's better
    if(new_fit > fit){
      fit = new_fit;
      p_index = index;
    }
    //else return to old solution and move on
    else{
      modify(pj, index);
    }
    index++;
    if(index > size-1){
      index = 0;
    }
  }
  while(index != p_index);
  //output solution vector
  cout << "Best Fitness = " << fit << endl;
  cout << "Vector: ";  
  for(index = 0; index < size-1; index++){
    cout << pj[index] << ",";
  }
  index = size-1;
  cout << pj[index] << endl;
  return 0;
}

//function swaps value at index for new candidate solution
void modify (int *pj, int index){
  pj[index] = 1-pj[index];
}
