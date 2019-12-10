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
    for i in range(1, 5):
        print(i)

    for i in range(5):
        print(i)

    for i in range(1, 10, 2):
        print(i)

    for i in range(9, 0, -3):
        print(i)

    i = 0
    while i < 10:
        print(i)
        i += 1
if 0:  # 277 파이썬 문자열 사용하기
    Korea = "대한민국"
    IT = 'Google을 넘어 세계 강국으로'

    print(Korea)
    print(IT)

    Korea = """아름다운
우리나라
대한민국"""

    IT = """Google을 넘어 
세계 강국으로"""

    print(Korea)
    print(IT)

    string = "You call it love"
    print(string[0:3])
    print(string[:8])
    print(string[9:11])
    print(string[12:])

    y = 2020
    m = 12
    d = 25
    christmas = "Christmas - {0}년도{1}월{2}일".format(y, m, d)
    print(christmas)

    stra = "Korea"
    strb = "Japan"

    if stra > strb:
        print(stra)

    print('www.example.com'.strip('cmowz.'))
    print('  www.example.com'.lstrip())
    print('http://www.example.com'.startswith('http'))
    print('www.example.com'.endswith('com'))
    print('i am a boy'.title())
    print('you are a girl'.upper())
    print('You Are A Girl'.lower())
    print('http://www.google.com'.find('google'))
    print('http://www.come.com'.rfind('com'))
    print('http://www.A.com'.replace('http', 'https'))
    print('Android,iOS,Windows 10 Mobile'.split(','))
if 0:  # 278 리스트(배열) 사용하기
    gold = ["박인비", "오혜리", "김소희", "구본찬", "장혜진", "기보배", "진종오", "박상영", "최미선",
            "김우진", "이승윤"]
    silver = ["김종현", "안바울", "정보경"]
    iron = ["차동민", "이태운", "정경은", "신승찬", "김태훈", "김형우", "김정환", "곽동한", "윤진희",
            "기보배", ]

    print("금메달 리스트:")
    print(gold)
    print("은메달 리스트:")
    print(silver)
    print("동메달 리스트:")
    print(iron)

    print(gold[0])
    print(silver[1:2])
    print(iron[:5])

    gold[1] = "오혜리2"
    print(gold)

    medal = gold + silver + iron
    print(medal)

    medalcount = len(gold) + len(silver) + len(iron)
    print(medalcount)
if 0:  # 279 튜플 사용하기
    smartos = ["Android OS", "iOS", "Windows 10 Mobile"]

    print("튜플 테스트")
    print(smartos)

    smartos[1] = "iOS 10 Coming this fall"
    print(smartos)

    market = 1, 2, 3
    Apple, Google, Microsoft = market
    print(Apple)
    print(Google)
    print(Microsoft)
if 1:  # 280 딕셔너리 사용하기
    sports = {}