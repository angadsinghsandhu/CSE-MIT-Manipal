/******************************************************************************
    
                    #4 : Fourth Lab Exersize (pg. 18)

*******************************************************************************/

// importing 4-bit full adder
`include "./#3.v"

// TODO : (Figure this diagram out)

// code for a 4-bit full adder
module multiplier2(x1, x0, y1, y0, z0, z1, z2, z3);
    input k, c_in, x3, x2, x1, x0, y3, y2, y1, y0;
    output sum3, sum2, sum1, sum0, c_out;

    // creating full adder objects with xor of k and all y in input
    full_adder bit0 (.c_in(c_in), .x(x0), .y(xor(y0, k, y0)), .sum(sum0), .c_out(carry1));
    full_adder bit1 (.c_in(carry1), .x(x1), .y(xor(y1, k, y1)), .sum(sum1), .c_out(carry2));
    full_adder bit2 (.c_in(carry2), .x(x2), .y(xor(y2, k, y2)), .sum(sum2), .c_out(carry3));
    full_adder bit3 (.c_in(carry3), .x(x3), .y(xor(y3, k, y3)), .sum(sum3), .c_out(c_out));
endmodule