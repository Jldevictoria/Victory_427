#!/usr/bin/python
import wave
import sys
from bitstring import *
from binascii import *
from struct import *
inf = sys.argv[1]
outf = sys.argv[2]
w = wave.open(inf, "rb")
binary_data = w.readframes(w.getnframes())
s = binary_data
inf = inf[:-4]
f = open(outf, 'w')
f.write("// Joseph DeVictoria\n")
f.write("// Taylor Simons\n")
f.write("// ECEN 427 2014\n\n")
f.write("int "+inf+"_soundData[] = {\n")
k = 1
for i in s:
	if k == 10:
		f.write(str(unpack("<b", i)[0])+',\n')
		k = 1
	else:
		f.write(str(unpack("<b", i)[0])+',')
		k+=1
	temp=''
f.write("};\n\n")
frames = w.getnframes()
rate = w.getframerate()
f.write(inf+"_numberOfSamples = "+str(frames)+"\n\n")
f.write(inf+"_sampleRate = "+str(rate)+"\n")
w.close
f.close
