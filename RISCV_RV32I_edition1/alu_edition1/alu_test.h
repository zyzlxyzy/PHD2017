#include "systemc.h"

SC_MODULE(alu_test)
{
	sc_out<bool> t_ins_bit30;
	sc_out<sc_bv<3>> t_aluop;
	sc_out<sc_bv<5>> t_shift_imm;
	sc_out<sc_bv<32>> t_operand1, t_operand2; 
	sc_in<sc_bv<32>> t_result;

    void driver();
    void monitor();

    SC_CTOR(alu_test)
    {
    	SC_THREAD(driver);
    	SC_THREAD(monitor);
    }
};