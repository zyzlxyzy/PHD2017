#include "alu.h"
#include "alu_test.h"

int sc_main(int argc, char* argv[])
{
	sc_signal<bool> m_ins_bit30;
	sc_signal<sc_bv<3>> m_aluop;
	sc_signal<sc_bv<5>> m_shift_imm;
	sc_signal<sc_bv<32>> m_operand1, m_operand2; 
	sc_signal<sc_bv<32>> m_result;

	alu a1("alu1");
	a1.aluop(m_aluop);
	a1.ins_bit30(m_ins_bit30);
	a1.shift_imm(m_shift_imm);
	a1.operand1(m_operand1);
	a1.operand2(m_operand2);
	a1.result(m_result);

	alu_test t1("alu_test1");
	t1.t_ins_bit30(m_ins_bit30);
	t1.t_aluop(m_aluop);	
	t1.t_shift_imm(m_shift_imm);
	t1.t_operand1(m_operand1);
	t1.t_operand2(m_operand2);
	t1.t_result(m_result);

	sc_start(180, SC_NS);

	return 0;

}