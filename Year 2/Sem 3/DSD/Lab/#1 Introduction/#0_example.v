/******************************************************************************
    
                    #0 : Sample verilog code (pg. 8)

*******************************************************************************/

// using gate-level primitive
module example(x1, x2, x3, f);
    input x1, x2, x3;
    output f;

    and(g, x1, x2);
    not(k, x2);
    and(h, k, x3);
    or(f, g, h);
endmodule

// using continuous assignment statements
module example2(x1, x2, x3, f);
    input x1, x2, x3;
    output f;

    assign f = (x1 & x2) | (!x2 & x3);
endmodule