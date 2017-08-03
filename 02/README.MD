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
			 = !x * nx + x * !nx

THE f CONTROLS

// xo and yo stands for x output and y output
xo	yo	f   no	|	out
0   0   0   0			// x & y   
0	0	0   1 	    	// x + y
0	0	1	0   		// x & y
0	0	1	1   		// x + y
0	1	0	0 			// x & y
0   1   0   1 			// x + y
0   1   1   0 			// x & y
0   1   1   1 			// x + y -> 1 + 1 = 10 where 0 is the sum term
1	0	0	0			//					and 1 the carry
1	0	0	1
1	0	1	0
1	0	1	1
1	1	0	0
1	1	0	1
1	1	1	0
1	1	1	1

f(xo, yo, f) = !xo * yo * f + xo * !yo * f + xo * yo * !f
			 = xo * (!yo * f + yo * !f) + !xo * yo * f
			 = xo + !xo * yo * f

THE No CONTROLS

sum   no   | out
0	  0		 0
0     1		 1
1     0		 1
1     1		 0

