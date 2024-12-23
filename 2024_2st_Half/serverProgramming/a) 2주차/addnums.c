// addnums.c
// You didn't tell me to submit this file, but I'm submitting it because I think you'll need it.

int addnums(int* nums, int n){
  int sum = 0;

  for(int i = 0; i < n; ++i){
    sum += *nums++;
  }

  return sum;
}
