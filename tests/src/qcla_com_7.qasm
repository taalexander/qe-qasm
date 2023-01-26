OPENQASM 2.0;
include "qelib1.inc";

qreg qubits[24];
x qubits[0];
x qubits[3];
x qubits[6];
x qubits[10];
x qubits[13];
x qubits[17];
x qubits[21];
ccx qubits[0],qubits[1],qubits[2];
ccx qubits[3],qubits[4],qubits[5];
ccx qubits[6],qubits[7],qubits[9];
ccx qubits[10],qubits[11],qubits[12];
ccx qubits[13],qubits[14],qubits[16];
ccx qubits[17],qubits[18],qubits[20];
ccx qubits[21],qubits[22],qubits[23];
cx qubits[3],qubits[4];
cx qubits[6],qubits[7];
cx qubits[10],qubits[11];
cx qubits[13],qubits[14];
cx qubits[17],qubits[18];
cx qubits[21],qubits[22];
ccx qubits[7],qubits[11],qubits[8];
ccx qubits[14],qubits[18],qubits[15];
h qubits[19];
ccx qubits[15],qubits[22],qubits[19];
ccx qubits[2],qubits[4],qubits[5];
ccx qubits[9],qubits[11],qubits[12];
ccx qubits[16],qubits[18],qubits[20];
ccx qubits[5],qubits[8],qubits[12];
ccx qubits[20],qubits[22],qubits[23];
ccx qubits[12],qubits[19],qubits[23];
ccx qubits[5],qubits[8],qubits[12];
ccx qubits[9],qubits[11],qubits[12];
ccx qubits[16],qubits[18],qubits[20];
ccx qubits[15],qubits[22],qubits[19];
ccx qubits[2],qubits[4],qubits[5];
ccx qubits[7],qubits[11],qubits[8];
ccx qubits[14],qubits[18],qubits[15];
cx qubits[3],qubits[4];
cx qubits[6],qubits[7];
cx qubits[10],qubits[11];
cx qubits[13],qubits[14];
cx qubits[17],qubits[18];
cx qubits[21],qubits[22];
ccx qubits[0],qubits[1],qubits[2];
ccx qubits[3],qubits[4],qubits[5];
ccx qubits[6],qubits[7],qubits[9];
ccx qubits[10],qubits[11],qubits[12];
ccx qubits[13],qubits[14],qubits[16];
ccx qubits[17],qubits[18],qubits[20];
x qubits[0];
x qubits[3];
x qubits[6];
x qubits[10];
x qubits[13];
x qubits[17];
x qubits[21];
x qubits[23];

