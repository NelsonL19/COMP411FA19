#include <stdio.h>

// define some constants used in this lab
#define ADDI 0
#define AND 1
#define OR 2
#define NOR 3
#define SLL 4
#define SRL 5
#define EXIT 6

#define ADDI_OPCODE 8
#define R_OPCODE 0
#define AND_FUNC 36

// TODO: You complete the rest
#define OR_FUNC 37
#define NOR_FUNC 39
#define SLL_FUNC 0
#define SRL_FUNC 2

// used for debugging 
void show_register_values( int*, int );

int main( int argc, char** argv ) {

	// lets create some variables that regpresent the three different registers
	// (rs = source, rt = target, and rd = destination) used in R and I type 
	// instructions.
	int rs, rt, rd;
	int s_registers[6] = { 0, 0, 0, 0, 0, 0 }; // our simulator has 5 general purpose 32 bit registers
	int operation;
	int reg_selection;
	short reg_value;
	short shamt = 0;		// see page 88 in the patterson and hennessy course textbook
	int exit = 0;

	printf( "------------------------------------------\n");
	printf( "Welcome to the Comp 411 MIPS instruction simulator!\n" );
	printf( "\nThe here we'll simulate R and I type MIPS instructions\n");
	printf( "Specifically, bitwise (and, or, nor, shift right and left)\n");
	printf( "and add immediate operations\n\n");
	printf( "All of these instructions can be found in Fig. 2 (page 64) \n");
	printf( "in the Patterson and Hennessy coursetext book.\n");
	printf( "-------------------------------------------\n");


	while ( !exit ) {

		printf( "\nlist of simulator operations:\n");
		printf( "\n(0)\taddi operation\n");
		printf( "(1)\tand operation\n");
		printf( "(2)\tor operation\n");
		printf( "(3)\tnor operation\n");
		printf( "(4)\tsll operation\n");
		printf( "(5)\tsrl operation\n");
		printf( "(6)\texit simulator\n");
		printf( "\nPlease select 0,1,2,3,4,5, or 6: ");
		scanf( "%d", &operation );

		switch ( operation ) {

			case ADDI:
				// I've done this one to get you going :)
				printf( "\nWhich register [0,1,2,3,4,5] would is the source (rs) register: ");
				scanf( "%d", &rs );
				printf( "Enter a 16-bit signed integer constant (in hexidecimal): " );
				scanf( "%hx", &reg_value );
				printf( "Which register [0,1,2,3,4,5] is the target (rt) register: ");
				scanf( "%d", &rt );
				printf( "The I-type message (in decimal) is: opcode=%d, rs=%d, rt=%d, and imm=%d\n", ADDI_OPCODE, rs, rt, reg_value );
				s_registers[rt] = s_registers[rs] + reg_value;
				printf( "The hex value of $s%d=%04X\n", rt, s_registers[rt] );

				rd = 0;
				rt = 0;
				rs = 0;
				shamt = 0;


				break;

			case AND:
				printf( "\nWhich register [0,1,2,3,4,5] would is the source (rs) register: ");
				scanf( "%d", &rs );
				printf( "Which register [0,1,2,3,4,5] is the target (rt) register: ");
				scanf( "%d", &rt );
				printf( "Which register [0,1,2,3,4,5] is the destination (rd) register: ");
				scanf( "%d", &rd );
				printf( "The R-type message (in decimal) is: opcode=%d, rs=%d, rt=%d, rd=%d, sa=%d, and function=%d\n", R_OPCODE, rs, rt, rd, shamt, AND_FUNC);


				s_registers[rd] = s_registers[rs] & s_registers[rt];

				//sprintf(rsReg, "%4X", (s_registers[rs] + '0'));
				//sprintf(rtReg, "%4X", (s_registers[rt] + '0'));

				printf( "The hex value of $s%d=%04X\n", rd, s_registers[rd] );


				
				rd = 0;
				rt = 0;
				rs = 0;
				shamt = 0;



				break;

			case OR:
				printf( "\nWhich register [0,1,2,3,4,5] would is the source (rs) register: ");
				scanf( "%d", &rs );
				printf( "Which register [0,1,2,3,4,5] is the target (rt) register: ");
				scanf( "%d", &rt );
				printf( "Which register [0,1,2,3,4,5] is the destination (rd) register: ");
				scanf( "%d", &rd );
				printf( "The R-type message (in decimal) is: opcode=%d, rs=%d, rt=%d, rd=%d, sa=%d, and function=%d\n", R_OPCODE, rs, rt, rd, shamt, NOR_FUNC);


				//rest of OR Case

				s_registers[rd] = s_registers[rs] | s_registers[rt];

				printf( "The hex value of $s%d=%04X\n", rd, s_registers[rd] );


				rd = 0;
				rt = 0;
				rs = 0;
				shamt = 0;


				break;
				

			case NOR:
				printf( "\nWhich register [0,1,2,3,4,5] would is the source (rs) register: ");
				scanf( "%d", &rs );
				printf( "Which register [0,1,2,3,4,5] is the target (rt) register: ");
				scanf( "%d", &rt );
				printf( "Which register [0,1,2,3,4,5] is the destination (rd) register: ");
				scanf( "%d", &rd );
				printf( "The R-type message (in decimal) is: opcode=%d, rs=%d, rt=%d, rd=%d, sa=%d, and function=%d\n", R_OPCODE, rs, rt, rd, shamt, NOR_FUNC);

 
				s_registers[rd] = ~(s_registers[rs] |  s_registers[rt]);

				printf( "The hex value of $s%d=%04X\n", rd, s_registers[rd] );



				rd = 0;
				rt = 0;
				rs = 0;
				shamt = 0;



				break;
				

			case SLL:

				printf("\nWhich register [0,1,2,3,4,5] is the target (rt) register: ");
				scanf( "%d", &rt );
				printf( "Which register [0,1,2,3,4,5] would is the destination (rd) register: ");
				scanf( "%d", &rd );
				printf( "Enter left bit-shift amount (sa): ");
				scanf( "%hd", &shamt );
				printf( "The R-type message (in decimal) is: opcode=%d, rs=%d, rt=%d, rd=%d, sa=%d, and function=%d\n", R_OPCODE, rs, rt, rd, shamt, SLL_FUNC);

				s_registers[rd] = s_registers[rt] <<  shamt;

				printf( "The hex value of $s%d=%04X\n", rd, s_registers[rd] );

				rd = 0;
				rt = 0;
				rs = 0;
				shamt = 0;

				break;
				

			case SRL:
				
				printf("\nWhich register [0,1,2,3,4,5] is the target (rt) register: ");
				scanf( "%d", &rt );
				printf("Which register [0,1,2,3,4,5] would is the destination (rd) register: ");
				scanf( "%d", &rd );
				printf( "Enter right bit-shift amount (sa): ");
				scanf( "%hd", &shamt );
				printf( "The R-type message (in decimal) is: opcode=%d, rs=%d, rt=%d, rd=%d, sa=%d, and function=%d\n", R_OPCODE, rs, rt, rd, shamt, SRL_FUNC);

				s_registers[rd] = s_registers[rt] >> shamt;

				printf( "The hex value of $s%d=%04X\n", rd, s_registers[rd] );

				shamt = 0;

				break;

			default:
				exit = 1;
				break;

		
		}

	}
	
	printf("Exiting simulator ... hope you had fun ... bye bye!\n\n");
	
	return 0;

} // end main function


// this can be used for debugging, i.e. you can see what is
// stored in the 5 general purpose registers.
void show_register_values( int* regs, int size ) {

	int i=0;

	for ( i=0; i<size; i++ ) {

		printf( "$s%d=%d\n", i, regs[i] );

	}

}
