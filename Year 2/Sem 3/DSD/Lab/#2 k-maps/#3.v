/******************************************************************************
    
                    #3 : Third Lab Exersize (pg. 13)

*******************************************************************************/

// equation to be created : 
// An exualtion that takes in x1, x2, x3, x4 as inputs
// and outputs 1 if 3 or more inputs are 1, else 0


// using continuous assignment statements
module exersixe_p1(x1, x2, x3, x4, f);
    input x1, x2, x3, x4;
    output f;

    assign f = (x1 & x2 & x3) | (x1 & x3 & x4) | (x1 & x2 & x4) | (x2 & x3 & x4);
endmodule