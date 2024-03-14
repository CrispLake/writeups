#!/bin/bash

chmod +x chal
(sleep 0.2 && pkill gdb) & gdb -x solve.py | grep fff > tmp
head -n 3 tmp | python3 parser.py > answer
