def convert_base_nat(mstr, m, n):
  convert_decimal = int(mstr, m) # 10진법으로 변환

  if convert_decimal < n == 0:
      result = str(convert_decimal) # 변환하고자 하는 진법보다 10진법 수가 작은 경우 변환 과정 불필요
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

    result = ""
    for i in range(1, len(reversed_result) + 1):
      result += reversed_result[-i] # reversed_result를 거꾸로 재배치해서 result에 저장

  return result

mstr = input("진법변환 하고자 하는 수를 입력하세요: ")
m = int(input("입력하신 수는 몇진법인가요?: "))
n = int(input("입력하신 수를 몇진법으로 변환 할까요?: "))

result = convert_base_nat(mstr, m, n)

print(f"{m}진법의 {mstr}을 {n}진법으로 변환하면 {result}입니다.")
