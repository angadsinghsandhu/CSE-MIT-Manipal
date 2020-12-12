/******************************************************************************
    
                #1 : First Additional Lab Exersize (pg. 11)

*******************************************************************************/

// equation to be minimized : 
// f(A, B, C, D, E) = ∑m(0, 1, 8, 9, 16, 17, 22, 23, 24, 25)

// the minimized term of the equation :
// Ans = AB'CD + C'D'


// using continuous assignment statements
module exersixe_p1(a, b, c, d, e, f);
    input a, b, c, d, e;
    output f;

    assign f = (a & ~b & c & d) | (~c & ~d);
endmodule