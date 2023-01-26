OPENQASM 3.0;

include "stdgates.inc";

// 4. loop unrolling

qubit q;
qubit r;
angle[3] c = 0;
reset q;
reset r;
h r;
uint[3] power = 1;
reset q;
h q;
cphase(power * 3 * pi / 8) q, r;
phase(-c) q;
h q;
measure q -> c[0];
c <<= 1;
power <<= 1;
reset q;
h q;
cphase(power * 3 * pi / 8) q, r;
phase(-c) q;
h q;
measure q -> c[0];
c <<= 1;
power <<= 1;
reset q;
h q;
cphase(power * 3 * pi / 8) q, r;
phase(-c) q;
h q;
measure q -> c[0];
c <<= 1;
power <<= 1;

