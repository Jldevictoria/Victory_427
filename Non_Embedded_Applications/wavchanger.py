#!/usr/bin/python
import wave
from binascii import *
from struct import *
w = wave.open("ufo_highpitch.wav", "rb")
binary_data = w.readframes(w.getnframes())
s = bytes(binary_data)
f = open('ufo_highpitch.c', 'w')
f.write("// Joseph DeVictoria\n")
f.write("// Taylor Simons\n")
f.write("// ECEN 427 2014\n\n")
f.write("int ufo_highpitch[] = {\n")
j = 0
temp=''
for i in s:
	temp+=i
	if j == 4:
		f.write('0x'+temp+'\n')
		temp=''
		j = 0
	else:
		j+=1
f.write("};\n")
w.close
