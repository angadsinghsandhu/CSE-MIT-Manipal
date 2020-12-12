/******************************************************************************
    
                    #4 : Fourth Lab Exersize (pg. 15)

*******************************************************************************/

// equation to be minimized : 
// f(A, B, C, D) = ∑m(1, 3, 5, 7, 9) + D(6, 12, 13)

// the minimized term of the equation :
// Ans = A'D + C'D


// using continuous assignment statements
module exersixe_p1(a, b, c, d, f);
    input a, b, c, d;
    output f;

    assign f = (~a & d) | (~c & d);

    // returning output using only nor gate

    // level 1
    nor(g1, a, ~d);
    nor(g2, c, ~d);

    // level2
    nor(~f, g1, g2);
endmodule