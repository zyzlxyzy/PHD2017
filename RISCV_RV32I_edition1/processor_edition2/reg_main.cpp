#include "systemc.h"
#include "reg.h"

SC_MODULE(reg_test)
{
    sc_out<bool> clk, w, reset, ins_load;
    sc_out<sc_bv<3>> funct3;
    sc_out<sc_bv<5>> addr_read1, addr_read2;
    sc_out<sc_bv<5>> addr_write_current, addr_write_previous;
    sc_out<sc_bv<32>> rd;
    sc_out<sc_bv<32>> load_rd_i;


    sc_in<sc_bv<32>> reg0, reg1;

    sc_in<sc_bv<32>> rs1, rs2;

    void driver();
    void monitor();
    void make_clk();
    void monitor_specific();

    SC_CTOR(reg_test)
    {
    	SC_THREAD(driver);
    	SC_THREAD(monitor);
        SC_THREAD(make_clk);
        SC_THREAD(monitor_specific);
    }
};


void reg_test::make_clk()
{
    clk = 0;
    while(1)
    {
        wait (5, SC_NS);
        clk = !clk;
    }
}


void reg_test::driver()
{
    sc_uint<32> temp_rd;

    wait(5, SC_NS);

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
    temp_rd = 23;
    rd.write(temp_rd);
    wait(10, SC_NS);

    w.write(0);


}


void reg_test::monitor()
{
    sc_uint<32> temp_rd, temp_load_rd_i, temp_rs1, temp_rs2;
    temp_rd = rd.read();
    temp_load_rd_i = load_rd_i.read();
    temp_rs1 = rs1;
    temp_rs2 = rs2;
    //wait(10, SC_NS);

//    sc_uint<32> regdata_uint [32];
//    regdata_uint = regdata;

    while (1)
    {
        cout << sc_time_stamp() << "::  " << "  clk  " << clk << "  w  " << w << "  reset  " << reset;
        cout << "  ins_load  " << ins_load << "  funct3  " << funct3 << "  addr_read1  ";
        cout << addr_read1 << "  addr_read2  " << addr_read2 << "  addr_write_current  ";
        cout << addr_write_current << "  addr_write_previous  " << addr_write_previous;
        cout << "  rd  " << temp_rd << "  load_rd_i  " << temp_load_rd_i;
        cout << "  rs1  " << temp_rs1 << "  rs2  " << temp_rs2 << endl;

        cout << "  reg0  " << reg0 << "  reg1  " << reg1 << "  rd  " << rd <<endl;

        //cout << "  reg0  " << regdata_uint[0] << "  reg1  " << regdata_uint[1] << "  reg2  " << regdata[2] << endl;
        wait(1, SC_NS);
    }
}


void reg_test::monitor_specific()
{
    sc_uint<32> temp_rd, temp_load_rd_i, temp_rs1, temp_rs2;
    temp_rd = rd.read();
    temp_load_rd_i = load_rd_i.read();
    temp_rs1 = rs1;
    temp_rs2 = rs2;

//    sc_uint<32> regdata_uint [32];
//    regdata_uint = regdata;
    wait(30, SC_NS);

    while (1)
    {
        cout << sc_time_stamp() << "::  " << "  w  " << w << "  reset  " << reset;
        cout << "  ins_load  " << ins_load << "  funct3  " << funct3 << "  addr_read1  ";
        cout << addr_read1 << "  addr_read2  " << addr_read2 << "  addr_write_current  ";
        cout << addr_write_current << "  addr_write_previous  " << addr_write_previous;
        cout << "  rd  " << temp_rd << "  load_rd_i  " << temp_load_rd_i;
        cout << "  rs1  " << temp_rs1 << "  rs2  " << temp_rs2 << endl;

//        cout << "  reg0  " << regdata_uint[0] << "  reg1  " << regdata_uint[1] << "  reg2  " << regdata[2] << endl;
        wait(2, SC_NS);
    }
}


int sc_main(int argv, char * argc[])
{
    sc_signal<bool> clk, w, reset, ins_load;
    sc_signal<sc_bv<3>> funct3;
    sc_signal<sc_bv<5>> addr_read1, addr_read2;
    sc_signal<sc_bv<5>> addr_write_current, addr_write_previous;
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

    r1.reg0(reg0);
    r1.reg1(reg1);

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


    t1.reg0(reg0);
    t1.reg1(reg1);



    t1.rs1(rs1);
    t1.rs2(rs2);

    sc_start(50, SC_NS);

    return 0;

}