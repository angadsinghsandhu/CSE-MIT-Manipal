/******************************************************************************
    
                #1 : First Additional Lab Exersize (pg. 11)

*******************************************************************************/

// describing function
module exersize_p1(a, b, c, f1, f2);
    input a, b, c;
    output f1, f2;

    // assigning outputs
    assign f1 = (a & !c) | (b & c) | (!b & !c);
    assign f2 = (a | !b | c) & (a | b | !c) & (!a | b | !c);
endmodule