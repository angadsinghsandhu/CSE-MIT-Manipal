/******************************************************************************

                            #1.3 : Not Gate

*******************************************************************************/

// gate code
module notgate(a, b);
    input a;
    output b;

    assign b = ~a;
endmodule

// test bench of gate
module notgate_tb;
    wire t_b;
    reg t_a;

    // creating gate object
    notgate my_gate( .a(t_a), .b(t_b) );

    initial begin
        // monitoring the output
        $monitor(t_a, t_b);

        t_a = 1'b0;
        #1

        t_a = 1'b1;
        
    end
endmodule