import Problem_300_271_300
import smartphone as sphone

Problem_300_271_300.print_star(5)
Problem_300_271_300.print_star(10)


class iPhone(sphone.Smartphone):
    def __init__(self):
        self.os = 'iOS'
        self.version = 'iOS9'
        self.model = 'iPhone6(s)'

    def getOS(self):
        return "OS:" + self.os


phone = iPhone()

print(phone.getOS())
print(phone.getVersion())
print(phone.getModel())
