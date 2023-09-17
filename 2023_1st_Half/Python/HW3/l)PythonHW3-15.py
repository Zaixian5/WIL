# 3-15. 터틀 그래픽을 활용하여 나선 형태의 그림을 그리는 재귀함수 만들기

# Google colab notebook 환경에서 작성한 코드입니다. 다른 파이썬 개발환경에서는 작동이 원활하지 않을 수 있습니다.

%pip install ColabTurtlePlus

from ColabTurtlePlus.Turtle import *

def draw_coloredTwister(col1, col2, len):
  t.pencolor(col1)
  draw_spiral(t, len)

  t.pencolor(col2)
  t.penup()  # 펜을 들어서 이동
  t.goto(10, 10)  # 파란색 선 시작 위치로 이동
  t.pendown()  # 펜 내려서 그리기
  draw_spiral(t, len - 20)

# 문제 15번 테스트
clearscreen()
setup(500,500) # 500x500 그림을 그릴 공간
showborder() # 그림 그릴 공간에 테두리를 보이게

t = Turtle()

draw_coloredTwister('red', 'blue', 200)