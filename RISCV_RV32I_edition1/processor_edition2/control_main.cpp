#include "control.h"

SC_MODULE(control_test)
{
	sc_out<bool> clk;
    sc_out<bool> reset;
    sc_out<sc_bv<7>> opcode;
    sc_out<sc_bv<5>> rd;
    sc_out<sc_bv<3>> funct3_control_i;
    sc_out<sc_bv<5>> rs1;
    sc_out<sc_bv<5>> rs2;
    sc_out<sc_bv<7>> imm7;
    sc_out<sc_bv<12>> pc_i;

    sc_in<sc_bv<12>> pc_o;
    sc_in<sc_bv<12>> imm;
    sc_in<bool> pc_jump;
    sc_in<bool> alu12_select;
    sc_in<bool> reg_w_current_stage;
    sc_in<bool> reg_w_following_stage_o;

    sc_in<bool> ins_branch;
    sc_in<bool> ins_load;
    sc_in<bool> ins_store;

    sc_in<bool> shift_imm;

    sc_in<sc_bv<4>> aluop;
    sc_in<bool> alu_input;
    sc_in<sc_bv<3>> funct3_control_o;

    void driver();
    void monitor();
    void make_clk();
    void monitor_specific();

    SC_CTOR(control_test)
    {
    	SC_THREAD(driver);
    	SC_THREAD(monitor);
        SC_THREAD(make_clk);
        SC_THREAD(monitor_specific);
    }
};


void control_test::make_clk()
{
    clk = 0;
    while(1)
    {
        wait (5, SC_NS);
        clk = !clk;
    }
}


void control_test::driver()
{
/*    sc_uint<7> temp_opcode;
    sc_uint<5> temp_rd;
    sc_uint<3> temp_funct3; 
    sc_uint<5> temp_rs1;
    sc_uint<5> temp_rs2;
    sc_uint<7> temp_imm7;
    sc_uint<12> temp_pc_i;*/

    reset.write(0);
    opcode.write(0);
    rd.write(0);
    funct3_control_i.write(0);
    rs1.write(0);
    rs2.write(0);
    imm7.write(0);
    pc_i.write(0);
    wait (10, SC_NS);

    reset.write(1);                    
    wait (10, SC_NS);

    reset.write(0);
    wait (10, SC_NS);
        
    opcode.write(111);
    rd.write(12);
    funct3_control_i.write(0);
    rs1.write(1);
    rs2.write(2);
    imm7.write(0);
    pc_i.write(33);

}


void control_test::monitor()
{
    while (1)
    {
        cout << sc_time_stamp() << "::  " << "pc_o  " << pc_o << "  imm  " << imm << "  reset  " << reset << endl;
        cout << "  pc_jump  " << pc_jump << "  alu12_select  " << alu12_select << "  reg_w_current_stage  " ; 
        cout << reg_w_current_stage << "  ins_branch  " << ins_branch;
        cout << "  aluop  " << aluop << "  alu_input  " << alu_input << endl;
        cout << "  ins_store  " << ins_store << "  ins_load  " << ins_load << "  shift_imm  " << shift_imm ; 
        cout << "  reg_w_following_stage_o  " << reg_w_following_stage_o; 
        cout << "  funct3_control_o  " << funct3_control_o << endl; 
        wait(10, SC_NS);
    }
}

void control_test::monitor_specific()
{
	wait(41, SC_NS);

        cout << sc_time_stamp() << "::  " << "pc_o  " << pc_o << "  imm  " << imm << "  reset  " << reset << endl;
        cout << "  pc_jump  " << pc_jump << "  alu12_select  " << alu12_select << "  reg_w_current_stage  " ; 
        cout << reg_w_current_stage << "  ins_branch  " << ins_branch;
        cout << "  aluop  " << aluop << "  alu_input  " << alu_input << endl;
        cout << "  ins_store  " << ins_store << "  ins_load  " << ins_load << "  shift_imm  " << shift_imm ; 
        cout << "  reg_w_following_stage_o  " << reg_w_following_stage_o; 
        cout << "  funct3_control_o  " << funct3_control_o << endl; 
        
}


int sc_main(int argv, char * argc[])
{
	sc_signal<bool> clk;
	sc_signal<bool> reset;
	sc_signal<sc_bv<7>> opcode;
	sc_signal<sc_bv<5>> rd;
	sc_signal<sc_bv<3>> funct3_control_i;
	sc_signal<sc_bv<5>> rs1;
	sc_signal<sc_bv<5>> rs2;
	sc_signal<sc_bv<7>> imm7;
	sc_signal<sc_bv<12>> pc_i;

    sc_signal<sc_bv<12>> pc_o;
	sc_signal<sc_bv<12>> imm;
	sc_signal<bool> pc_jump;
	sc_signal<bool> alu12_select;
	sc_signal<bool> reg_w_current_stage;
	sc_signal<bool> reg_w_following_stage_o;
	sc_signal<bool> ins_branch;
	sc_signal<bool> ins_load;
	sc_signal<bool> ins_store;
	sc_signal<bool> shift_imm;
	sc_signal<sc_bv<4>> aluop;
	sc_signal<bool> alu_input;
	sc_signal<sc_bv<3>> funct3_control_o;

	control c1("control1");
	c1.clk(clk);
	c1.reset(reset);
	c1.opcode(opcode);
	c1.rd(rd);
	c1.funct3_control_i(funct3_control_i);
	c1.rs1(rs1);
	c1.rs2(rs2);
	c1.imm7(imm7);
	c1.pc_i(pc_i);

    c1.pc_o(pc_o);
	c1.imm(imm);
	c1.pc_jump(pc_jump);
	c1.alu12_select(alu12_select);
	c1.reg_w_current_stage(reg_w_current_stage);
	c1.reg_w_following_stage_o(reg_w_following_stage_o);
	c1.ins_branch(ins_branch);
	c1.ins_load(ins_load);
	c1.ins_store(ins_store);
	c1.shift_imm(shift_imm);
	c1.aluop(aluop);
	c1.alu_input(alu_input);
	c1.funct3_control_o(funct3_control_o);

    control_test t1("control_test1");
    t1.clk(clk);
	t1.reset(reset);
	t1.opcode(opcode);
	t1.rd(rd);
	t1.funct3_control_i(funct3_control_i);
	t1.rs1(rs1);
	t1.rs2(rs2);
	t1.imm7(imm7);
	t1.pc_i(pc_i);

    t1.pc_o(pc_o);
	t1.imm(imm);
	t1.pc_jump(pc_jump);
	t1.alu12_select(alu12_select);
	t1.reg_w_current_stage(reg_w_current_stage);
	t1.reg_w_following_stage_o(reg_w_following_stage_o);
	t1.ins_branch(ins_branch);
	t1.ins_load(ins_load);
	t1.ins_store(ins_store);
	t1.shift_imm(shift_imm);
	t1.aluop(aluop);
	t1.alu_input(alu_input);
	t1.funct3_control_o(funct3_control_o);

    sc_start(70, SC_NS);

    return 0;

}