/******************************************************************************
    
                    #1 : First Lab Exersize (pg. 15)

*******************************************************************************/

// nand relations :
// - AND can be converted to NAND by inverting its output 
// - OR can be converted to NOR by inverting its output 
// - AND can be converted to NOR by inverting its inputs 
// - OR can be converted to NAND by inverting its inputs 

// equation to be minimized : 
// f(A, B, C, D) = ΠM(2, 6, 8, 9, 10, 11, 14)

// the minimized term of the equation :
// Ans = A'C' + A'D + BC' + BD


// using continuous assignment statements
module exersixe_p1(a, b, c, d, f);
    input a, b, c, d;
    output f;

    // returning output using only nand gate

    // level 1
    nand(g1, ~a, ~c);
    nand(g2, ~a, d);
    nand(g3, b, ~c);
    nand(g4, b, d);

    // level2
    nand(f, g1, g2, g3, g4);
endmodule