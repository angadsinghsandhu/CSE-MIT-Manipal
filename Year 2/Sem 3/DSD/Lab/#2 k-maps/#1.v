/******************************************************************************
    
                    #1 : First Lab Exersize (pg. 13)

*******************************************************************************/

// PART (A)

// equation to be minimized : 
// f(A, B, C, D) = ∑m(2, 3, 4, 5, 6, 7, 10, 11, 12, 15)

// the minimized term of the equation :
// Ans = A'B + B'C + BC'D' + CD


// using continuous assignment statements
module exersixe_p1(a, b, c, d, f);
    input a, b, c, d;
    output f;

    assign f = (~a & b) | (~b & c) | (b & ~c & ~d) | (c & d);
endmodule


// PART (B)

// equation to be minimized : 
// f(A, B, C, D) = ∑m(1, 3, 4, 9, 10, 12) + D(0, 2, 5, 11)

// the minimized term of the equation :
// Ans = B'D + B'C + BC'D'


// using continuous assignment statements
module exersixe_p2(a, b, c, d, f);
    input a, b, c, d;
    output f;

    assign f = (~B & D) | (~B & C) | (B & ~C & ~D);
endmodule

	
Π