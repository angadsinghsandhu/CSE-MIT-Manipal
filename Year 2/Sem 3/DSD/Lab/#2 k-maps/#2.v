/******************************************************************************
    
                    #2 : Second Lab Exersize (pg. 13)

*******************************************************************************/

// PART (A)

// equation to be minimized : 
// f(A, B, C, D) = ΠM(0, 1, 4, 6, 8, 9, 12, 14)

// the minimized term of the equation :
// Ans = A'CD + AB'CD' + ABD


// using continuous assignment statements
module exersixe_p1(a, b, c, d, f);
    input a, b, c, d;
    output f;

    assign f = (~A & C & D) | (A & ~B & C & ~D) | (A & B & D);
endmodule


// PART (B)

// equation to be minimized : 
// f(A, B, C, D) = ΠM(6, 9, 10, 11, 12) + D(2, 4, 7, 13)

// the minimized term of the equation :
// Ans = B'C'D' + ABC + A'D


// using continuous assignment statements
module exersixe_p2(a, b, c, d, f);
    input a, b, c, d;
    output f;

    assign f = (~B & ~C & ~D) | (A & B & C) | (~A & D);
endmodule