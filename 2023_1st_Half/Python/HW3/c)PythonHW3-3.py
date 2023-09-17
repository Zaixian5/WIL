# 3-3. 동전 계산 문제에서 어떤 종류의 동전을 몇 회 사용하는지도 알려주는 함수로 만들기

# 지불 방법이 여러개일지라도 하나만 표시하도록 설정

def coins3(v, cset):
    if 1 not in cset:
        raise ValueError("집합에 1을 포함해야 합니다.")
    
    memo = {0: (0, {})}
    for i in range(1, v+1):
        memo[i] = (float('inf'), {})  # 무한대로 초기화
        
        for c in cset:
            if i >= c:
                curr_min_coins, curr_coin_dict = memo[i - c]
                new_min_coins = curr_min_coins + 1
                new_coin_dict = dict(curr_coin_dict)
                
                if c in new_coin_dict:
                    new_coin_dict[c] += 1
                else:
                    new_coin_dict[c] = 1
                
                if new_min_coins < memo[i][0]:
                    memo[i] = (new_min_coins, new_coin_dict)
    
    return memo[v]

# 문제3 테스트1
print(coins3(15, {7, 5, 2, 1}))

# 문제3 테스트2
print(coins3(50, {9, 3, 2, 1}))