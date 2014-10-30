// Joseph DeVictoria
// Taylor Simons
// ECEN 427 2014

int shoot_soundData[4080] = {
129,99,103,164,214,129,31,105,204,118,
55,92,140,225,152,61,84,154,184,101,
75,129,209,135,47,94,125,207,166,72,
79,135,195,118,68,122,205,136,64,106,
143,173,105,54,122,200,133,74,106,215,
236,91,43,84,163,115,34,81,150,209,
184,198,191,113,95,12,0,79,167,111,
120,238,255,255,118,0,0,0,0,0,
89,236,255,255,255,255,190,0,0,0,
20,170,161,137,255,255,255,181,37,0,
0,15,0,60,167,255,255,255,255,255,
60,0,0,41,60,44,128,211,255,255,
255,150,51,12,0,0,10,136,201,208,
236,255,255,209,0,0,0,15,16,31,
128,255,255,255,255,252,144,0,0,0,
77,68,75,171,255,255,255,233,139,53,
0,0,9,106,77,123,209,255,255,255,
146,68,7,0,0,0,136,166,159,219,
255,255,255,82,0,0,0,0,0,81,
214,225,229,255,255,255,115,0,0,0,
75,63,47,126,209,255,255,255,222,119,
54,0,0,0,112,133,103,185,255,255,
255,222,136,74,0,0,0,102,96,98,
177,255,255,255,255,191,119,0,0,0,
44,125,116,122,222,255,255,255,236,98,
50,0,0,0,17,129,208,164,194,255,
255,255,198,19,0,0,0,0,40,154,
205,191,209,255,255,255,147,74,20,0,
0,0,112,140,119,180,255,255,255,236,
211,122,0,0,0,33,85,81,123,207,
255,255,255,255,255,132,0,0,0,29,
31,33,115,184,255,255,248,255,255,226,
33,0,0,0,55,44,58,128,215,255,
243,255,255,255,226,36,0,0,0,12,
31,98,170,232,225,228,255,255,255,140,
39,0,0,0,0,13,96,192,192,174,
242,255,255,255,207,50,0,0,0,0,
0,70,149,232,192,191,248,255,255,236,
140,40,0,0,0,0,24,118,208,167,
163,224,255,255,255,209,137,63,10,0,
0,0,88,120,115,153,181,253,255,255,
228,239,219,87,0,0,0,0,22,54,
130,204,200,177,238,255,255,231,208,137,
75,0,0,0,0,94,105,112,178,225,
204,215,255,255,255,201,112,44,10,0,
0,0,91,101,115,167,214,245,232,216,
255,255,225,150,63,23,0,0,0,40,
101,113,140,198,216,198,219,255,255,233,
180,137,81,17,0,0,0,64,78,108,
154,197,240,212,207,233,255,255,209,144,
71,36,0,0,0,22,103,106,136,170,
200,248,221,212,233,255,255,195,112,37,
6,0,0,0,27,126,128,139,173,190,
224,243,221,214,233,255,221,144,54,2,
0,0,0,0,67,154,177,161,173,171,
214,250,221,211,225,243,204,122,48,9,
3,0,0,2,75,154,167,160,177,202,
218,195,195,221,249,235,188,143,105,53,
0,0,0,15,63,79,133,166,202,215,
174,160,191,240,229,205,200,207,204,109,
20,0,0,0,0,19,89,164,174,163,
168,187,216,183,171,202,211,240,212,171,
154,113,68,0,0,0,0,16,54,115,
152,200,214,178,157,176,201,192,177,195,
218,208,168,136,87,55,2,0,0,0,
55,77,108,152,180,211,198,166,170,187,
195,181,185,205,218,174,149,132,91,60,
0,0,0,3,64,88,108,159,198,197,
181,167,177,194,173,159,184,190,214,202,
160,153,140,103,34,0,0,3,6,19,
71,115,166,204,184,170,183,197,166,144,
152,180,204,194,174,180,185,157,132,96,
60,36,0,0,0,24,78,105,125,156,
185,202,177,168,168,181,170,142,154,180,
201,181,167,168,171,170,128,85,44,30,
16,0,3,22,58,120,137,149,173,176,
194,185,164,156,156,170,146,136,161,185,
191,171,156,163,168,142,108,84,60,17,
0,7,29,48,55,85,128,171,183,171,
178,187,178,160,147,152,160,146,133,149,
168,188,170,154,159,159,156,130,109,96,
68,23,5,13,23,50,71,81,106,146,
168,188,191,173,171,168,174,161,139,139,
147,144,132,142,159,176,174,160,153,150,
147,150,128,109,91,53,44,34,15,24,
40,70,82,96,126,149,180,184,178,173,
174,177,166,144,144,149,150,137,126,129,
143,149,153,156,163,168,149,139,136,135,
136,118,106,92,74,46,26,31,44,55,
60,75,91,119,146,156,166,173,183,183,
168,161,159,159,156,142,139,143,143,132,
128,130,139,144,137,143,152,163,160,147,
140,133,136,129,116,112,118,112,89,68,
50,46,53,53,58,67,84,105,105,113,
136,156,170,171,173,176,177,167,160,153,
153,152,140,139,142,140,140,130,132,129,
137,133,128,128,135,140,142,143,147,150,
146,136,130,129,126,128,116,111,113,120,
119,87,46,13,0,6,53,96,139,161,
200,255,255,174,82,58,55,105,219,208,
82,71,70,112,235,204,79,70,71,120,
239,207,79,68,67,118,242,204,78,65,
65,112,242,207,78,64,60,109,243,211,
77,58,57,103,245,216,81,60,58,99,
232,225,82,53,58,88,221,236,98,53,
58,81,205,250,118,51,55,72,183,255,
139,51,57,63,167,255,164,55,54,57,
143,255,191,58,53,55,115,255,214,75,
51,55,96,232,243,96,44,54,78,200,
255,133,47,57,63,163,255,177,53,55,
55,122,255,215,64,47,51,98,238,245,
98,46,60,75,191,255,150,46,53,55,
142,255,201,58,48,50,101,243,243,91,
44,51,70,190,255,152,46,54,58,129,
255,212,68,43,50,92,222,255,116,43,
54,61,164,255,187,51,46,53,102,248,
246,94,41,54,65,176,255,174,48,46,
54,113,255,236,81,40,54,72,177,255,
168,47,48,58,111,252,245,89,46,51,
71,176,255,180,50,46,54,101,235,255,
106,41,54,64,152,255,207,63,39,51,
88,202,255,140,40,48,55,120,255,240,
82,40,53,68,163,255,191,51,46,50,
94,214,255,136,40,53,57,120,255,242,
88,41,54,70,156,255,207,60,43,53,
85,190,255,166,46,47,60,101,222,255,
125,41,48,61,122,255,243,95,37,51,
70,144,255,221,67,41,54,75,164,255,
200,55,43,53,84,184,255,177,50,46,
57,95,201,255,156,47,47,60,101,216,
255,139,44,50,61,112,224,255,126,44,
51,65,113,229,255,122,39,48,63,115,
236,255,120,47,48,64,119,231,255,118,
43,50,68,116,229,255,128,46,47,67,
112,219,255,135,47,53,63,108,205,255,
154,50,48,61,98,192,255,170,50,50,
58,92,173,255,195,57,39,46,77,149,
255,208,65,34,51,78,137,255,233,79,
41,50,72,120,232,255,112,43,47,67,
106,201,255,160,47,47,60,92,170,255,
200,63,46,55,82,142,255,242,91,48,
50,75,118,212,255,146,48,47,63,101,
167,255,201,64,47,57,84,136,243,253,
106,44,55,71,111,188,255,177,55,47,
55,91,146,252,243,92,47,54,77,113,
191,255,168,54,48,63,92,144,250,243,
96,51,50,74,106,184,255,185,57,48,
54,87,133,233,255,116,50,51,65,105,
164,255,214,67,48,53,84,118,200,255,
160,55,51,58,95,140,242,252,108,48,
51,67,101,159,255,216,71,50,50,81,
113,180,255,187,57,47,53,88,122,205,
255,153,50,48,61,96,135,226,255,123,
51,53,65,98,144,242,240,102,48,48,
72,103,146,255,232,84,50,53,74,103,
156,255,222,84,51,54,79,106,159,255,
224,78,53,54,75,106,154,255,226,85,
51,54,75,105,152,255,228,89,51,54,
74,106,147,245,238,106,50,50,74,103,
139,231,250,126,53,53,65,101,129,208,
255,147,54,53,61,91,120,191,255,177,
61,47,57,87,115,164,255,211,71,54,
53,78,109,146,243,240,108,55,55,65,
105,128,202,255,156,58,51,58,98,115,
171,255,208,74,51,53,79,112,143,228,
253,128,55,51,64,102,122,181,255,195,
67,48,57,89,111,143,233,249,123,58,
55,68,102,119,176,255,195,72,51,58,
84,112,136,216,255,150,55,51,60,92,
115,159,253,229,99,54,58,72,103,123,
178,255,195,68,53,60,81,113,136,207,
255,164,61,51,58,89,119,144,225,255,
137,58,54,64,94,119,154,239,240,112,
54,58,68,103,119,156,246,224,96,46,
48,65,101,118,159,246,224,94,50,55,
65,106,122,159,248,221,99,51,55,68,
105,126,156,243,228,108,55,51,70,101,
122,154,231,242,128,55,55,65,98,119,
144,215,255,152,60,54,63,91,119,136,
194,255,181,64,51,63,85,109,126,171,
255,218,94,57,58,71,108,122,153,225,
245,140,57,51,67,94,118,136,187,255,
192,74,53,58,82,109,126,154,229,246,
130,57,57,67,95,118,132,183,255,197,
77,54,60,78,106,125,150,214,255,153,
61,54,63,88,116,126,166,242,226,112,
58,50,67,96,120,136,180,255,202,79,
54,55,71,102,122,142,195,255,181,68,
53,60,79,108,125,144,198,255,171,67,
50,57,85,108,126,144,202,255,168,65,
50,58,85,112,128,146,197,253,173,67,
50,57,82,105,123,139,190,253,185,72,
50,58,79,108,126,137,177,249,207,92,
58,60,72,99,119,133,161,229,236,130,
58,51,67,94,113,126,147,198,252,174,
67,50,61,84,105,128,136,164,243,219,
103,58,53,67,96,116,130,146,198,249,
170,68,50,61,79,111,126,133,163,231,
229,125,58,50,64,95,112,129,140,177,
248,202,92,58,54,72,99,118,132,147,
190,249,187,75,53,57,81,106,118,133,
144,200,255,176,67,54,60,81,109,123,
137,143,197,252,173,71,53,60,81,106,
118,137,143,190,250,187,77,54,63,77,
102,119,133,144,177,240,202,99,54,54,
74,98,118,132,137,164,224,232,132,60,
48,63,94,115,126,140,152,195,249,178,
72,55,55,78,109,119,135,144,168,225,
228,129,63,50,63,91,112,129,139,144,
188,239,200,92,60,57,71,101,119,133,
143,149,197,249,180,72,53,57,70,101,
113,129,136,144,197,238,167,68,50,55,
77,102,118,133,140,150,197,240,170,70,
57,60,81,102,116,132,142,143,190,240,
187,87,53,57,72,99,118,132,143,143,
173,229,212,120,60,50,68,91,115,126,
136,140,156,198,239,168,72,55,58,79,
106,120,133,139,143,168,224,218,132,60,
48,67,91,112,125,133,143,146,176,232,
204,108,55,51,71,94,113,126,139,144,
144,181,232,195,103,57,53,71,95,112,
129,140,140,143,174,226,204,115,57,51,
71,94,112,125,135,143,143,164,209,224,
146,64,51,60,79,108,123,133,140,140,
150,184,229,187,89,54,54,72,96,116,
129,139,137,142,160,197,229,156,68,51,
55,78,106,118,130,136,140,146,161,204,
221,149,64,51,63,79,105,120,129,140,
142,139,160,202,221,156,64,53,60,75,
102,120,130,140,144,144,154,188,224,178,
89,55,54,70,95,116,125,137,143,142,
142,164,204,216,144,63,51,63,84,102,
118,130,136,140,143,147,171,214,198,122,
60,48,65,88,112,118,132,139,139,139,
143,168,209,202,128,60,50,65,87,105,
120,132,139,139,143,143,160,198,212,152,
70,54,60,79,101,118,130,137,137,137,
142,146,174,208,194,116,57,51,71,89,
111,123,128,137,140,143,147,146,177,211,
184,109,57,51,70,92,111,123,136,137,
137,143,143,147,171,202,198,128,61,50,
63,85,108,120,132,139,140,143,143,140,
152,184,208,163,89,54,54,74,96,112,
128,132,140,139,143,142,140,157,184,205,
159,84,58,53,72,98,116,129,139,143,
142,146,140,137,147,176,201,180,111,57,
51,70,92,111,125,132,140,142,144,142,
140,139,154,183,205,157,84,54,51,70,
92,106,125,133,136,142,140,137,136,135,
144,180,200,163,98,55,50,75,89,112,
125,133,139,140,143,140,139,137,135,157,
188,195,144,75,55,55,81,99,115,132,
137,143,142,142,139,140,136,136,153,184,
197,153,84,57,55,77,98,115,128,137,
142,140,144,139,136,137,139,142,161,185,
185,139,74,54,64,79,102,116,129,139,
139,140,144,139,140,136,135,136,150,176,
192,161,96,58,53,77,96,115,123,132,
142,139,139,142,142,135,137,135,130,150,
177,188,160,101,58,54,72,91,111,122,
135,137,143,142,142,139,136,137,135,130,
133,153,176,185,149,87,61,55,77,94,
112,129,135,139,139,142,140,139,136,137,
135,132,128,137,161,178,183,132,75,53,
60,81,101,118,130,136,140,139,143,140,
135,136,137,130,129,132,128,140,167,181,
167,115,70,54,67,85,108,119,136,136,
142,142,139,142,140,132,135,132,130,130,
126,128,147,168,183,156,106,68,57,65,
92,106,123,132,136,142,140,140,137,139,
133,129,133,130,125,130,130,126,146,167,
176,160,113,71,55,65,87,105,119,133,
139,140,140,137,140,139,130,133,130,129,
132,132,128,126,130,139,154,167,174,142,
95,67,57,72,95,111,126,132,140,142,
140,140,139,136,137,130,135,132,128,128,
128,126,130,126,132,150,163,173,161,118,
79,60,67,84,102,120,129,135,140,140,
142,142,140,132,135,130,130,133,129,128,
126,130,130,126,125,130,137,156,163,170,
146,102,74,58,72,88,109,122,130,139,
140,140,139,137,136,137,130,135,132,128,
129,128,132,128,126,128,125,130,130,128,
135,150,159,163,163,125,91,65,63,75,
95,115,123,132,140,142,143,140,139,130,
132,129,128,128,123,129,129,125,123,126,
126,126,125,129,125,125,125,126,135,143,
154,159,157,135,102,78,61,71,89,106,
120,129,137,139,143,142,142,139,139,136,
132,128,133,128,128,132,128,126,132,126,
126,130,128,126,126,126,128,128,128,125,
129,130,139,152,152,156,150,126,99,82,
65,70,89,106,120,133,139,140,143,140,
139,137,139,132,136,133,129,128,133,129,
128,132,128,126,125,130,128,132,128,126,
130,126,126,126,125,125,125,126,128,128,
128,128,128,129,142,144,150,147,144,133,
108,91,79,70,77,96,106,123,133,139,
144,140,140,139,137,139,132,153,176,119,
102,113,113,116,130,166,122,99,130,113,
132,166,118,103,130,111,136,166,115,105,
129,111,132,160,120,102,128,115,130,160,
120,101,129,109,130,163,119,105,128,109,
130,164,116,101,129,111,130,164,116,108,
129,111,128,159,119,112,129,111,125,157,
120,116,128,106,126,150,130,123,120,111,
120,139,146,126,113,116,119,133,153,126,
106,120,113,132,160,122,102,128,109,126,
163,115,111,129,109,126,154,125,119,123,
111,120,139,146,126,109,120,116,133,164,
118,102,128,109,126,163,119,108,129,111,
125,149,130,123,118,115,122,132,159,128,
108,125,111,132,164,118,109,129,111,125,
150,132,128,119,112,119,132,159,123,106,
128,111,128,159,120,118,125,112,122,139,
150,126,111,125,115,129,164,116,112,128,
111,125,144,142,128,113,118,116,130,164,
120,106,126,115,126,146,139,123,113,122,
116,130,166,118,106,129,112,125,144,143,
129,116,119,118,130,160,116,116,125,116,
126,133,154,128,109,126,116,128,153,126,
120,120,118,120,132,166,122,109,126,112,
120,136,139,125,109,115,118,123,154,122,
116,120,112,122,129,163,119,108,123,113,
125,136,152,126,112,122,118,122,150,132,
125,119,116,116,130,157,119,118,123,118,
122,132,159,120,109,125,115,125,137,156,
123,111,123,118,126,139,142,128,116,119,
118,128,147,132,122,115,118,123,128,152,
128,120,125,116,116,132,153,120,120,123,
118,122,128,157,122,119,125,119,123,129,
159,116,116,126,119,123,129,159,116,116,
126,119,120,132,159,116,118,125,119,120,
132,154,118,118,123,122,123,129,153,120,
120,123,118,122,128,152,120,125,125,116,
123,126,144,130,120,120,113,122,126,144,
137,122,118,118,123,120,135,147,125,119,
119,122,120,132,154,122,115,123,118,119,
132,154,119,113,123,115,126,132,146,122,
125,122,115,122,125,137,143,126,119,119,
125,120,132,154,122,115,126,123,122,129,
153,122,119,125,119,123,126,139,142,123,
119,119,125,118,132,154,118,118,125,116,
126,126,140,132,125,123,116,123,120,132,
154,122,113,122,118,122,128,146,126,123,
122,115,126,120,132,153,116,116,123,118,
122,128,142,129,123,125,116,123,120,132,
153,116,116,128,116,126,126,139,137,122,
120,119,122,120,132,149,120,125,125,116,
129,122,129,153,122,119,125,119,128,123,
136,144,128,120,118,123,123,129,142,126,
122,125,119,129,118,132,149,119,123,125,
119,129,122,129,153,120,120,125,119,129,
128,129,150,122,122,125,120,129,125,132,
139,122,120,119,125,125,129,140,137,128,
120,120,126,126,126,137,137,123,122,125,
125,126,129,135,137,128,120,120,123,128,
128,136,137,126,120,125,125,125,125,136,
140,128,120,125,125,125,125,132,144,128,
115,119,116,122,123,129,144,118,115,125,
118,126,120,130,144,118,122,128,116,128,
122,129,140,120,125,125,119,128,123,129,
136,132,125,125,122,123,128,128,129,143,
123,122,125,123,128,125,125,142,120,125,
125,123,128,128,128,132,136,126,122,125,
123,128,125,129,143,118,125,125,123,128,
128,128,132,136,126,122,125,123,128,128,
129,142,119,125,125,123,128,128,128,129,
137,126,122,125,125,125,126,129,142,122,
126,125,123,128,125,128,129,142,119,123,
125,123,123,128,128,129,137,125,125,125,
123,128,128,128,132,130,123,125,125,125,
126,126,126,136,126,125,125,123,123,128,
128,128,137,120,123,123,123,125,129,128,
128,137,120,125,125,125,123,128,128,128,
136,123,123,128,119,126,128,128,128,136,
123,123,128,123,123,123,123,129,136,123,
125,125,119,128,128,123,130,135,129,130,
120,125,125,125,125,125,129,135,125,125,
125,125,123,128,128,128,137,120,123,128,
125,128,128,125,125,132,125,125,125,125,
126,126,126,126,126,136,126,120,126,125,
123,128,128,128,136,123,125,125,123,128,
123,128,128,128,133,126,125,125,125,123,
128,123,128,133,123,125,125,123,128,128,
128,128,128,135,123,125,125,125,125,126,
126,126,130,135,125,125,125,125,125,126,
126,126,130,130,125,125,125,125,126,126,
126,126,130,129,125,125,125,125,126,126,
126,126,132,125,125,125,125,126,126,126,
126,130,130,123,129,125,125,129,125,125,
125,125,129,129,125,125,125,125,126,126,
126,130,129,130,126,125,125,125,125,126,
129,125,129,135,125,125,129,125,125,125,
129,125,129,130,123,125,129,125,129,125,
125,125,129,129,130,123,125,125,125,126,
126,126,122,129,128,123,123,123,122,126,
122,126,128,123,128,128,128,123,128,123,
128,128,128,128,128,129,129,125,129,125,
125,125,125,126,126,126,130,125,125,125,
126,126,126,126,128,128,128,129,125,125,
125,125,126,126,126,126,126,130,129,125,
125,125,125,130,125,125,129,125,129,129,
125,125,125,125,126,126,126,130,125,125,
129,125,125,125,125,130,125,125,125,125,
130,125,129,125,129,129,125,125,129,125,
129,125,129,129,125,125,125,125,129,125,
125,125,126,128,128,129,125,129,125,125,
};

int shoot_numberOfSamples = 4080;

int shoot_sampleRate = 11025;
