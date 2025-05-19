REM
REM UIC 1.0 program to compute exercise target heart rates
REM based on CDC recommendations
REM
REM Author: Prof. Hummel, U. of Illinois Chicago, Fall 2020
REM

out_s 	"Enter your age: "
in_i
store_i	M0

load_i  220
sub_i   M0
store_i M1

out_s	"Maximum safe heart rate: "
load_i	M1
out_i
out_s	"\n"

load_i  M1
div_i   2
store_i M2

out_s	"Minimum target heart rate: "
load_i	M2
out_i
out_s	"\n"

load_i  M1
mult_i  64
div_i   100
store_i M3

load_i  M1
mult_i  76
div_i   100
store_i M4

out_s	"Moderate intensity targets: "
load_i	M3
out_i
out_s   "-"
load_i  M4
out_i
out_s	"\n"

load_i  M1
mult_i  77
div_i   100
store_i M5

load_i  M1
mult_i  93
div_i   100
store_i M6

out_s	"High intensity targets: "
load_i	M5
out_i
out_s   "-"
load_i  M6
out_i
out_s	"\n"

out_s	"Done"
out_s	"\n"

end
