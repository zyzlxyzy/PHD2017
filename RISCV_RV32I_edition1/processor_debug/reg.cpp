#ifndef _REG_
#define _REG_
#include "systemc.h"

SC_MODULE(reg)
{
	sc_in<bool> clk, w, reset, ins_load;
	sc_in<sc_bv<3>> funct3;
	sc_in<sc_bv<5>> addr_read1, addr_read2;
	sc_in<sc_bv<5>> addr_write_current, addr_write_previous;
	sc_in<sc_bv<32>> rd;
	sc_in<sc_bv<32>> load_rd_i;
    sc_out<sc_bv<32>> rs1, rs2;

    sc_bv<32> regdata [32];
    sc_bv<32> load_rd_o;

    void reg_base();
    void view_specific();

    SC_CTOR(reg)
    {
    	SC_METHOD(reg_base);
    	sensitive << clk.pos();
    	SC_METHOD(view_specific);
    	sensitive << clk;
    }
};

#endif

void reg::reg_base()
{
	sc_uint<5> addr_read1_int, addr_read2_int, addr_write_int;

    addr_read1_int = addr_read1.read();
    addr_read2_int = addr_read2.read();
    
    if (ins_load.read() == 1)
        addr_write_int = addr_write_previous;
    else 
        addr_write_int = addr_write_current;







    sc_uint<3> funct3_int;
    funct3_int = funct3.read();

    sc_bv<16> lhu;
    sc_bv<8> lbu;
    sc_bv<16> lh;
    sc_bv<8> lb;

    sc_uint<16> lhu_int;
    sc_uint <8> lbu_int;
    sc_int<16> lh_int;
    sc_int<8> lb_int;

    lhu = (load_rd_i.read()).range(15,0);
    lhu_int = lhu;
    lbu = (load_rd_i.read()).range(7,0);
    lbu_int = lbu;
    lh = (load_rd_i.read()).range(15,0);
    lh_int = lh;
    lb = (load_rd_i.read()).range(7,0);
    lb_int = lb;

    if (ins_load == 1)
    {
        switch (funct3_int)
        {
            case 0 : load_rd_o = lb_int; break;    //LB
            case 1 : load_rd_o = lh_int; break;    //LH
            case 2 : load_rd_o = load_rd_i; break;    //LW
            case 4 : load_rd_o = lbu_int; break;    //LBU
            case 5 : load_rd_o = lhu_int; break;    //LHU
            default: load_rd_o = load_rd_i; break;
        }
        
    }

    else load_rd_o = load_rd_i;













	if (reset.read() == 1)
	{
		regdata[0] = 0; regdata[1] = 0; regdata[2] = 0; regdata[3] = 0; regdata[4] = 0;
		regdata[5] = 0; regdata[6] = 0; regdata[7] = 0; regdata[8] = 0; regdata[9] = 0;
		regdata[10] = 0; regdata[11] = 0; regdata[12] = 0; regdata[13] = 0; regdata[14] = 0;
		regdata[15] = 0; regdata[16] = 0; regdata[17] = 0; regdata[18] = 0; regdata[19] = 0;
		regdata[20] = 0; regdata[21] = 0; regdata[22] = 0; regdata[23] = 0; regdata[24] = 0;
		regdata[25] = 0; regdata[26] = 0; regdata[27] = 0; regdata[28] = 0; regdata[29] = 0;
		regdata[30] = 0; regdata[31] = 0;
	}
	else 
	{
		if (ins_load.read() == 1)
			regdata[addr_write_int] = load_rd_o;
		else if (w.read() == 1)
			regdata[addr_write_int] = rd;
		else
		{
			rs1.write(regdata[addr_read1_int]);
			rs2.write(regdata[addr_read2_int]);
			cout << sc_time_stamp() << ": addr"; 
			cout << addr_read1_int << "  " << addr_read2_int << endl;
		} 
	}
}



void reg::view_specific()
{
	cout << sc_time_stamp() << endl;
	cout << " reg0 " << regdata[0] << " reg1 " << regdata[1] << endl;
	cout << " reg2 " << regdata[2] << " reg3 " << regdata[3] << endl;
	cout << " reg4 " << regdata[4] << " reg5 " << regdata[5] << endl;
	cout << " reg6 " << regdata[6] << " reg7 " << regdata[7] << endl;
	cout << " reg8 " << regdata[8] << " reg9 " << regdata[9] << endl;

	cout << "  load  " << load_rd_o << endl;
}


SC_MODULE(reg_test)
{
    sc_out<bool> clk, w, reset, ins_load;
    sc_out<sc_bv<3>> funct3;
    sc_out<sc_bv<5>> addr_read1, addr_read2;
    sc_out<sc_bv<5>> addr_write_current, addr_write_previous;
    sc_out<sc_bv<32>> rd;
    sc_out<sc_bv<32>> load_rd_i;


    sc_in<sc_bv<32>> rs1, rs2;

    void driver();
    void monitor();
    void make_clk();

    SC_CTOR(reg_test)
    {
    	SC_THREAD(driver);
    	SC_THREAD(monitor);
        SC_THREAD(make_clk);
    }
};


void reg_test::make_clk()
{
    while(1)
    {
    	clk = 1;
        wait (5, SC_NS);
        clk = 0;
        wait (5, SC_NS);
    }
}


