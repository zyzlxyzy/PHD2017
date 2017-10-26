#include "instruction_memory.h"

/*void instruction_memory::prc_instruction_memory()
{
	sc_lv<32> allzs (sc_logic_Z);
	sc_lv<32> allxs (sc_logic_X);
	sc_uint<10> temp;
	temp = addr;

	if (write)
	{
		if (temp < 1024)
			ram[temp] = instruction_i;
		else 
			ram[temp] = ram[temp];
	}

	else 
	{
		if (temp < 1024)	
		    instruction_o = ram[temp];
		else 
			instruction_o = allxs;
	}
}*/

void instruction_memory::prc_instruction_memory()
{
	if (write)
		ram[addr.read()] = instruction_i;
	else 
	    //instruction_o = ram[addr.read()];
	    instruction_o.write(ram[addr.read()]);
}