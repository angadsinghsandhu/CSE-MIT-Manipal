/******************************************************************************
    
                #1 : First Additional Lab Exersize (pg. 15)

*******************************************************************************/

// equation to be minimized : 
// f(A, B, C, D) = ΠM(1, 3, 5, 8, 9, 11, 15) + D(2, 13) 

// the minimized term of the equation :
// Ans = A'C'D' + A'BC + ACD' + ABC'


// using continuous assignment statements
module exersixe_p1(a, b, c, d, f);
    input a, b, c, d;
    output f;

    // returning output using only nand gate

    // level 1
    nand(~g1, ~a, ~c, ~d);
    nand(~g2, ~a, b, c);
    nand(~g3, a, c, ~d);
    nand(~g4, a, b, ~c);

    // level2
    nand(f, ~g1, ~g2, ~g3, ~g4);
endmodule