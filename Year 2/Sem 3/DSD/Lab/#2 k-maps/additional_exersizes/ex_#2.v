/******************************************************************************
    
                #2 : Second Additional Lab Exersize (pg. 11)

*******************************************************************************/

// equation to be calculated : 
// return 1 if the gate has 2 or 3 inputs
// i.e. return 0 if the gate has 1 or 4 inputs 

// hence, we use "or" to check if these 5 conditions are possible
// [ 4 conditons for 1 high input, 1 condition of all 4 high input ]
// then taking the negation to get the output 1 when 

// using continuous assignment statements
module exersixe_p1(a, b, c, d, f);
    input a, b, c, d;
    output f;

    assign f = ~( (a & ~b & ~c & ~d) | (~a & b & ~c & ~d) | 
                (~a & ~b & c & ~d) | (~a & ~b & ~c & d) | (a & b & c & d) );
endmodule