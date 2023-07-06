module ShiftRegister(
  input clock,
  input novoBit,
  output wire saidaFlipFlop1,
  output wire saidaFlipFlop2,
  output wire saidaFlipFlop3,
  output wire saidaFlipFlop4
);
  FlipFlopD ff1(.clock(clock),
                .d(novoBit),
                .q(saidaFlipFlop1));
  
  FlipFlopD ff2(.clock(clock),
                .d(saidaFlipFlop1),
                .q(saidaFlipFlop2));
  
  FlipFlopD ff3(.clock(clock),
                .d(saidaFlipFlop2),
                .q(saidaFlipFlop3));
  
  FlipFlopD ff4(.clock(clock),
                .d(saidaFlipFlop3),
                .q(saidaFlipFlop4));
endmodule

module FlipFlopD(
  input clock,
  input d,
  output reg q
);
  
  always @ (posedge clock) begin
    #1 q <= d;
  end
  
endmodule