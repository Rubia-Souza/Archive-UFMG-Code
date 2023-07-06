module TesteShiftRegister();
  reg clock;
  reg novoBit;
  wire [7:0] saida;
  integer i;
  
  ShiftRegister shiftRegister(.clock(clock),
                              .novoBit(novoBit),
                              .sequencia(saida));
  
  initial begin
    minotor;
    
    novoBit = 0;
    for(i = 0; i < 8; i = i + 1) begin 
      clock = 0;
      clock = 1;
      minotor;
    end
    
    novoBit = 1;
    for(i = 0; i < 8; i = i + 1) begin 
      clock = 0;
      clock = 1;
      minotor;
    end
  end
  
  task minotor;
    #2 $monitor("saida: %b", saida);
  endtask
  
endmodule