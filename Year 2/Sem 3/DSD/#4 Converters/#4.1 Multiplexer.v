/******************************************************************************

                            #4.1 : Multiplexers

*******************************************************************************/

/*
    Multiplexers are used for selecting one input
    as output from multiple inputs, this is done using
    select lines which are separate inputs

    Some important things to keep in mind :
        - If the MUX has 2 inputs it will have 1 
          Select Line, similarly if the MUX has 4 
          inputs it will have 2 Select Lines

        - Number of Inputs = (Number of Select Line(s))^2

        - 2x1 MUX => 2 inputs, 1 output, 1 select line

        - 4x1 MUX => 4 inputs, 1 output, 2 select lines
*/ 

// 2:1 mux using condition code
module mux2x1(a, b, s, y);
    input a, b, s;
    output y;

    assign y = s ? b : a;
endmodule

// // 4:1 mux using structural modeling code
// module mux4x1(a, b, c, d, s1, s2, y);
//     input a, b, s;
//     output y;

//     assign y = s ? b : a;
// endmodule

// test bench for multiplexer
module mux_tb;
    reg t_a, t_b, t_s;
    wire t_y;

    // creating mux object
    mux2x1 mux( .a(t_a), .b(t_b), .s(t_s), .y(t_y) );

    initial begin
        // monitoring
        $monitor(t_a, t_b, t_s, t_y);

        // specifying cases
        // (s==0)
        t_a = 1'b0;
        t_b = 1'b0;
        t_s = 1'b0;
        #1
        
        t_a = 1'b1;
        t_b = 1'b0;
        t_s = 1'b0;
        #1

        t_a = 1'b0;
        t_b = 1'b1;
        t_s = 1'b0;
        #1

        t_a = 1'b1;
        t_b = 1'b1;
        t_s = 1'b0;
        #1

        // (s==1)
        t_a = 1'b0;
        t_b = 1'b0;
        t_s = 1'b1;
        #1
        
        t_a = 1'b1;
        t_b = 1'b0;
        t_s = 1'b1;
        #1

        t_a = 1'b0;
        t_b = 1'b1;
        t_s = 1'b1;
        #1

        t_a = 1'b1;
        t_b = 1'b1;
        t_s = 1'b1;
    end

endmodule