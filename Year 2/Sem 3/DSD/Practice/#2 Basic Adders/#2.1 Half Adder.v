/******************************************************************************

                            #2.1 : Half Adder

*******************************************************************************/

/*
    Half Adders are used for adding 2 bits
    thses are made by using 2 gates :
        - An xor gate for SUM
        - An and gate for CARRY
*/ 

// adder code
module halfadder(a, b, sum, carry);
    input a, b;
    output sum, carry;

    assign sum = a ^ b;
    assign carry = a & b;
endmodule

// test bench of adder
module halfadder_tb;
    wire t_sum, t_carry;
    reg t_a, t_b;

    // creating half-adder object
    halfadder my_adder( .a(t_a), .b(t_b), .sum(t_sum), .carry(t_carry) );

    initial begin
        // monitoring output
        $monitor(t_a, t_b, t_sum, t_carry);

        // specifying cases
        t_a = 1'b0;
        t_b = 1'b0;
        #1
        
        t_a = 1'b0;
        t_b = 1'b1;
        #1

        t_a = 1'b1;
        t_b = 1'b0;
        #1

        t_a = 1'b1;
        t_b = 1'b1;

    end
endmodule