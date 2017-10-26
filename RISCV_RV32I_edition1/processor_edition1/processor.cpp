#include "pc.h"
#include "alu.h"
#include "control.h"
#include "reg.h"
#include "ram.h"

int sc_main(int argc, char* argv[])
{
	sc_signal<sc_bv<7>> opcode;
	sc_signal<sc_bv<7>> funct7;
	sc_signal<sc_bv<5>> rs1, rs2, rs3;
	sc_signal<sc_bv<7>> fucnt3;

	ram r1("instruction_ram");
    r1.clk();
    r1.enable();
    r1.w();
    r1.addr();
    r1.datain();
    r1.dataout();

	ram r2("data_ram");
	r2.clk();
    r2.enable();
    r2.w();
    r2.addr();
    r2.datain();
    r2.dataout();

	pc p1("program_counter");
    p1.clk();
    p1.reset();
    p1.jump();
    p1.pcin();
    p1.pcout();


	alu a1("alu1");
	a1.alupo();
	a1.ins_bit30();
	a1.shift_imm();
	a1.operand1();
	a1.operand2();
	a1.result();

	control c1("control_unit");
	c1.opcode();
	c1.reg_w();


}