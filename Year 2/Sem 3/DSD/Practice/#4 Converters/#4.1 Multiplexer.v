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

        - 3 2x1 mux are required to create a 4x1 mux
        - 5 2x1 mux are required to create a 8x1 mux
*/ 

// 2:1 mux using condition code
module mux2x1_if(a, b, s, y);
    input a, b, s;
    output y;

    assign y = s ? b : a;
endmodule

// 2:1 mux using structural modeling code
module mux2x1(a, b, s, y);
    input a, b, s;
    output y;

    reg y;

    always@(a or b or s)
        if(~s)
            y=a;
        else
            y=b;
    
endmodule

// 2:1 mux using structural modeling code
module mux4x1(a, b, c, d, s1, s2, y);
    input a, b, c, d, s1, s2;
    output y;
    wire temp1, temp2;

    // defining 2x1 mux objects
    mux2x1 m1(.a(a), .b(b), .s(s1), .y(temp1));
    mux2x1 m2(.a(c), .b(d), .s(s1), .y(temp2));
    mux2x1 m3(.a(temp1), .b(temp2), .s(s2), .y(y));
endmodule

// test bench for 2x1 multiplexer
module mux2_tb;
    reg t_a, t_b, t_s;
    wire t_y;

    // creating mux object
    mux2x1 mux2( .a(t_a), .b(t_b), .s(t_s), .y(t_y) );

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