void reg_test::monitor()
{
    sc_uint<32> temp_rd, temp_load_rd_i, temp_rs1, temp_rs2;

    while (1)
    {
    	temp_rd = rd.read();
    	temp_load_rd_i = load_rd_i.read();
    	temp_rs1 = rs1;
    	temp_rs2 = rs2;
        cout << sc_time_stamp() << "::  " << "  clk  " << clk << "  w  " << w << "  reset  " << reset;
        cout << "  ins_load  " << ins_load << "  funct3  " << funct3 << "  addr_read1  ";
        cout << addr_read1 << "  addr_read2  " << addr_read2 << "  addr_write_current  ";
        cout << addr_write_current << "  addr_write_previous  " << addr_write_previous;
        cout << "  rd  " << temp_rd << "  load_rd_i  " << temp_load_rd_i;
        cout << "  rs1  " << temp_rs1 << "  rs2  " << temp_rs2 << endl;  
        wait(1, SC_NS);

        temp_rd = rd.read();
        temp_load_rd_i = load_rd_i.read();
        temp_rs1 = rs1;
    	temp_rs2 = rs2;
        cout << sc_time_stamp() << "::  " << "  clk  " << clk << "  w  " << w << "  reset  " << reset;
        cout << "  ins_load  " << ins_load << "  funct3  " << funct3 << "  addr_read1  ";
        cout << addr_read1 << "  addr_read2  " << addr_read2 << "  addr_write_current  ";
        cout << addr_write_current << "  addr_write_previous  " << addr_write_previous;
        cout << "  rd  " << temp_rd << "  load_rd_i  " << temp_load_rd_i;
        cout << "  rs1  " << temp_rs1 << "  rs2  " << temp_rs2 << endl;        
        wait(9, SC_NS);
    }
}


void reg_test::driver()
{
//    sc_uint<32> temp_rd;
	sc_uint<32> temp_load;

    wait(10, SC_NS);

    w.write(0);
    reset.write(0);
    ins_load.write(0);
    funct3.write(0);
    addr_read1.write(0);
    addr_read2.write(0);
    addr_write_current.write(0);
    addr_write_previous.write(0);
    rd.write(0);
    load_rd_i.write(0);
    wait (10, SC_NS);

    reset.write(1);
    wait (10, SC_NS);

    reset.write(0);
    w.write(1);
    addr_read1.write(0);
    addr_read2.write(1);
    addr_write_current.write(1);
    //temp_rd = 23;
    rd.write(23);
    wait(10, SC_NS);

    w.write(0);
    wait(10, SC_NS);
    funct3.write(0);
    addr_read2.write(1);
    ins_load.write(1);
    addr_write_previous.write(1);
    temp_load = 383;              //lb
    load_rd_i.write(temp_load);
    wait(10, SC_NS);

    funct3.write(1);
    addr_write_previous.write(2);
    temp_load = 32768 + 383;
    load_rd_i.write(temp_load);
    wait(10, SC_NS);              //lh

    funct3.write(2);
    addr_write_previous.write(3);
    temp_load = 1000000000;
    load_rd_i.write(temp_load);
    wait(10, SC_NS);              //lw

    funct3.write(3);
    addr_write_previous.write(4);
    temp_load = 1000000000;
    load_rd_i.write(temp_load);
    wait(10, SC_NS);              //default

    funct3.write(4);
    addr_write_previous.write(5);
    temp_load = 127+1024;
    load_rd_i.write(temp_load);
    wait(10, SC_NS);              //lbu


    funct3.write(5);
    addr_write_previous.write(6);
    temp_load = 127+1024+32768;
    load_rd_i.write(temp_load);
    wait(10, SC_NS);              //lhu
    
    ins_load.write(0);
    addr_read2.write(3);
    addr_read1.write(2);
    wait(10, SC_NS);

    reset.write(1);
}


int sc_main(int argv, char * argc[])
{
    sc_signal<bool> clk, w, reset;
    sc_signal<bool> ins_load;
    sc_signal<sc_bv<3>> funct3;
    sc_signal<sc_bv<5>> addr_read1, addr_read2;
    sc_signal<sc_bv<5>> addr_write_current;
    sc_signal<sc_bv<5>> addr_write_previous;
    sc_signal<sc_bv<32>> rd;
    sc_signal<sc_bv<32>> load_rd_i;


    sc_signal<sc_bv<32>> reg0, reg1;


    sc_signal<sc_bv<32>> rs1, rs2;

	reg r1("reg1");
	r1.clk(clk);
    r1.w(w);
	r1.reset(reset);
 	r1.ins_load(ins_load);
 	r1.funct3(funct3);
	r1.addr_read1(addr_read1);
	r1.addr_read2(addr_read2);
	r1.addr_write_current(addr_write_current);
 	r1.addr_write_previous(addr_write_previous);
	r1.rd(rd);
    r1.load_rd_i(load_rd_i);

	r1.rs1(rs1);
	r1.rs2(rs2);

    reg_test t1("reg_test1");
    t1.clk(clk);
    t1.w(w);
    t1.reset(reset);
    t1.ins_load(ins_load);
    t1.funct3(funct3);
    t1.addr_read1(addr_read1);
    t1.addr_read2(addr_read2);
    t1.addr_write_current(addr_write_current);
    t1.addr_write_previous(addr_write_previous);
    t1.rd(rd);
    t1.load_rd_i(load_rd_i);

    t1.rs1(rs1);
    t1.rs2(rs2);

    sc_start(130, SC_NS);

    return 0;

}
