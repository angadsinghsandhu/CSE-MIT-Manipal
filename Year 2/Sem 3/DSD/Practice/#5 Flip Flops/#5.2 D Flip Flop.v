/******************************************************************************

                            #5.2 : D Flip Flop

*******************************************************************************/

/*
    Flip Flops give us the same output as inputs,
    these are used to store data

    Some important things to keep in mind :
        - (Number of Input(s))^2 = (Number of Output lines)^2

        - 2x4 Decoder => 2 inputs, 4 output lines
        - 3x8 Decoder => 3 inputs, 8 output lines

        - 3 2x1 decoder are required to create a 4x1 decoder
        - 5 2x1 decoder are required to create a 8x1 decoder
*/ 

// d_flipflop using sequential code
module d_flipflop(d, clk, reset, q);
    input d, clk, reset;
    output q;
    reg q;

    // calculating on change in the 
    // positive edge (posedge) of clock (clk)
    always@(posedge clk)
    begin
        if(reset)
            q <= 1'b0;
        else
            q <= d;
    end
endmodule