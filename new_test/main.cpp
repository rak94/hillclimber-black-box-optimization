#include <iostream>

using namespace std;

double eval (int *key);
void modify (int *key,int index);

//main hillclimber function
int main()
{
  int size = 100;//size of key
  int key[size];//current best solution
  double fit = 0;//current fitness
  double nfit = 0;//new fitness
  int index = 0;//position in string
  int pindex = 0;

  for(index = 0; index < size; index++)
  {
    key[index] = 0;
  }
  
  fit = eval(key);
  cout << "starting fitness = " << fit << endl;
  
  index=0;
  do
  {
    modify(key,index);
    
    nfit = eval(key);
    
    if(nfit>fit)//keep new solution if it's better
    {
      fit = nfit;
      pindex = index;
    }
    else//else return to old solution and move on
    {
      modify(key,index);
    }
    
    index++;
    if(index > size-1)
    {
      index = 0;
    }
    
  }while(index != pindex);
  
  //output solution vector
  cout << "fitness = " << fit << endl;
  cout << "Vector: ";  
  for(index = 0; index < size-1; index++)
  {
    cout << key[index] << ",";
  }
  index = size-1;
  cout << key[index] << endl;
  
  return 0;
}

//function swaps value at index for new candidate solution
void modify (int *key,int index)
{
  key[index] = 1-key[index];
}
