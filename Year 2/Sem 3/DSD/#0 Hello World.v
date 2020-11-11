/******************************************************************************

                        #1 : Hello World in Verolog

*******************************************************************************/

module hello_world ;

  // adding clock
  always @(posedge i_clock)

  // creating 2 binarys and storing it in a register
  reg i = 2'b01;
  reg j = 4'b1001;

  initial begin
    $display ("Hello World by Angad");
    #10  $finish;
  end

endmodule // End of Module hello_world