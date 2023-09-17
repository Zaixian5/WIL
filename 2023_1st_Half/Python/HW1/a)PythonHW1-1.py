import math # math.lcm, math.gcd 등등 활용을 위해 import

x1 = y1 = x2 = y2 = 0   # 분수 q1과 q2의 순서쌍
add_x = add_y = 0       # 덧셈 계산 결과의 순서쌍
sub_x = sub_y = 0       # 뺄셈 계산 결과의 순서쌍
div_x = div_y = 0       # 나눗셈 계산 결과의 순서쌍

# 각각의 실수 q1, q2를 분수 형태로 바꿔 분자와 분모를 각각 변수 x(x1, y1), y(y1, y2)에 할당하는 함수
def mkFrac(q1, q2):
    global x1, y1, x2, y2
    
    # 실수 q1을 분수 형태로 변환
    q1_count = len(str(q1).split(".")[1])
    q1_denominator = 10 ** q1_count
    q1_numerator = int(q1 * q1_denominator)

    # 약분해서 x1, y1에 저장
    q1_division = math.gcd(q1_denominator, q1_numerator)
    x1 = int(q1_numerator / q1_division)
    y1 = int(q1_denominator / q1_division)
 
    # 실수 q2를 분수 형태로 변환
    q2_count = len(str(q2).split(".")[1])
    q2_denominator = 10 ** q2_count
    q2_numerator = int(q2 * q2_denominator)

    #약분해서 x2, y2에 저장
    q2_division = math.gcd(q2_denominator, q2_numerator)
    x2 = int(q2_numerator / q2_division)
    y2 = int(q2_denominator / q2_division)

# 분수 덧셈 계산 함수
def addFrac(q1, q2):
    global x1, y1, x2, y2
    global add_x, add_y
    
    mkFrac(q1, q2)

    # 통분해서 더하기
    common_denominator = math.lcm(y1, y2)
    q1_multiply = int(common_denominator / y1)
    q2_multiply = int(common_denominator / y2)
    add_numerator = x1 * q1_multiply + x2 * q2_multiply

    # 약분해서 계산 결과 저장
    division = math.gcd(common_denominator, add_numerator)
    add_x = int(add_numerator / division)
    add_y = int(common_denominator / division)

# 분수 뺄셈 계산 함수
def subFrac(q1, q2):
    global x1, y1, x2, y2
    global sub_x, sub_y
    
    mkFrac(q1, q2)

    # 통분해서 빼기
    common_denominator = math.lcm(y1, y2)
    q1_multiply = int(common_denominator / y1)
    q2_multiply = int(common_denominator / y2)
    sub_numerator = x1 * q1_multiply - x2 * q2_multiply

    # 약분해서 계산 결과 저장
    division = math.gcd(common_denominator, sub_numerator)
    sub_x = int(sub_numerator / division)
    sub_y = int(common_denominator / division)

# 분수 나눗셈 계산 함수
def divFrac(q1, q2):
    global x1, y1, x2, y2
    global div_x, div_y

    mkFrac(q1, q2)

    # 나눗셈 계산
    div_denominator = y1 * x2
    div_numerator = x1 * y2

    # 약분해서 결과 저장
    division = math.gcd(div_denominator, div_numerator)
    div_x = int(div_numerator / division)
    div_y = int(div_denominator / division)

q1 = float(input("실수1 입력: "))
q2 = float(input("실수2 입력: "))

mkFrac(q1, q2)
print("")
print(f"{q1}의 분자 분모는 각각 {x1}, {y1}입니다.")
print(f"{q2}의 분자 분모는 각각 {x2}, {y2}입니다.")

addFrac(q1, q2)
print("")
print(f"{q1}과 {q2}의 합의 분자 분모는 각각 {add_x}, {add_y}입니다.")

subFrac(q1, q2)
print("")
print(f"{q1}과 {q2}의 차의 분자 분모는 각각 {sub_x}, {sub_y}입니다.")

divFrac(q1, q2)
print("")
print(f"{q1}과 {q2}를 나눈 결과의 분자 분모는 각각 {div_x}, {div_y}입니다.")
