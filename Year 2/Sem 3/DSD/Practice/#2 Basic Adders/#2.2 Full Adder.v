/******************************************************************************

                            #2.2 : Full Adder

*******************************************************************************/

/*
    Full Adders are used for adding 3 bits
    (1 extra being thr carry from the previous adder)
    thses are made by using 2 gates :
        - An xor gate for SUM
        - An and gate for CARRY
*/ 

// importing half adder
`include "./#2.1 : Half Adder.v"

// adder code
module fulladder(a, b, c, sum, carry);
    input a, b, c;
    output sum, carry;

    assign sum = a ^ b ^ c;
    assign carry = (a & b) + (b & c) + (c & a);
endmodule

// adder code using half adder
module full_halfadder(a, b, c, sum, carry);
    input a, b, c;
    output sum, carry;
    wire temp1, temp2, temp3;

    // implementing multile half adder
    halfadder ha1 (.a(a), .b(b), .sum(temp1), .carry(temp2));
    halfadder ha2 (.a(temp1), .b(c), .sum(sum), .carry(temp3));

    assign carry = temp2 | temp3;
endmodule

// test bench for adder
module fulladder_tb;
    reg t_a, t_b, t_c;
    wire t_sum, t_carry;

    // creating full adder object
    full_halfadder mu_adder( .a(t_a), .b(t_b), .c(t_c), .sum(t_sum), .carry(t_carry) );

    initial begin
        // monitoring output
        $monitor(t_a, t_b, t_c, t_sum, t_carry);

        // specifying cases
        // (c==0)
        t_a = 1'b0;
        t_b = 1'b0;
        t_c = 1'b0;
        #1
        
        t_a = 1'b1;
        t_b = 1'b0;
        t_c = 1'b0;
        #1

        t_a = 1'b0;
        t_b = 1'b1;
        t_c = 1'b0;
        #1

        t_a = 1'b1;
        t_b = 1'b1;
        t_c = 1'b0;
        #1

        // (c==1)
        t_a = 1'b0;
        t_b = 1'b0;
        t_c = 1'b1;
        #1
        
        t_a = 1'b1;
        t_b = 1'b0;
        t_c = 1'b1;
        #1

        t_a = 1'b0;
        t_b = 1'b1;
        t_c = 1'b1;
        #1

        t_a = 1'b1;
        t_b = 1'b1;
        t_c = 1'b1;
    end

endmodule