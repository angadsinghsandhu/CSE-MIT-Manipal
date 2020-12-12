/******************************************************************************
    
                    #3 : Third Lab Exersize (pg. 15)

*******************************************************************************/

// equation to be minimized : 
// f(x1, x2, x3, x4, x5) = ∑m(1, 2, 7, 9, 10, 18, 19, 25, 31) + D(0, 15, 20, 26)

// the minimized term of the equation (from k-map) :
// Ans = x1'x3x4x5 + x3'x4x5' + x1x2'x3'x4 + x2x3'x4'x5 + x2x3x4x5 + x1'x2'x3'x4'

// the minimized term of the equation (from functional decomposition) :

// TODO : (execute functional decomposition)

// Ans = x1'x3x4x5 + x3'x4x5' + x1x2'x3'x4 + x2x3'x4'x5 + x2x3x4x5 + x1'x2'x3'x4'


// using continuous assignment statements
module exersixe_p1(a, b, c, d, f);
    input a, b, c, d;
    output f;

    assign f = (~B & ~D) | (~A & ~C & D) | (~B & ~C);

    // returning output using only nor gate

    // level 1
    nor(g1, b, d);
    nor(g2, a, c, ~d);
    nor(g3, b, c);

    // level2
    nor(h, g1, g2, g3);

    // level 3
    not(f, h);
endmodule