

load_i	 1     REM i = 1
store_i	 M0

load_i   M0    REM i <= 20
cmp_i    20
jgt      +8    REM jump i>20

load_i   M0    REM cout i
out_i
out_s    "\n"
load_i   M0    REM i++
add_i    1
store_i  M0
jump     -9    REM loop

end
