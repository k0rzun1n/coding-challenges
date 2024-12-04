# "set PYTHONPATH=. && py -u"
import builtins
builtins.cc = type('',(object,),{"__sub__": lambda s,o:print(o) or s})()
# cc-"qweqwe"-(70000-580)-101


