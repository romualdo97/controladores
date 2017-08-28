Seth both A and D to A + 1
AD = A + 1 -> 111 110111 110 000

@19
D = A

Set both A and D to A + D

AD = D + A

Set RAM[5034] to D - 1

@5034
M = D - 1

Set RAM[53] to 171

@171
D = A
@53
M = D

Add 1 to RAM[7],
and store the result in D

@7
D = M + 1

sum = 0

@sum
M = 0

j = j + 1

@j
M = M + 1

q = sum + 12 – j

@12
D = A
@j
D = D - M
@sum
D = M + D
@q
M = D

arr[3] = -1

@3
D = A
@arr
A = A + D
M = -1

arr[j] = 0

@j
D = A
@arr
A = D + A
M = 0

arr[j] = 17

@j
D = A
@arr
D = D + A
@17

if D<9 goto 507

@9
D = D - A
@507
D; JLT

if RAM[12] > 0 goto 50

@12	// A = 12
D = M	// D = RAM[A]
@50	// A = 50
D; JGT

if sum > 0 goto END


@sum
D = A
@END
D; JGT

if x[i]<=0 goto NEXT.

@x			// A = x
D = A 		// D = A
@i 			// A = i
A = D + M 	// A = D + ram[A]
D = M		// D = ram[A]
@NEXT 		// A = NEXT
D; JLE		// if (D <= 0) jump to A

