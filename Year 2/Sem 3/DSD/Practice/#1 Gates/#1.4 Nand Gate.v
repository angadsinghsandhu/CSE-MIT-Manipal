/******************************************************************************

                            #1.4 : Nand Gate

*******************************************************************************/

// gate code
module nandgate(a, b, c);
    input a,b;
    output c;
    
    assign c = ~(a & b);
endmodule

// nand using cases
module nandgatecases(a, b, c);
    input a,b;
    output c;
    reg c;  // storing the value of c

    // executing code only when a or b change
    always @(a or b)
    begin
        case({a, b})

            // if (a,b) is (1,1) return 0
            2'b11:begin
                c = 1'b0;
            end

            // for all other cases return 1
            default:begin
                c = 1'b1;
            end
        endcase
    end
    
endmodule

// test bench of gate
module nandgate_tb;
    wire t_c;
    reg t_a, t_b;
    
    // creating gate object
    nandgate my_gate( .a(t_a), .b(t_b), .c(t_c) );
    
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