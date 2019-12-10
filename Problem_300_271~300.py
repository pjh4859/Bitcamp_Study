if 0:  # 272 변수형 사용하기
    x = 1
    y = 2

    z = x + y
    x = 3.14

    print(z)
    print(x)

    x = 588
    b = 1000000000
    e = 1110

    MC = x * b * e
    print(MC)
if 0:  # 273 연산자 사용하기
    x1 = 10
    x2 = 20
    x3 = 30
    x4 = 40
    x5 = 50

    y1 = x1 + 30
    y2 = x2 - 30
    y3 = x3 * 30
    y4 = x4 / 30
    y5 = x5 % 30

    print(y1)
    print(y2)
    print(y3)
    print(y4)
    print(y5)

    a = 5
    b = 7
    c = a & b

    print(bin(a))
    print(bin(b))
    print(c)
    print(bin(c))

    h = 255
    print(hex(h))
if 0:  # 274 값을 입력받고 출력하기
    print("첫 번째 수를 입력하세요:")
    a = input()

    print("두 번째 수를 입력하세요")
    b = input()

    c = int(a) * int(b)

    print("a와 b를 곱한 값:")
    print(c)

    print("이름을 입력하세요:")
    name = input()

    print("나의 이름은" + name + "입니다")
if 0:  # 275 조건문 사용하기(if~else)
    x = 1
    y = 2

    if x < y:
        print("x가 y보다 작습니다.")
        print(x)
        print(y)
    elif x == y:
        print("x와 y가 같습니다.")
        print(x)
        print(y)
    else:
        print("x가 y보다 큽니다.")
        print(x)
        print(y)
    z = x + y
if 0:  # 276 순환문 사용하기(for, while)
    for i in range(1,5):
        print(i)

    for i in range(5):
        print(i)

    for i in range(1,10,2):
        print(i)

    for i in range(9,0,-3):
        print(i)

    i=0
    while i<10:
        print(i)
        i+=1
if 1:  # 277 파이썬 문자열 사용하기
    Korea="대하님ㄴ국"
    IT='Google을 넘어 세계 강국으로'

    print(Korea)
    print(IT)

    Korea="""아름다운
    우리나라
    대한민국"""

    IT="""Google을 넘어 
    세계 강국으로"""

    print(Korea)
    print(IT)

    string="You call it love"
    print(string[0:3])
    print(string[:8])
    print(string[9:11])
    print(string[12:])

    y=2020
    m=12
    d=25
    christmas="Christmas - {0}년도{1}월{2}일".format(y,m,d)
    print(christmas)

    stra="Korea"
    strb="Japan"

    if stra>strb:
        print(stra)

    print('www.example.com'.strip('cmowz'))
