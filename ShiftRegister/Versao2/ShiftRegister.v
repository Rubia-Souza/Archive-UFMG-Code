module ShiftRegister(
  input clock,
  input novoBit,
  output reg [7:0] sequencia
);
  integer i;
  
  always @ (posedge clock) begin
    sequencia[0] <= novoBit;
    
    for(i = 1; i <= 7; i = i + 1) begin
      sequencia[i] <= sequencia[i-1];
    end
  end
  
endmodule