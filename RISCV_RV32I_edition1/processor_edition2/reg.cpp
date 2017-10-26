#include "reg.h"

void reg::reg_base()
{
    sc_uint<5> addr_read1_int, addr_read2_int, addr_write_int;

    addr_read1_int = addr_read1;
    addr_read2_int = addr_read2;

    if (ins_load.read() == 1)
        addr_write_int = addr_write_previous;
    else 
        addr_write_int = addr_write_current;

    

    if (reset.read() == 1)
    {
        sc_bv<32> regdata[] = {};
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
            //regdata[0] = 0;
            cout << sc_time_stamp() << ": addr" << addr_read1_int << "  " << addr_read2_int << endl;
        }
    }
}

void reg::load_extended()
{
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
            case 5 : load_rd_o = lbu_int; break;    //LHU
            default: load_rd_o = load_rd_i; break;
        }
        
    }

    else load_rd_o = load_rd_i;
}


void reg::view_specific()
{
    reg0 = regdata[0];
    reg1 = regdata[1];
}