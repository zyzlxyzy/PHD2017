#include "control.h"

void control::control_main()
{
	sc_uint<7> opcode_uint;
	opcode_uint = opcode.read();

	sc_uint<3> funct3_int;
	funct3_int = funct3_control_i.read();

	sc_uint<4> aluop_int;
	aluop.write(aluop_int);

	funct3_control_o.write(funct3_control_i);
	pc_o.write(pc_i);

	if (reset == 1)
	{
		pc_jump.write(0);
		alu12_select.write(0);
		reg_w_following_stage_o.write(0);
		ins_branch.write(0);
		aluop_int = 0;
		alu_input.write(0);     
		ins_store.write(0);
		ins_load.write(0);
		shift_imm.write(0); 
	}

	else
	{switch(opcode_uint)
	{
/*************************************************************/
// JAL instruction
		case 111 : {                            
		    pc_jump.write(1);
			alu12_select.write(1);
			reg_w_following_stage_o.write(0);
			ins_branch.write(0);
			aluop_int = 0;
			alu_input.write(0);     
			ins_store.write(0);
			ins_load.write(0);
			shift_imm.write(0);     
		} 
		break;
// JAL instruction
/*************************************************************/
// JALR instruction
		case 103 : {
			pc_jump.write(1);
			alu12_select.write(0);
			reg_w_following_stage_o.write(0);
			ins_branch.write(0);
			aluop_int = 0; // add
			alu_input.write(0);
			ins_store.write(0);
			ins_load.write(0);
			shift_imm.write(0);
		}
		break;
// JALR instruction
/*************************************************************/
// BRANCH instructions
		case 99 : {                  
			pc_jump.write(0);
			alu12_select.write(1);
			reg_w_following_stage_o.write(0);
			ins_branch.write(1);
			aluop_int = 1; // sub
			alu_input.write(0);
			ins_store.write(0);
			ins_load.write(0);
			shift_imm.write(0);
		}
		break;
// BRANCH instructions
/*************************************************************/
// LOAD instructions
		case 3 : {
			pc_jump.write(0);
			alu12_select.write(0);
			reg_w_following_stage_o.write(1);
			ins_branch.write(0);
			aluop_int = 0;
			alu_input.write(0);
			ins_store.write(0);
			ins_load.write(1);
			shift_imm.write(0);
		}
		break;
// LOAD instructions
/*************************************************************/
// STORE instructions
		case 35 : {
			pc_jump.write(0);
			alu12_select.write(0);
			reg_w_following_stage_o.write(0);
			ins_branch.write(1);
			aluop_int = 0;
			alu_input.write(0);
			ins_store.write(1);
			ins_load.write(0);
			shift_imm.write(0);
		}
		break;
// STORE instructions
/*************************************************************/
// ALU instructions
		case 51 : {
			pc_jump.write(0);
			alu12_select.write(0);
			reg_w_following_stage_o.write(1);
			ins_branch.write(0);
			switch (funct3_int)
			{
				case 0 : {
					if (imm7.read()[6] == 0)
						aluop_int = 0;  // add
					else
						aluop_int = 8;  // sub
				} break;
				case 5 : {
					if (imm7.read()[6] == 0)
						aluop_int = 5;  // srl
					else
						aluop_int = 9;  // sra
				} break;
				default : aluop_int = funct3_int; break; 
				// 1 sll; 2 slt; 3 sltu; 4 xor; 6 or; 7 and;
			}
			alu_input.write(0);
			ins_store.write(0);
			ins_load.write(0);
			shift_imm.write(0);
		}
		break;
// ALU instructions
/*************************************************************/
// ALUI instructions
		case 19 : {
			pc_jump.write(0);
			alu12_select.write(0);
			reg_w_following_stage_o.write(1);
			ins_branch.write(0);
			switch (funct3_int)
			{
				case 5 : {
					if (imm7.read()[6] == 0)
						aluop_int = 5;  // srl
					else
						aluop_int = 9;  // sra
				} break;
				default : aluop_int = funct3_int; break; 
				// 1 sll; 2 slt; 3 sltu; 4 xor; 6 or; 7 and;
			}
			alu_input.write(1);
			ins_store.write(0);
			ins_load.write(0);
			shift_imm.write(1);
		}
		break;
// ALUI instructions
/*************************************************************/	
		default : {
			pc_jump.write(0);
			alu12_select.write(0);
			reg_w_following_stage_o.write(0);
			ins_branch.write(0);
			aluop_int = 0;
			alu_input.write(0);
			ins_store.write(0);
			ins_load.write(0);
			shift_imm.write(0);
		}
		break;
	}}
	
}


void control::imm_selector()
{
	imm1.range(11, 5) = imm7.read();
	imm1.range(4, 0) = rs2.read();              // for LOAD, immediate and JALR instructions bit[31,20]

	imm2[11] = (funct3_control_i.read())[0];
	imm2[10] = (rs2.read())[0];
	imm2.range(9, 4) = (imm7.read()).range(5,0);
	imm2.range(3, 0) = (rs2.read()).range(4,1);  // extremely annoying imm for JAL instruction

	imm3.range(11, 5) = imm7.read();
	imm3.range(4, 0) = rd.read();               // used for STORE instructions

	imm4[11] = (imm7.read())[6];
	imm4[10] = (rd.read())[0];
	imm4.range(9, 4) = (imm7.read()).range(5,0);
	imm4.range(3, 0) = (rd.read()).range(4,1);    // used for BRANCH instructions

	imm5.range(11, 5) = 5;
	imm5.range(4, 0) = rs2.read();               // used for SLLI, SRLI, SRAI

	sc_uint<7> opcode_uint;
	opcode_uint = opcode.read();

	if (reset == 1)
		imm.write(0);
	else {
	switch (opcode_uint)
	{
		case 3 : imm.write(imm1); break;
		case 103 : imm.write(imm1); break;
		case 111 : imm.write(imm2); break;
		case 35 : imm.write(imm3); break;
		case 99 : imm.write(imm4); break;
		case 19 : {
			if ((funct3_control_i.read() == 1) || (funct3_control_i.read() == 5))
				imm.write(imm5);
			else 
				imm.write(imm1);
		} break;
		default : imm.write(imm1); break;
	}}
}


void control::write_reg()
{
	if ((opcode.read() == 111) || (opcode.read() == 103))
		reg_w_current_stage.write(1);
	else
		reg_w_current_stage.write(0);
}