// test bench for 4x1 multiplexer
module mux4_tb;
    reg t_a, t_b, t_c, t_d, t_s1, t_s2;
    wire t_y;

    // creating mux object
    mux4x1 mux4( .a(t_a), .b(t_b), .c(t_c), .d(t_d), .s1(t_s1), .s2(t_s2), .y(t_y) );

    initial begin
        // monitoring
        $monitor(t_a, t_b, t_c, t_d, t_s1, t_s2, t_y);

        // specifying cases
        // (s1,s2==00)
        t_a = 1'b0;
        t_b = 1'b0;
        t_c = 1'b0;
        t_d = 1'b0;
        t_s1 = 1'b0;
        t_s2 = 1'b0;
        #1
        
        t_a = 1'b1;
        t_b = 1'b0;
        t_c = 1'b0;
        t_d = 1'b0;
        t_s1 = 1'b0;
        t_s2 = 1'b0;
        #1

        t_a = 1'b0;
        t_b = 1'b1;
        t_c = 1'b0;
        t_d = 1'b0;
        t_s1 = 1'b0;
        t_s2 = 1'b0;
        #1

        t_a = 1'b1;
        t_b = 1'b1;
        t_c = 1'b0;
        t_d = 1'b0;
        t_s1 = 1'b0;
        t_s2 = 1'b0;
        #1

        t_a = 1'b0;
        t_b = 1'b0;
        t_c = 1'b1;
        t_d = 1'b0;
        t_s1 = 1'b0;
        t_s2 = 1'b0;
        #1

        t_a = 1'b1;
        t_b = 1'b0;
        t_c = 1'b1;
        t_d = 1'b0;
        t_s1 = 1'b0;
        t_s2 = 1'b0;
        #1

        t_a = 1'b0;
        t_b = 1'b1;
        t_c = 1'b1;
        t_d = 1'b0;
        t_s1 = 1'b0;
        t_s2 = 1'b0;
        #1

        t_a = 1'b1;
        t_b = 1'b1;
        t_c = 1'b1;
        t_d = 1'b0;
        t_s1 = 1'b0;
        t_s2 = 1'b0;
        #1

        t_a = 1'b0;
        t_b = 1'b0;
        t_c = 1'b0;
        t_d = 1'b1;
        t_s1 = 1'b0;
        t_s2 = 1'b0;
        #1

        t_a = 1'b1;
        t_b = 1'b0;
        t_c = 1'b0;
        t_d = 1'b1;
        t_s1 = 1'b0;
        t_s2 = 1'b0;
        #1

        t_a = 1'b0;
        t_b = 1'b1;
        t_c = 1'b0;
        t_d = 1'b1;
        t_s1 = 1'b0;
        t_s2 = 1'b0;
        #1

        t_a = 1'b1;
        t_b = 1'b1;
        t_c = 1'b0;
        t_d = 1'b1;
        t_s1 = 1'b0;
        t_s2 = 1'b0;
        #1

        t_a = 1'b0;
        t_b = 1'b0;
        t_c = 1'b1;
        t_d = 1'b1;
        t_s1 = 1'b0;
        t_s2 = 1'b0;
        #1

        t_a = 1'b1;
        t_b = 1'b0;
        t_c = 1'b1;
        t_d = 1'b1;
        t_s1 = 1'b0;
        t_s2 = 1'b0;
        #1

        t_a = 1'b0;
        t_b = 1'b1;
        t_c = 1'b1;
        t_d = 1'b1;
        t_s1 = 1'b0;
        t_s2 = 1'b0;
        #1

        t_a = 1'b1;
        t_b = 1'b1;
        t_c = 1'b1;
        t_d = 1'b1;
        t_s1 = 1'b0;
        t_s2 = 1'b0;
        #1

        // (s1,s2==10)
        t_a = 1'b0;
        t_b = 1'b0;
        t_c = 1'b0;
        t_d = 1'b0;
        t_s1 = 1'b1;
        t_s2 = 1'b0;
        #1
        
        t_a = 1'b1;
        t_b = 1'b0;
        t_c = 1'b0;
        t_d = 1'b0;
        t_s1 = 1'b1;
        t_s2 = 1'b0;
        #1

        t_a = 1'b0;
        t_b = 1'b1;
        t_c = 1'b0;
        t_d = 1'b0;
        t_s1 = 1'b1;
        t_s2 = 1'b0;
        #1

        t_a = 1'b1;
        t_b = 1'b1;
        t_c = 1'b0;
        t_d = 1'b0;
        t_s1 = 1'b1;
        t_s2 = 1'b0;
        #1

        t_a = 1'b0;
        t_b = 1'b0;
        t_c = 1'b1;
        t_d = 1'b0;
        t_s1 = 1'b1;
        t_s2 = 1'b0;
        #1

        t_a = 1'b1;
        t_b = 1'b0;
        t_c = 1'b1;
        t_d = 1'b0;
        t_s1 = 1'b1;
        t_s2 = 1'b0;
        #1

        t_a = 1'b0;
        t_b = 1'b1;
        t_c = 1'b1;
        t_d = 1'b0;
        t_s1 = 1'b1;
        t_s2 = 1'b0;
        #1

        t_a = 1'b1;
        t_b = 1'b1;
        t_c = 1'b1;
        t_d = 1'b0;
        t_s1 = 1'b1;
        t_s2 = 1'b0;
        #1

        t_a = 1'b0;
        t_b = 1'b0;
        t_c = 1'b0;
        t_d = 1'b1;
        t_s1 = 1'b1;
        t_s2 = 1'b0;
        #1

        t_a = 1'b1;
        t_b = 1'b0;
        t_c = 1'b0;
        t_d = 1'b1;
        t_s1 = 1'b1;
        t_s2 = 1'b0;
        #1

        t_a = 1'b0;
        t_b = 1'b1;
        t_c = 1'b0;
        t_d = 1'b1;
        t_s1 = 1'b1;
        t_s2 = 1'b0;
        #1

        t_a = 1'b1;
        t_b = 1'b1;
        t_c = 1'b0;
        t_d = 1'b1;
        t_s1 = 1'b1;
        t_s2 = 1'b0;
        #1

        t_a = 1'b0;
        t_b = 1'b0;
        t_c = 1'b1;
        t_d = 1'b1;
        t_s1 = 1'b1;
        t_s2 = 1'b0;
        #1

        t_a = 1'b1;
        t_b = 1'b0;
        t_c = 1'b1;
        t_d = 1'b1;
        t_s1 = 1'b1;
        t_s2 = 1'b0;
        #1

        t_a = 1'b0;
        t_b = 1'b1;
        t_c = 1'b1;
        t_d = 1'b1;
        t_s1 = 1'b1;
        t_s2 = 1'b0;
        #1

        t_a = 1'b1;
        t_b = 1'b1;
        t_c = 1'b1;
        t_d = 1'b1;
        t_s1 = 1'b1;
        t_s2 = 1'b0;
        #1

        // (s1,s2==01)
        t_a = 1'b0;
        t_b = 1'b0;
        t_c = 1'b0;
        t_d = 1'b0;
        t_s1 = 1'b0;
        t_s2 = 1'b1;
        #1
        
        t_a = 1'b1;
        t_b = 1'b0;
        t_c = 1'b0;
        t_d = 1'b0;
        t_s1 = 1'b0;
        t_s2 = 1'b1;
        #1

        t_a = 1'b0;
        t_b = 1'b1;
        t_c = 1'b0;
        t_d = 1'b0;
        t_s1 = 1'b0;
        t_s2 = 1'b1;
        #1

        t_a = 1'b1;
        t_b = 1'b1;
        t_c = 1'b0;
        t_d = 1'b0;
        t_s1 = 1'b0;
        t_s2 = 1'b1;
        #1

        t_a = 1'b0;
        t_b = 1'b0;
        t_c = 1'b1;
        t_d = 1'b0;
        t_s1 = 1'b0;
        t_s2 = 1'b1;
        #1

        t_a = 1'b1;
        t_b = 1'b0;
        t_c = 1'b1;
        t_d = 1'b0;
        t_s1 = 1'b0;
        t_s2 = 1'b1;
        #1

        t_a = 1'b0;
        t_b = 1'b1;
        t_c = 1'b1;
        t_d = 1'b0;
        t_s1 = 1'b0;
        t_s2 = 1'b1;
        #1

        t_a = 1'b1;
        t_b = 1'b1;
        t_c = 1'b1;
        t_d = 1'b0;
        t_s1 = 1'b0;
        t_s2 = 1'b1;
        #1

        t_a = 1'b0;
        t_b = 1'b0;
        t_c = 1'b0;
        t_d = 1'b1;
        t_s1 = 1'b0;
        t_s2 = 1'b1;
        #1

        t_a = 1'b1;
        t_b = 1'b0;
        t_c = 1'b0;
        t_d = 1'b1;
        t_s1 = 1'b0;
        t_s2 = 1'b1;
        #1

        t_a = 1'b0;
        t_b = 1'b1;
        t_c = 1'b0;
        t_d = 1'b1;
        t_s1 = 1'b0;
        t_s2 = 1'b1;
        #1

        t_a = 1'b1;
        t_b = 1'b1;
        t_c = 1'b0;
        t_d = 1'b1;
        t_s1 = 1'b0;
        t_s2 = 1'b1;
        #1

        t_a = 1'b0;
        t_b = 1'b0;
        t_c = 1'b1;
        t_d = 1'b1;
        t_s1 = 1'b0;
        t_s2 = 1'b1;
        #1

        t_a = 1'b1;
        t_b = 1'b0;
        t_c = 1'b1;
        t_d = 1'b1;
        t_s1 = 1'b0;
        t_s2 = 1'b1;
        #1

        t_a = 1'b0;
        t_b = 1'b1;
        t_c = 1'b1;
        t_d = 1'b1;
        t_s1 = 1'b0;
        t_s2 = 1'b1;
        #1

        t_a = 1'b1;
        t_b = 1'b1;
        t_c = 1'b1;
        t_d = 1'b1;
        t_s1 = 1'b0;
        t_s2 = 1'b1;
        #1

        // (s1,s2==11)
        t_a = 1'b0;
        t_b = 1'b0;
        t_c = 1'b0;
        t_d = 1'b0;
        t_s1 = 1'b1;
        t_s2 = 1'b1;
        #1
        
        t_a = 1'b1;
        t_b = 1'b0;
        t_c = 1'b0;
        t_d = 1'b0;
        t_s1 = 1'b1;
        t_s2 = 1'b1;
        #1

        t_a = 1'b0;
        t_b = 1'b1;
        t_c = 1'b0;
        t_d = 1'b0;
        t_s1 = 1'b1;
        t_s2 = 1'b1;
        #1

        t_a = 1'b1;
        t_b = 1'b1;
        t_c = 1'b0;
        t_d = 1'b0;
        t_s1 = 1'b1;
        t_s2 = 1'b1;
        #1

        t_a = 1'b0;
        t_b = 1'b0;
        t_c = 1'b1;
        t_d = 1'b0;
        t_s1 = 1'b1;
        t_s2 = 1'b1;
        #1

        t_a = 1'b1;
        t_b = 1'b0;
        t_c = 1'b1;
        t_d = 1'b0;
        t_s1 = 1'b1;
        t_s2 = 1'b1;
        #1

        t_a = 1'b0;
        t_b = 1'b1;
        t_c = 1'b1;
        t_d = 1'b0;
        t_s1 = 1'b1;
        t_s2 = 1'b1;
        #1

        t_a = 1'b1;
        t_b = 1'b1;
        t_c = 1'b1;
        t_d = 1'b0;
        t_s1 = 1'b1;
        t_s2 = 1'b1;
        #1

        t_a = 1'b0;
        t_b = 1'b0;
        t_c = 1'b0;
        t_d = 1'b1;
        t_s1 = 1'b1;
        t_s2 = 1'b1;
        #1

        t_a = 1'b1;
        t_b = 1'b0;
        t_c = 1'b0;
        t_d = 1'b1;
        t_s1 = 1'b1;
        t_s2 = 1'b1;
        #1

        t_a = 1'b0;
        t_b = 1'b1;
        t_c = 1'b0;
        t_d = 1'b1;
        t_s1 = 1'b1;
        t_s2 = 1'b1;
        #1

        t_a = 1'b1;
        t_b = 1'b1;
        t_c = 1'b0;
        t_d = 1'b1;
        t_s1 = 1'b1;
        t_s2 = 1'b1;
        #1

        t_a = 1'b0;
        t_b = 1'b0;
        t_c = 1'b1;
        t_d = 1'b1;
        t_s1 = 1'b1;
        t_s2 = 1'b1;
        #1

        t_a = 1'b1;
        t_b = 1'b0;
        t_c = 1'b1;
        t_d = 1'b1;
        t_s1 = 1'b1;
        t_s2 = 1'b1;
        #1

        t_a = 1'b0;
        t_b = 1'b1;
        t_c = 1'b1;
        t_d = 1'b1;
        t_s1 = 1'b1;
        t_s2 = 1'b1;
        #1

        t_a = 1'b1;
        t_b = 1'b1;
        t_c = 1'b1;
        t_d = 1'b1;
        t_s1 = 1'b1;
        t_s2 = 1'b1;
        
    end

endmodule