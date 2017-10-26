#include "systemc.h"

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

    SC_CTOR(control_test)
    {
    	SC_THREAD(driver);
    	SC_THREAD(monitor);
        SC_THREAD(make_clk);
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
    sc_uint<7> temp_opcode;
    sc_uint<5> temp_rd;
    sc_uint<3> temp_funct3; 
    sc_uint<5> temp_rs1;
    sc_uint<5> temp_rs2;
    sc_uint<7> temp_imm7;
    sc_uint<12> temp_pc_i;

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
        
    opcode.write(51);
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
        cout << sc_time_stamp() << "::  " << "pc_o  " << pc_o << "  imm  " << imm << endl;
        cout << "  pc_jump  " << pc_jump << "  alu12_select  " << alu12_select << "  reg_w_current_stage  " ; 
        cout << reg_w_current_stage << "  reg_w_following_stage_o  " << reg_w_following_stage_o;
        cout << "  ins_branch  " << ins_branch << "  ins_load  " << ins_load; 
        cout << "  ins_store  " << ins_store << "  shift_imm  " << shift_imm << endl; 
        cout << "  aluop  " << aluop << "  alu_input  " << alu_input; 
        cout << "  funct3_control_o  " << funct3_control_o << endl; 
        wait(10, SC_NS);
    }
}
