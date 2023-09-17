# 3-2. 동전 계산 문제를 반복문으로 바꾸기

def coins2(v, cset):
    if 1 not in cset:
        raise ValueError("집합에 1을 포함해야 합니다.")
    
    memo = {0: 0}
    for i in range(1, v+1):
        memo[i] = float('inf')  # 무한대로 초기화
        
        for c in cset:
            if i >= c:
                memo[i] = min(memo[i], memo[i - c] + 1)
    
    return memo[v]

# 문제2 테스트1
print(coins2(30, {7, 5, 2, 1}))

# 문제2 테스트2
print(coins2(50, {9, 3, 2, 1}))

# 문제2 테스트3
# print(coins1(50, {2, 3, 5, 7})) # 집합에 1이 없어 ValueError가 발생함