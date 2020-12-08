/******************************************************************************
    
                    #2 : Second Lab Exersize (pg. 10)

*******************************************************************************/

// using gate-level primitive
module exersize_p1(a, b, c, d, f, y);
    input a, b, c, d;
    output f, y;

    // level 1
    nand(g, a, b);

    // level2
    xor(f, d, g, c);
    nor(y, b, c, d);
endmodule

// using continuous assignment statements
module exersixe_p2(a, b, c, d, f);
    input a, b, c, d;
    output f, y;

    assign f = d ^ (!(a & b)) ^ c;
    assign y = !(b | c | d);
endmodule