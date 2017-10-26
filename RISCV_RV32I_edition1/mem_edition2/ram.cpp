#include "ram.h"

void ram::prc_ram()
{

		if (enable.read() == 1)
		{
			if (w.read() == 1)
			{
				ramdata[addr.read()] = datain.read();
			}
			else
			{
				dataout.write(ramdata[addr.read()]);
			} 
			cout << "  at time  " << sc_time_stamp() << "::  ram0  " << ramdata[0] << "  ram1  " << ramdata[1] << endl;	
		}

		    
        else 
        	cout << "  denied  "  << endl;
}
