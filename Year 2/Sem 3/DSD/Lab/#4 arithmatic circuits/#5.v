/******************************************************************************
    
                    #5 : Fifth Lab Exersize (pg. 18)

*******************************************************************************/

// importing 4-bit full adder/subtractor
`include "./#3.v"

// code for a 4-bit full adder
module multiplier2(c_in, x[3:0], y[3:0], s[0:3], c_out);
    input c_in, x[3:0], y[3:0];
    output s[0:3], c_out;

    // creating full adder/subtractor objects with xor of k and all y in input
    addersubtractor4 AS4_init (1'b0, c_in, x[3], x[2], x[1], x[0], y[3], y[2], y[1], y[0], sum3, sum2, sum1, sum0, carry1);

    // intermediate carry out circuit
    and(g1, sum3, sum2);
    and(g2, sum3, sum1);
    or(c_out, carry1, g1, g2);

    // creating full adder/subtractor objects to find the BCD value
    addersubtractor4 AS4_final (1'b0, 1'b0, 1'b0, c_out, c_out, 1'b0, sum3, sum2, sum1, sum0, s[3], s[2], s[1], s[0] carry2);

endmodule