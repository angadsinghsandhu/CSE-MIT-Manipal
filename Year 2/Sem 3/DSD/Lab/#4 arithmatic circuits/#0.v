/******************************************************************************
    
                    #0 : Sample Lab Exersize (pg. 18)

*******************************************************************************/

// writing code to implement a 4 bit adder

// code for a 1-bit full adder
module full_adder(c_in, x, y, sum, c_out);
    input c_in, x, y;
    output sum, c_out;

    // calculating sum by XORing
    assign sum = c_in ^ x ^ y;

    // calculating carry out by ADDing and ORing
    assign c_out = (x & y) | (y & c_in) | (c_in & x);
endmodule

// code for a 4-bit full adder
module adder4(c_in, x3, x2, x1, x0, y3, y2, y1, y0, sum3, sum2, sum1, sum0, c_out);
    input c_in, x3, x2, x1, x0, y3, y2, y1, y0;
    output sum3, sum2, sum1, sum0, c_out;

    // creating full adder objects
    full_adder bit0 (.c_in(c_in), .x(x0), .y(y0), .sum(sum0), .c_out(carry1));
    full_adder bit1 (.c_in(carry1), .x(x1), .y(y1), .sum(sum1), .c_out(carry2));
    full_adder bit2 (.c_in(carry2), .x(x2), .y(y2), .sum(sum2), .c_out(carry3));
    full_adder bit3 (.c_in(carry3), .x(x3), .y(y3), .sum(sum3), .c_out(c_out));
endmodule