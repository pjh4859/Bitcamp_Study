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
    for i in range(1, 10, 2):
        print(i)

    for i in range(9, 0, -3):
        print(i)

    i = 0
    while i < 10:
        print(i)
        i += 1
if 0:  # 277 파이썬 문자열 사용하기
    Korea = "대하님ㄴ국"
    IT = 'Google을 넘어 세계 강국으로'

    print(Korea)
    print(IT)

    Korea = """아름다운
우리나라
대한민국"""

    IT = """Google을 넘어 
세계 강국으로"""
    Korea = """아름다운
    우리나라
    대한민국"""

    IT = """Google을 넘어 
    세계 강국으로"""

    print(Korea)
    print(IT)

    string = "You call it love"
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
if 0:  # 280 딕셔너리 사용하기
    sports = {}
    sports['양궁'] = '한국 종합 우승'
    sports['펜싱'] = '한국 기력 상승'
    sports['축구'] = '아쉽다'
    sports['유도'] = '잘함'
    sports['사격'] = '세계신기록'
    sports['골프'] = '116년만 금메달'

    print(sports)
    print(sports['골프'])
    print(sports.keys())
    print(sports.values())

    if '양궁' in sports:
        print(sports['양궁'])
    sports.clear()
    print(sports)
if 0:  # 281 날짜 및 시간 구하기
    import time
    import datetime
    import calendar

    today = datetime.date.today()
    print(today)

    today = datetime.datetime.now()
    print(today)

    mydatetime = datetime.datetime(2020, 12, 24, 18, 0, 0)
    print(mydatetime)
    print(mydatetime.weekday())

    mydate = datetime.date(2020, 12, 24)
    print(mydate)

    mytime = datetime.time(18, 30, 25)
    print(mytime)

    today = time.time()
    print(today)

    localtime = time.localtime(time.time())
    print(localtime)
    print(localtime.tm_year)
    print(localtime.tm_mon)
    print(localtime.tm_mday)
    print(localtime.tm_hour)
    print(localtime.tm_min)
    print(localtime.tm_sec)
    print(localtime.tm_wday)

    mycalendar = calendar.month(2020, 12)
    print(mycalendar)
if 0:  # 282 함수 사용하기
    def print_star(star):
        for num in range(0, star, 1):
            print('*', end="")
        print("")


    print_star(5)
    print_star(10)


    def max(a, b):
        if a >= b:
            return a
        return b


    print(max(50, 100))
if 0:  # 283 함수 고급기법 사용하기
    def print_star(*star):
        for star_num in star:
            for num in range(0, star_num, 1):
                print('*', end="")
            print("")


    print_star(1, 2, 3)
    print_star(1, 3, 5, 7, 9)
if 0:  # 284 텍스트 파일 쓰기
    file = open("D:\\Python\\untitled\\b.txt", 'w')
    print(file)

    if not file.closed:
        file.write("아름다운 파이썬\n")
        file.write("우리나라 대한민국\n")
        file.close()
    else:
        print("파일을 열 수 없습니다1")

    try:
        file.open("D:\\Python\\untitled\\b.txt", 'w')
        file.write("아름다운 파이썬\n")
        file.close()
    except:
        print("파일을 열 수 없습니다.")
if 0:  # 285 텍스트 파일 읽기
    try:
        file = open("D:\\Python\\untitled\\a.txt", "rt")
        buff = file.readline()

        while buff != "":
            print(buff.strip())
            buff = file.readline()

        file.close()
    except:
        print("파일을 열 수 없습니다.")
if 0:  # 286 바이너리 파일 쓰기
    import struct

    try:
        file = open("D:\\Python\\untitled\\x.bin", "wb")

        bin_value = struct.pack('i', 2020)
        file.write(bin_value)

        bin_value = struct.pack('f', 3.14)
        file.write(bin_value)

        bin_value = struct.pack('5s', 'Korea'.encode())
        file.write(bin_value)

        bin_value = struct.pack('3s', 'KOR'.encode(encoding='utf-8'))
        file.write(bin_value)

        file.close()
    except:
        print("파일을 열 수 없습니다.")
if 0:  # 287 바이너리 파일 읽기
    import struct

    try:
        file = open("D:\\Python\\untitled\\x.bin", "rb")

        buff = file.read(4)
        print(buff)
        tuple_unpack = struct.unpack('i', buff)
        print(tuple_unpack[0])

        buff = file.read(4)
        tuple_unpack = struct.unpack('f', buff)
        print(tuple_unpack[0])

        buff = file.read(5)
        print(buff)
        tuple_unpack = struct.unpack('5s', buff)
        print(tuple_unpack[0])
        print(tuple_unpack[0].decode())

        buff = file.read(3)
        tuple_unpack = struct.unpack('3s', buff)
        print(tuple_unpack[0].decode(encoding='utf-8'))

        file.close()
    except:
        print("파일을 열 수 없습니다.")
if 0:  # 288 클래스 이해하기
    class Smartphone:
        def __init__(self):
            self.os = 'Android'
            self.version = 'Marshmallow'
            self.model = 'Galaxy Note 7'

        def getOS(self):
            return self.os

        def getVersion(self):
            return self.version

        def getModel(self):
            return self.model


    phone = Smartphone()

    print(phone.getOS())
    print(phone.getVersion())
    print(phone.getModel())
if 0:  # 클래스 정적함수 이해하기
    class Smartphone:

        @staticmethod
        def getOS():
            return "Android"

        @staticmethod
        def getVersion():
            return "Marshmallow"

        @staticmethod
        def getModel():
            return "Galaxy Note 7"


    print(Smartphone.getOS())
    print(Smartphone.getVersion())
    print(Smartphone.getModel())

    phone = Smartphone()
    print(phone.getOS())
