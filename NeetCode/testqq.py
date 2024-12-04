
class ppp2(object):
    def __neg__(self):
        print ()
        return self
    def __invert__(self):
        # print ("----------------")
        print ("\n----------------",end="")
        return self
    def __sub__(self, other):
        print ()
        print (other, end=" ")
        return self
    def __add__(self, other):
        print (other,end =" ")
        return self
pp2 = ppp2()

~~pp2-3-5+8+7
pp2-"qwelk"


class ppp(object):
    def __neg__(self):
        print ()
        return self
    def __invert__(self):
        print ("----------------")
        # print ("\n----------------",end="")
        return self
    def __sub__(self, other):
        print (other)
        return self
    def __add__(self, other):
        print (other,end =" ")
        return self
pp = ppp()

~~pp-3-5+8+7
pp-"qwelk"

def z(s, o):
    print (o)
    return s
def x(s):
    print ("------------",end=" ")
    return s
obz = type('',(object,),{"__sub__": z,"__pos__": x,"__neg__": x})()
+++-obz-"qweqwe"-(55555)-101

obj = type('',(object,),{"__sub__": lambda s,o:print(o) or s})()
obj-123123-6

pp+""

print(12,34,56,sep="-")



