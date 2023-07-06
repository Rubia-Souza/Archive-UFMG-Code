module TesteLinearFeedbackShiftRegister();
  reg clock;
  reg reset;
  wire [1:4] saida;
  integer i;
  
  LinearFeedbackShiftRegister linearFeedbackShiftRegister(.clock(clock),
                                                          .reset(reset),
                                                          .sequencia(saida));
  
  initial begin
    reset = 1;
    clock = 0;
    clock = 1;
    clock = 0;
    #5 reset = 0;
    
    for(i = 0; i < 30; i = i + 1) begin
      	#5 clock = ~clock;
    end
  end
  
  always @(saida[1], saida[2], saida[3], saida[4]) begin
    $display("%b%b%b%b", saida[1], saida[2], saida[3], saida[4]);
  end
endmodule