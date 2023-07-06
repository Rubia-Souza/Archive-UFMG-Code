module TesteShiftRegister();
  reg clock;
  reg novoBit;
  wire saida1;
  wire saida2;
  wire saida3;
  wire saida4;
  
  ShiftRegister shiftRegister(.clock(clock),
                              .novoBit(novoBit),
                              .saidaFlipFlop1(saida1),
                              .saidaFlipFlop2(saida2),
                              .saidaFlipFlop3(saida3),
                              .saidaFlipFlop4(saida4));
  
  initial begin
    display;
    
    novoBit = 1;
    clock = 0;
    clock = 1;
    display;
    
    clock = 1;
    clock = 0;
    display;
    
    clock = 1;
    clock = 0;
    display;
    
    clock = 1;
    clock = 0;
    display;
    
    clock = 1;
    clock = 0;
    display;
    
    novoBit = 0;
    clock = 1;
    clock = 0;
    display;
    
    clock = 1;
    clock = 0;
    display;
    
    clock = 1;
    clock = 0;
    display;
    
    clock = 1;
    clock = 0;
    display;
  end
  
  task display;
    #40 $display("saida1:%0h, saida2:%0h, saida3:%0h, saida4:%0h", saida1, saida2, saida3, saida4);
  endtask
  
endmodule