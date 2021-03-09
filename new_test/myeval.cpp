// Student Name - Rakshith Kothanur Harish
// Email - rak94@live.missouristate.edu
// Instructor - Dr. Siming Liu
// Problem - Hill Climber Black Box Optimization

double eval(int *pj){
  int sum = 0;
  int count = 0;
  
  for(count = 0; count < 25; count++){
    if(pj[count] > 0){
      sum++;
    }
  }
  
  for(count = 25; count < 70; count++){
    if(pj[count] < 1){
      sum++;
    }
  }
  
  for(count = 70; count < 76; count++){
    if(pj[count] > 0){
      sum++;
    }
  }
  
  if(pj[count] > 0 && pj[count+1] > 0){
    sum += 2;
  }
  
  for(count = 76;count < 100;count++){
    if(pj[count] < 1){
      sum++;
    }
  }
  return sum;
}
