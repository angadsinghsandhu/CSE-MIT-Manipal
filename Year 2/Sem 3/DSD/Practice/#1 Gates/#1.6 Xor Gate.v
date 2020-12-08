/******************************************************************************

                            #1.6 : Xor Gate

*******************************************************************************/

// gate code
module xorgate(a, b, c);
    input a,b;
    output c;
    
    assign c = a ^ b;
endmodule

// test bench of gate
module xorgate_tb;
    wire t_c;
    reg t_a, t_b;
    
    // creating gate object
    xorgate my_gate( .a(t_a), .b(t_b), .c(t_c) );
    
    initial begin
        // monitoring the output
        $monitor(t_a, t_b, t_c);
        
        t_a = 1'b0;
        t_b = 1'b0;
        
        #1
        t_a = 1'b0;
        t_b = 1'b1;
        
        #1
        t_a = 1'b1;
        t_b = 1'b0;
        
        #1
        t_a = 1'b1;
        t_b = 1'b1;
    
    end
endmodule