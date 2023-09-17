# 0부터 9까지 글자와 A부터 Z까지의 글자를 컴퓨터 정수값으로 변환하는 함수
# 0부터 9는 정수 0부터 9로, A부터 Z는 정수 10부터 35로
def digit2int(c):
  return int(c, 36)

char = input("정수로 변환할 글자 입력(0~9, A~Z): ")
result = digit2int(char)

print("")
print(f"{char}를 정수로 변환하면 {result}입니다.")
