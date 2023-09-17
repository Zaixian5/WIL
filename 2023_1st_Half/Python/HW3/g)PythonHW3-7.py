# 7-7. 무한 다항식의 나눗셈을 계산하는 제너레이터 만들기

def div(g1, g2):
    # 나눗셈 결과를 담을 제너레이터 생성
    def generator():
        # g1과 g2의 다음 항을 초기화
        a = next(g1)
        b = next(g2)
        while True:
            # 다음 항을 계산하고 yield
            yield a / b

            # g1의 다음 항을 가져오기 위해 next 호출
            a = next(g1)

            # g2의 다음 항을 가져오기 위해 next 호출
            b = next(g2)

            # g1이나 g2 중 하나라도 StopIteration이 발생하면 종료
            # 어느 한 제너레이터가 끝나면 더 이상 나눗셈을 진행하지 않음
            if a is None or b is None:
                break

    return generator()

# 문제7 테스트1
# 제너레이터로 표현된 무한 다항식 생성 (5개 항만 생성)
g1 = (2 ** i for i in range(5))  # 1, 2, 4, 8, 16, ...
g2 = (3 ** i for i in range(1, 6))  # 3, 9, 27, 81, 243, ...

# 나눗셈 수행
result = div(g1, g2)

# 결과 출력 (5개 항만 출력)
for i in range(5):
    print(next(result))

# 문제7 테스트2
# 제너레이터로 표현된 무한 다항식 생성 (5개 항만 생성)
g1 = (3 ** i for i in range(5))  # 1, 3, 9, 27, 81, ...
g2 = (5 ** i for i in range(1, 6))  # 5, 25, 125, 625, 3125, ...

# 나눗셈 수행
result = div(g1, g2)

# 결과 출력 (5개 항만 출력)
for i in range(5):
    print(next(result))