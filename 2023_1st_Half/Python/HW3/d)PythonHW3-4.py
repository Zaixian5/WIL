# 3-4. 동전 계산 문제에서 지불방법이 여러개인 경우를 모두 표시하도록 만들기

def coins4(v, cset):
    if 1 not in cset:
        raise ValueError("집합에 1을 포함해야 합니다.")
    
    memo = {0: [(0, {})]}
    for i in range(1, v+1):
        memo[i] = []
        
        for c in cset:
            if i >= c:
                for prev_min_coins, prev_coin_dict in memo[i - c]:
                    new_min_coins = prev_min_coins + 1
                    new_coin_dict = dict(prev_coin_dict)
                    
                    if c in new_coin_dict:
                        new_coin_dict[c] += 1
                    else:
                        new_coin_dict[c] = 1
                    
                    memo[i].append((new_min_coins, new_coin_dict))
        
        min_coins = float('inf')
        for coins, _ in memo[i]:
            min_coins = min(min_coins, coins)
        
        memo[i] = [(coins, coin_dict) for coins, coin_dict in memo[i] if coins == min_coins]
    
    unique_results = []
    for coins, coin_dict in memo[v]:
        if coin_dict not in unique_results:
            unique_results.append(coin_dict)
    
    return min_coins, unique_results

# 문제4 테스트1
print(coins4(10, {7, 5, 3, 1}))

# 문제4 테스트2
print(coins4(30, {1, 5, 7, 9}))