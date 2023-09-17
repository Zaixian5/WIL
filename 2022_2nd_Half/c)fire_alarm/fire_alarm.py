# 11월 17일 화재경보기 작동하기
# 저장명: fire_alarm.py

import turtle as t

color_status = ['white', 'blue', 'red']
alert_status = ['정상', '주의', '화재']
tempc = 50

def check_fire():
    if tempc < 80:
        status = 0  # 정상
    elif tempc < 120:
        status = 1  # 주의
    else:
        status = 2  # 위험
    
    t.clear()
    t.home()
    t.pendown()
    t.fillcolor(color_status[status])
    t.begin_fill()
    t.circle(20)
    t.end_fill()
    t.penup()
    t.goto(-22, 50)
    t.write("%s : %d" % (alert_status[status], tempc))

def key_up():
    global tempc
    if tempc < 80:
        tempc = tempc + 5
    else:
        tempc = tempc + 10
    check_fire()

def key_down():
    global tempc
    if tempc < 80:
        tempc = tempc - 5
    else:
        tempc = tempc - 10
    check_fire()

t.setup(300, 300)
s = t.Screen()
t.hideturtle()
t.speed(0)
check_fire()

s.onkey(key_up, "Up")
s.onkey(key_down, "Down")
s.onkey(s.bye, "q")
s.listen()









        
