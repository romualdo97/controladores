THE zX CONTROLS

x	zx	nx   | out
0   0   0      0
0	0	1      0
0	1	0	   0
0	1	1	   0
1	0	0	   1
1   0   1      1
1   1   0      0
1   1   1      0

f(x, zx, nx) = x * !zx * !nx + x * !zx * nx
			 = x * !zx (!nx + nx)
			 = x * !zx

THE nX CONTROLS

x	zx	nx   | out
0   0   0      0
0	0	1      1
0	1	0	   0
0	1	1	   1
1	0	0	   1
1   0   1      0
1   1   0      1
1   1   1      0

f(x, zx, nx) = !x * !zx * nx + !x * zx * nx + x * !zx * !nx + x * zx * !nx
			 = !x * nx (!zx + zx) + x * !nx (!zx + zx)
			 = !x * nx (!zx + zx) + x * !nx (!zx + zx)