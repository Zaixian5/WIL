# 3-1. 동전 계산 문제
# 주어진 액면가의 동전으로만 주어진 금액을 지불하여 계산할 수 있는 동전의 최소 개수를 구하는 알고리즘 만들기

# 예) 동전 액면가가 7원, 5원, 2원, 1원뿐이고 지불할 금액은 15원일 때, 계산할 수 있는 동전의 최소 개수는?
# 정답: 3회(7원 2번, 1원 1번)

# 메모해두기(Memoization) 알고리즘 사용
# 계산 단순화를 위해 동전 액면가 집합에 1은 무조건 포함되도록 설정

def coins1(v, cset):
    if 1 not in cset:
        raise ValueError("집합에 1을 포함해야 합니다.")

    memo = {}

    def f(n):
        if n == 0:
            return 0

        if n in memo:
            return memo[n]

        coins = float('inf')  # 초기값으로 무한대를 설정

        for c in cset:
            if n >= c:
                coins = min(coins, f(n - c))

        memo[n] = coins + 1
        return memo[n]

    return f(v)

# 문제1 테스트1
print(coins1(30, {7, 5, 2, 1}))

# 문제1 테스트2
print(coins1(50, {9, 3, 2, 1}))

# 문제1 테스트3
# print(coins1(50, {2, 3, 5, 7})) # 집합에 1이 없어 ValueError가 발생함