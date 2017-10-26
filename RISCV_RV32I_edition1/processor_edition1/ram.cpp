#include "ram.h"

void ram::prc_ram()
{
	sc_uint<8> addr_int;
	addr_int = addr.read();

	sc_int<32> ram0_int, ram1_int;
	ram0_int = ramdata[0];
	ram1_int = ramdata[1];

		if (enable.read() == 1)
		{
			if (w.read() == 1)
			{
				ramdata[addr_int] = datain.read();
			}
			else
			{
				dataout.write(ramdata[addr_int]);
			} 
			cout << "  at time  " << sc_time_stamp() << "::  ram0  " 
			     << ram0_int << "  ram1  " << ram1_int << endl;	
		}

		    
        else 
        	cout << "  denied  "  << endl;
}
