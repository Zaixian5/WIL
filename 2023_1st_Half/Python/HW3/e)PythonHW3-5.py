# 3-5. 라이프니츠 공식으로 원주율을 계산하는 제너레이터 만들기

# 라이프니츠 공식은 무한급수로 되어있어 많이 계산할 수록 실제 원주율 값과 근사한 값을 얻을 수 있음
# 따라서 실제 원주율 값과 비교하여 제너레이터를 몇번 실행해야 하는지도 같이 확인할 수 있도록 설정
# 즉, 제너레이터 실행 횟수가 실제 원주율과 가장 근사한 값을 얻기까지의 시그마 계산 횟수라고 할 수 있음 

import math

def leibniz(): # 라이프니츠 공식으로 원주율을 계산하는 제너레이터
  pi = 0
  i = 1

  while True:
    denominator = 2*i - 1
    numerator = (-1) ** (i + 1)
    pi += numerator / denominator
    i += 1

    yield 4 * pi

def calcPi(k): 
  pi_gen = leibniz()
  count_gen = 0

  while True:
    pi_value = next(pi_gen)
    count_gen += 1

    if round(pi_value, k) == round(math.pi, k):
      print(f"반올림해서 소수점 {k}번째까지 계산한 원주율: {round(pi_value, k)}")
      print(f"제너레이터 실행 횟수: {count_gen}회") # math.pi와 라이프니츠 공식으로 계산한 원주율을 비교하여 최소 전개 횟수를 구합니다.
      break

# 문제5 테스트1
# calcPi(5) # 소수점 5째 자리까지의 원주율 계산
calcPi(5)

# 문제5 테스트2
# calcPi(6) # 소수점 6째 자리까지의 원주율 계산
calcPi(6)