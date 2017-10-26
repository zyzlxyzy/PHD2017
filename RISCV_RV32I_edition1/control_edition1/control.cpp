#include "control.h"

void control::prc_control()
{
	sc_uint<7> opcode_dec;

	opcode_dec = opcode.read();

	if(opcode_dec == 51)
		reg_w.write(1);
	else 
		reg_w.write(0); 
}