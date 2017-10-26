#include "control.h"

void control::prc_control()
{
	sc_uint<7> opcode_dec;

	opcode_dec = opcode.read();

    switch(opcode_dec)
    {
    	case 51 : {                       // ALU no immediate
    		reg_w.write(1);
    		reg_enable.write(1);
    		dataram_w.write(0);
    		dataram_enable.write(0);
    		//alumux_select.write(1);       // tell the ALU mux to select bit30

    	}
    	break;

    	case 3 : {                         // LOAD
    		reg_w.write(1);
    		reg_enable.write(1);
    		dataram_w.write(0);
    		dataram_enable.write(1);
    		//alumux_select.write(1); 
    	}
    	break;

    	case 35 :{                          // STORE
    		reg_w.write(0);
    		reg_enable.write(1);
    		dataram_w.write(1);
    		dataram_enable.write(1);
    		//alumux_select.write(1); 
    	}
    	break;

    	default : {
    		reg_w.write(0);
    		reg_enable.write(0);
    		dataram_w.write(0);
    		dataram_enable.write(0);
    		//alumux_select.write(0); 
    	}
    	break;
    }

}


void control::alu_control()
{
	sc_uint<7> opcode_dec;
	opcode_dec = opcode.read();

	if (opcode_dec == 51)
		aluop.write(funct3);
	else
	    aluop.write(0);
}