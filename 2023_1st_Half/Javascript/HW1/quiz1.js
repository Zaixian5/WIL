function calculateGCD() 
{
  let userNum1 = parseInt(document.querySelector("#num1").value);
  let userNum2 = parseInt(document.querySelector("#num2").value);

  if (Number.isNaN(userNum1) || Number.isNaN(userNum2)) 
  {
    document.querySelector("#result").innerHTML = "잘못된 입력입니다.";
  }
  else
  {
    let gcd = getGCD(userNum1, userNum2);
    document.querySelector("#result").innerHTML = `최대 공약수: ${gcd}`;
  }
}

function getGCD(num1, num2) 
{
  let target = (num1 > num2) ? (num2) : (num1);
  let result = null;

  for(let i = 1; i <= target; i++)
  {
    if(num1 % i === 0 && num2 % i === 0)
    {
      result = i;
    }
  }

  return result;
}