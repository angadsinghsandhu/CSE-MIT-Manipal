/******************************************************************************
    
                    #1 : First Lab Exersize (pg. 10)

*******************************************************************************/

// using gate-level primitive
module exersize_p1(a, b, c, d, f);
    input a, b, c, d;
    output f;

    // level 1
    and(g1, a, b);
    and(g2, a, b);

    // level 2
    or(h1, g1, c);
    or(h2, g2, c);

    // level 3
    not(h1_not, h1);

    and(i1, h1_not, d);
    or(i2, h2, d);

    // level 4
    and(f, i1, i2);
endmodule

// using continuous assignment statements
module exersixe_p2(a, b, c, d, f);
    input a, b, c, d;
    output f;

    assign f = (!((a & b) | c) & d) & (((a & b) | c) | d);
endmodule