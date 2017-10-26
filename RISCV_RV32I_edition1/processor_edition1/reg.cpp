#include "reg.h"

void reg::reg_base()
{
    sc_uint<5> addr_read1_int, addr_read2_int, addr_write_int;
    sc_uint<32> reg0, reg5;
    
    reg0 = regdata[0];
    reg5 = regdata[5];
    addr_read1_int = addr_read1;
    addr_read2_int = addr_read2;
    addr_write_int = addr_write;

	if (enable.read() == 1)
	{
		if (w.read() == 1)
			regdata[addr_write_int] = rd;
		else 
		{
          	rs1.write(regdata[addr_read1_int]);
          	rs2.write(regdata[addr_read2_int]);
		}
	}
}
