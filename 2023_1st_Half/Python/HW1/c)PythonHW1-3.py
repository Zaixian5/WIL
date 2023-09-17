import math

x = y = 0 # 분수의 순서쌍. x - 분자, y - 분모

# mstr이 우량입력인지 불량입력인지 판단하는 함수
def confirm_mstr(mstr):
  (left, dot, right) = mstr.partition(".")

  if dot == ".":

    if left.isdigit() and right.isdigit():
      return "float" # 소수일 경우 float 반환

    elif left[0] == "-" and left[1:].isdigit() and right.isdigit():
      return "float" # 소수일 경우 float 반환

    # 알파벳이 포함된 양의 소수인 경우
    elif str(int(left, 36)).isdigit() and str(int(right, 36)).isdigit:
      return "float"

    # 알파벳이 포함된 음의 소수인 경우
    elif left[0] == "-" and str(int(left, 36))[1:].isdigit() and str(int(right, 36)).isdigit:
      return "float"

    else:
      raise ValueError # 불량입력
  
  else:
    
    if mstr.isdigit():
      return "integer" # 정수일 경우 integer 반환

    elif  mstr[0] == "-" and mstr[1:].isdigit():
      return "integer" # 정수일 경우 integer 반환

    elif str(int(mstr, 36)).isdigit(): # 알파벳이 포함된 양의 정수일 경우
      return "integer"

    elif mstr[0] == "-" and str(int(mstr, 36))[1:].isdigit(): # 알파벳이 포함된 음의 정수일 경우
      return "integer"

    else:
      raise ValueError # 불량입력

# mstr이 정수일 경우 진법 변환 함수
def convert_base_nat(mstr, m, n):
  convert_decimal = int(mstr, m) # 10진법으로 변환
  negative = 0

  if convert_decimal < 0: # mstr이 음수일 경우 양수로 변환 후 계산
    negative = True
    convert_decimal *= -1
  
  if convert_decimal < n == 0: # 변환하고자 하는 진법보다 10진법 수가 작은 경우 변환 과정 불필요
      result = str(convert_decimal)
      return result

  else:
    reversed_result = "" 
    target = convert_decimal

    while True:
      if target < n:
        if target > 9: # target > 9일 경우 알파벳으로 바꿔야 함
          target = chr(65 + (target - 10)) # ASCII 코드를 이용한 알파벳 변환

        reversed_result += str(target) 
        break

      num = target % n 
      if num > 9: # num > 9일 경우 알파벳으로 바꿔야 함
        num = chr(65 + (num - 10)) # ASCII 코드를 이용한 알파벳 변환

      reversed_result += str(num)
      target //= n

    if negative: # 양수로 변환했던 mstr을 다시 음수로 변환
      reversed_result += "-"

    result = ""
    for i in range(1, len(reversed_result) + 1):
      result += reversed_result[-i] # reversed_result를 거꾸로 재배치해서 result에 저장

  return result

# 0~9, A~Z의 글자를 정수로 변환하는 함수
def digit2int(c):
  return int(c, 36)

# 매개변수로 받은 실수를 10진법의 분수로 변환하는 함수
def mkFrac_base(decimal, m):
  global x, y

  decimal_list = []
  decimal_base = 0

  # 소수의 10진수 변환
  for i in range(0, len(decimal)):
    decimal_list.append(digit2int(decimal[i]))

  for j in range(0, len(decimal)):
    decimal_base += decimal_list[j] * ( m ** -(j+1) )

  # 분수로 만들기
  decimal_count = len(str(decimal_base).split(".")[1])
  denominator = 10 ** decimal_count
  numerator = int(decimal_base * denominator)

  # 약분해서 순서쌍에 저장
  division = math.gcd(denominator, numerator)
  x = int(numerator / division)
  y = int(denominator / division)

# 분수 곱셈과 뺄셈 계산을 통해 정수부분을 리턴하고 분수부분을 순서쌍에 담아주는 함수
def sepFrac(n):
  global x, y

  numerator = x * n
  denominator = y

  integer_part = numerator // denominator

  numerator -= (denominator * integer_part)

  division = math.gcd(numerator, denominator)
  x = int(numerator / division)
  y = int(denominator / division)

  if integer_part > 9:
    integer_part = chr(65 + (integer_part - 10)) # ASCII 코드를 이용한 알파벳 변환

  return integer_part

# mstr이 소수일 경우 진법 변환 함수
def convert_base(mstr, m, n, p):
  global x, y

  negative_zero = 0
  (integer, decimal) = mstr.split(".")

  # 소수의 정수 부분이 0이고 소수가 음수일 경우 convert_base_nat에서 음수 처리를 못함
  # 예) -0.25 => -0을 정수로 변환하면 0이므로 convert_base_nat에서 음수로 처리하지 못해 여기서 별도로 처리해야 함.
  if integer == "-0": 
    negative_zero = True

  converted_integer = convert_base_nat(integer, m, n)

  mkFrac_base(decimal, m)
  converted_decimal = ""

  while True:
    if x == y:
      break
    
    elif len(converted_decimal) == p:
      break

    else:
      converted_decimal += str(sepFrac(n))

  if negative_zero:
    result = "-" + converted_integer + "." + converted_decimal
  
  else:
    result = converted_integer + "." + converted_decimal

  return result

mstr = input("진법 변환할 실수를 입력하세요. ")

confirm = confirm_mstr(mstr)

if confirm == "integer":
  m = int(input("입력하신 수는 몇진법인가요? "))
  n = int(input("입력하신 수를 몇진법으로 변환할까요? "))

  result = convert_base_nat(mstr, m, n)

  print("")
  print(f"{m}진법의 {mstr}을 {n}진법으로 변환하면 {result}입니다.")

elif confirm == "float":
  m = int(input("입력하신 수는 몇진법인가요? "))
  n = int(input("입력하신 수를 몇진법으로 변환할까요? "))
  p = int(input("소수점 몇째 자리까지 나타낼까요? "))

  result = convert_base(mstr, m, n, p)

  print("")
  print(f"{m}진법의 {mstr}을 {n}진법으로 변환하면 {result}입니다.")
