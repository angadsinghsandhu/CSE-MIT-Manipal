/******************************************************************************
    
                #2 : Second Additional Lab Exersize (pg. 11)

*******************************************************************************/

// importing half adder
`include "./ex_#1.v"

// NOTE : check timing graph

// checking for functional equavalent / testbenching our first code
module exersize_p2;
    input a, b, c;
    output f1, f2;

    reg t_a, t_b, t_c;
    wire t_f1, t_f2;

    // creating exersize 1 object
    exersize_p1 p1( .a(t_a), .b(t_b), .c(t_c), .f1(t_f1), .f2(t_f2) );

    // NOTE : We will now see the output of f1 and f2 be
    // exactly the same
    initial begin
        // monitoring output
        $display("abc  f1f2");
        $monitor(t_a, t_b, t_c, " : ", t_f1, t_f2);

        // specifying cases
        // (c==0)
        t_a = 1'b0;
        t_b = 1'b0;
        t_c = 1'b0;
        #1
        
        t_a = 1'b1;
        t_b = 1'b0;
        t_c = 1'b0;
        #1

        t_a = 1'b0;
        t_b = 1'b1;
        t_c = 1'b0;
        #1

        t_a = 1'b1;
        t_b = 1'b1;
        t_c = 1'b0;
        #1

        // (c==1)
        t_a = 1'b0;
        t_b = 1'b0;
        t_c = 1'b1;
        #1
        
        t_a = 1'b1;
        t_b = 1'b0;
        t_c = 1'b1;
        #1

        t_a = 1'b0;
        t_b = 1'b1;
        t_c = 1'b1;
        #1

        t_a = 1'b1;
        t_b = 1'b1;
        t_c = 1'b1;
    end
endmodule