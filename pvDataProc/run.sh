#!/bin/bash
xterm -e "python3 count.py | ./mbx_daemon" &
xterm -e ./dataproc &
xterm -e ./pvs &
pvbrowser &

