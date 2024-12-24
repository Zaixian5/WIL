# 프로젝트: 성적표 출력하기
# 저장명: score.py

a = []

with open('C:\\Users\\Admin\\Desktop\\data.txt', 'r') as f:
    for i in range(10):
        a.append(f.readline().split()) 

    for i in range(10):
        a[i][1] = int(a[i][1]) # 국어 점수 정수형변환
        a[i][2] = int(a[i][2]) # 영어 점수 정수형변환
        a[i][3] = int(a[i][3]) # 수학 점수 정수형변환

        a[i].append(a[i][1]  + a[i][2] + a[i][3]) # a[i][4] -> 총점
        a[i].append(a[i][4] / 3) # a[i][5] -> 평균
       
        if a[i][5] >= 90:
            grade = 'A'
        elif a[i][5] >= 80:
            grade = 'B'
        elif a[i][5] >= 70:
            grade = 'C'
        elif a[i][5] >= 60:
            grade = 'D'
        else:
            grade = 'F'

        a[i].append(grade)

# 과목별 평균 구하기

kt = 0 # 국어 총점 
et = 0 # 영어 총정
mt = 0 # 수학 총점

for i in range(10):
    kt += a[i][1]
    et += a[i][2]
    mt += a[i][3]

# 파이썬에 출력하기

print('                  ** 성적표 **                  ')
print('                                    담당: 사재헌')
print('================================================')
print('이  름   국어   영어   수학   총점   평균   학점')
print('================================================')

for i in range(10):
    print('%s    %d     %d     %d    %d    %.1f    %s'
          % (a[i][0], a[i][1], a[i][2], a[i][3], a[i][4], a[i][5], a[i][6])
          )
print('================================================')
print('평  균:  %.1f   %.1f   %.1f          %.1f'
      % (kt / 10, et / 10, mt / 10, (kt + et + mt) / 30)
      )

# report.txt 파일로 만들기

with open('C:\\Users\\Admin\\Desktop\\report.txt', 'w') as f2:
    print(' ', file = f2)
    
    print('                  ** 성적표 **                  ', file = f2)
    print('                                    담당: 사재헌', file = f2)
    print('================================================', file = f2)
    print('이  름   국어   영어   수학   총점   평균   학점', file = f2)
    print('================================================', file = f2)

    for i in range(10):
        print('%s    %d     %d     %d    %d    %.1f    %s'
              % (a[i][0], a[i][1], a[i][2], a[i][3], a[i][4], a[i][5], a[i][6]),
              file = f2)
    print('================================================', file = f2)
    print('평  균:  %.1f   %.1f   %.1f          %.1f'
          % (kt / 10, et / 10, mt / 10, (kt + et + mt) / 30),
          file = f2)






















    
