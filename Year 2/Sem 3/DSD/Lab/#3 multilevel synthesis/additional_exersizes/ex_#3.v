/******************************************************************************
    
                #3 : Third Additional Lab Exersize (pg. 15)

*******************************************************************************/

// equation to be minimized : 
// f(x1, x2, x3, x4) = ∑m(0, 4, 8, 13, 14, 15)

// the minimized term of the equation (from k-map) :
// Ans = x1'x3'x4' + x2'x3'x4' + x1x2x4 + x1x2x3

// the minimized term of the equation (from functional decomposition) :
// Ans = (x1' + x2')x3'x4' + (x3 + x4)x1x2  (taking common terms)
// Ans = (x1x2)'(x3 + x4)' + (x3 + x4)x1x2  (inverting -ve terms)

// let, g = (x1x2) and h = (x3 + x4)
// Ans = g'h' + hg  (replacing)

// Final Ans = gh + g'h'  (replacing)

// using continuous assignment statements
module exersixe_p1(x1, x2, x3, x4, f);
    input x1, x2, x3, x4;
    output f;

    // returning output using only functional decomposition

    // level 1
    assign g = x1 & x2;
    assign h = x3 | x4;

    // level2
    assign f = (g & h) | (~g & ~h);
endmodule