if 0:  # 290 클래스 상속과 오버라이딩 이해하기
    class Smartphone:
        def __init__(self):
            self.os = 'Android'
            self.version = 'Marshmallow'
            self.model = 'Galaxy Note 7'

        def getOS(self):
            return self.os

        def getVersion(self):
            return self.version

        def getModel(self):
            return self.model


    class iPhone(Smartphone):
        def __init__(self):
            super().__init__()
            self.os = 'iOS'
            self.version = 'iOS9'
            self.model = 'iPhone6(s)'

        def getOs(self):
            return "OS:" + self.os


    phone = iPhone()
    print(phone.getOS())
    print(phone.getVersion())
    print(phone.getModel())
if 0:  # 291 다중 파일 사용하기
    def print_star(star):
        for num in range(0, star, 1):
            print('*', end="")

        print("")
if 0:  # 292 역삼각형 출력하기
    class Star:
        def __init__(self):
            self.star_from = 10
            self.star_to = 0

        def print_reversestar(self):
            for star_num in range(self.star_from, self.star_to, -1):
                for num in range(0, star_num, 1):
                    print('*', end="")
                print("")


    star = Star()
    star.print_reversestar()
if 0:  # 293 1에서 100까지의 합계 구하기
    class Calc:
        def __init__(self, begin, end):
            self.begin = begin
            self.end = end
            self.hap = 0

        def sum(self):
            for value in range(self.begin, self.end + 1, 1):
                self.hap += value
            return self.hap

        def sum_even(self):
            for value in range(self.begin + 1, self.end + 1, 2):
                self.hap += value
            return self.hap


    class CalcTo(Calc):
        def sum(self, to):
            for value in range(self.begin, to + 1, 1):
                self.hap += value
            return self.hap


    calc = Calc(1, 100)
    print(calc.sum())
    print(calc.sum_even())

    calcto = CalcTo(1, 100)
    print(calcto.sum(1000))
if 0:  # 294 30에서 50 사이의 난수 만들기
    import random

    num = random.random()
    print(num)

    num = random.randint(30, 50)
    print(num)

    num = random.randrange(30, 50, 5)
    print(num)
if 0:  # 295 2진수와 16진수 연산하기
    a = 16
    print(a)

    bin_a = bin(a)
    hex_a = hex(a)

    print(bin_a)
    print(hex_a)

    shift_a = a >> 2
    print(shift_a)

    shift_a = shift_a << 2
    print(shift_a)

    a = 255
    print(a)
    and_a = a & 0b00001010
    print(and_a)
    print(bin(and_a))

    a = 3
    or_a = a | 0b1100
    print(or_a)
    print(bin(or_a))

    a = 0b1010
    xor_a = a ^ 0b1010
    print(xor_a)
    print(bin(xor_a))
if 0:  # 296 TCP/IP 소켓 서버/클라이언트
    import socket

    print('파이썬 TCP/IP 서버 프로그래밍')

    HOST = '127.0.0.11'
    PORT = 10000

    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((HOST, PORT))
    server.listen(1)

    print('클라이언트 접속 대기 중...')
    client, ipinfo = server.accept()

    print('클라이언트 접속됨:', ipinfo)

    buff = client.recv(4096)

    print('데이터 수신:', repr(buff))

    client.close()
    server.close()
if 0:  # 297 HTTP 사용하기
    import http.client, urllib.parse

    conn = http.client.HTTPSConnection("www.python.org")
    conn.request("GET", "/")
    r1 = conn.getresponse()
    print(r1.status, r1.reason)

    data1 = r1.read()
    print(data1)
    # conn.request("GET","/")
    # r1=conn.getresponse()
    # while nor r1.closed:
    # print(r1.read(200)) #200 bytes
    conn.close()

    # HTTP POST
    params = urllib.parse.urlencode({'@number': 12524, '@type': 'issue', '@action':
        'show'})
    headers = {"Content-type": "application/x=www=form-urlencoded",
               "Accept": "text/plain"}

    conn = http.client.HTTPConnection("bugs.python.org")
    conn.request("POST", "", params, headers)
    response = conn.getresponse()
    print(response.status, response.reason)

    data = response.read()
    print(data)

    conn.close()
if 0:  # 298 클라이언트 만들기
    from ftplib import FTP

    ftp = FTP('ftp.debian.org')
    ftp.login()

    ftp.cwd('debian')
    ftp.retrlines('LIST')

    ftp.quit()
if 0:  # 299 SMTP 메일 클라이언트 만들기
    import smtplib

    fromaddr = 'eunchol71@naver.com'
    toaddrs = 'jaehee@khu.ac.kr'

    msg = ("From: %s\r\nTo: %s\r\n\r\n"
           % (fromaddr, ",".join(toaddrs)))
    msg = msg + 'test mail'

    server = smtplib.SMTP('localhost')

    server.sendmail(fromaddr, toaddrs, msg)
    server.quit()
if 0:  # 300 MySQL 데이터베이스 사용하기
    import sqlite3

    conn = sqlite3.connect('example.db')
    c = conn.cursor()

    c.execute('''CREATE TABLE stocks
              (date text,trans text,symbol text,qty real,price real)''')
    c.execute("INSERT INTO stocks VALUES('2006-01-05','BUY','RHAT',100,35.14)")

    conn.commit()
    conn.close()
if 0:  # 300(2)
    import sqlite3

    conn = sqlite3.connect('example.db')
    c = conn.cursor()

    t = ('RHAT')
    c.execute('SELECT*FROM stocks WHERE symbol=?', t)
    print(c.fetchone())

    conn.close()
