/******************************************************************************

                            #4.2 : Decoders

*******************************************************************************/

/*
    Decoders the ooposite of multiplexers are used for 
    decoding multiple outputs from single inputs.
    based on the input value one of the output lines
    will have value 1 and all other lines will be 0

    Some important things to keep in mind :
        - (Number of Input(s))^2 = (Number of Output lines)^2

        - 2x4 Decoder => 2 inputs, 4 output lines
        - 3x8 Decoder => 3 inputs, 8 output lines

        - 3 2x1 decoder are required to create a 4x1 decoder
        - 5 2x1 decoder are required to create a 8x1 decoder
*/ 

// 2:1 decoder using condition code
module decoder2x4(a, y);
    input [1:0]a;
    output [3:0]y;
    reg [3:0]y;

    // calculating on change in the value of a
    always@(a)
    begin
        y[3] = a[1] & a[0];
        y[2] = !a[1] & a[0];
        y[1] = a[1] & !a[0];
        y[0] = !a[1] & !a[0];
    end
endmodule

// creating test bench for decoder
module decoder2x4_tb;
    reg [1:0]t_a;
    wire [3:0]t_y;

    // creating decoder object
    decoder2x4 dec( .a(t_a), .y(t_y) );

    initial begin
        // monitoring output
        $display("ab  dddd");
        $monitor(t_a[0], t_a[1], " ",t_y[0], t_y[1], t_y[2], t_y[3]);

        // creating cases
        t_a[0] = 1'b0; 
        t_a[1] = 1'b0;
        #1
         
        t_a[0] = 1'b1; 
        t_a[1] = 1'b0;
        #1
        
        t_a[0] = 1'b0; 
        t_a[1] = 1'b1;
        #1
        
        t_a[0] = 1'b1; 
        t_a[1] = 1'b1;
    end
endmodule