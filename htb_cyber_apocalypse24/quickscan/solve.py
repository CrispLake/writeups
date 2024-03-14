import gdb

gdb.execute("file ./chal")
gdb.execute("starti")
gdb.execute("si 28")
gdb.execute("x/24bx $rsp")