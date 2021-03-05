double eval(int *key){
  int sum = 0;
  int count = 0;
  
  for(count = 0; count < 33; count++){
    if(key[count] > 0){
      sum++;
    }
  }
  
  for(count = 33; count < 36; count++){
    if(key[count] < 1){
      sum++;
    }
  }
  
  for(count = 36; count < 70; count++){
    if(key[count] > 0){
      sum++;
    }
  }
  
  if(key[count] > 0 && key[count+1] > 0){
    sum += 2;
  }
  
  for(count = 72;count < 100;count++){
    if(key[count] < 1){
      sum++;
    }
  }
  return sum;
}
