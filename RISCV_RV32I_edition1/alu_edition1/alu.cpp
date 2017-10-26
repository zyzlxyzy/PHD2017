#include "alu.h"

void alu::alu_main()
{
	sc_uint<4> op_4bit;
	//sc_bv<4> op_4bit;
	sc_int<32> operand1_int, operand2_int, result_int;
	sc_uint<32> operand1_uint, operand2_uint, result_uint;
	sc_uint<5> shift_imm_uint;
	sc_uint<4> op_4bit_int;

	//op_4bit = (aluop, ins_bit30);
	//op_4bit_int = op_4bit;
	op_4bit = aluop.read();
	op_4bit_int = op_4bit * 2 + ins_bit30.read();

	operand1_int = operand1.read();
	operand2_int = operand2.read();

	operand1_uint = operand1.read();
	operand2_uint = operand2.read();

	shift_imm_uint = shift_imm.read();

	switch (op_4bit_int)
	{
		case 0 : 
		{
			result_int = operand1_int + operand2_int;   //add 0000
			result = result_int;
			break;
		}

		case 1 :
		{
			result_int = operand2_int - operand1_int;   //sub 0001
		    result = result_int;
		    break;
		}

		case 2 :                        //sll 0010: shift left logical
		{
			result_uint = operand1_uint << shift_imm_uint; 
			result = result_uint;
			break;
		} 
		   
		case 4 :
		{
			if (operand1_int < operand2_int)   //slt 0100: set less than if rs1 < rs0, assign 0 to rd 
		    	result.write(1);
		    else 
		    	result.write(0);
			break;
		}	

		case 6 :
		{
			if (operand1_uint < operand2_uint)   //sltu 0110: set less than unsigned  if rs1 < rs0, assign 0 to rd
		    	result.write(1);
		    else 
		    	result.write(0);
			break;
		}

		case 8 :
		{
			result_int = operand1_int ^ operand2_int;   //xor 1000
			result = result_int;
			break;
		}

		case 10 :                         //srl 1010: shift right logical
		{
			result_uint = operand1_uint >> shift_imm_uint; 
			result = result_uint;
			break;
		}

		case 11 :                         //sra 1011: shift right arithmetic
		{
			result_int = operand1_int >> shift_imm_uint;
			result = result_int;
			break;
		}
			
		case 12 :
		{
			//result_int = operand1_int | operand2_int;   //or 1100
		    //result = result_int;
		    result.write(operand1.read() | operand2.read());
			break;
		}
		    
		case 14 :
		{
			result_int = operand1_int & operand2_int;   //and 1110
		    result = result_int;
			break;	
		}

		defalt :
		result.write(operand1.read());
		break;
	}
}

/*void alu::show_temp()
{
	sc_bv<4> op_4bit;
	sc_uint<4> op_4bit_int;

	op_4bit = (aluop, ins_bit30);
	op_4bit_int = op_4bit;
	cout << "  op_4bit_int  " << op_4bit_int << endl;
}*/