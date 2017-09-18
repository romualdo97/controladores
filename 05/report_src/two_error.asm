// TYPE-A
// 000 0 001100 000 110 -> @774
// A = 774
// BUT IF WERE TYPE-C
// ALU OUT = D
// JUMP COND = JLE (if out <= 0 then JUMP)

ROM[16]
A = 774
D = 32
inLoad = (where is j1 will be j3 and vice versa)
// making JUMP COND = JGE (if out >= 0 then JUMP)
PC(in=outALU, load=inLoad) = 16

---

ROM[32]
A = 774
D = 32
PC = 32
