module TesteLinearFeedbackShiftRegister();
  reg clock;
  reg reset;
  wire [1:8] saida;
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
  end
  
  always begin
    #5 clock = ~clock;
  end
  
  always @(saida[1], saida[2], saida[3], saida[4], saida[5], saida[6], saida[7], saida[8]) begin
    $display("%b%b%b%b%b%b%b%b", saida[1], saida[2], saida[3], saida[4], saida[5], saida[6], saida[7], saida[8]);
  end
endmodule