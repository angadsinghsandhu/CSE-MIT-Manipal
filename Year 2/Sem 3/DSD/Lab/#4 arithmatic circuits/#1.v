/******************************************************************************
    
                    #1 : First Lab Exersize (pg. 18)

*******************************************************************************/

// code for a 1-bit half adder
module half_adder(x, y, sum, c_out);
    input x, y;
    output sum, c_out;

    // calculating sum by XORing
    assign sum = x ^ y;

    // calculating carry out by ADDing and ORing
    assign c_out = (x & y);
endmodule

// code for a 1-bit full adder
module full_adder(c_in, x, y, sum, c_out);
    input c_in, x, y;
    output sum, c_out;

    // calculating sum by XORing
    assign sum = c_in ^ x ^ y;

    // calculating carry out by ADDing and ORing
    assign c_out = (x & y) | (y & c_in) | (c_in & x);
endmodule

// code for a 1-bit decomposed full adder
module full_adder_decomposed(c_in, x, y, sum, c_out);
    input c_in, x, y;
    output sum, c_out;

    // instantiating objects
    half_adder h1 (.x(x), .y(y), .sum(s1), .c_out(c1));
    half_adder h2 (.x(s1), .y(c_in), .sum(sum), .c_out(c2));

    // getting final carry
    or(c_out, c1, c2)
endmodule