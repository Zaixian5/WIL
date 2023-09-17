var chunk = function(arr, size) {
  let resultArr = [];
  let subArr = [];

  if(arr[0] === undefined){
    return arr;
  }

  let i = 0;
  while(true){
    if(arr[i + size] !== undefined){
      subArr = arr.slice(i, i + size);
      resultArr.splice(i, 0, subArr);
      i += size;
    }
    else{
      subArr = arr.slice(i);
      resultArr.splice(i, 0, subArr);
      break;
    }
  }

  return resultArr;
};
