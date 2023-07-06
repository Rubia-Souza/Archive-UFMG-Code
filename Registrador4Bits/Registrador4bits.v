module Registrador4bits(
  input clock,
  input d1,
  input d2,
  input d3,
  input d4,
  output reg q1,
  output reg q2,
  output reg q3,
  output reg q4
);
  
  always @ (posedge clock) begin
    q1 <= d1;
    q2 <= d2;
    q3 <= d3;
    q4 <= d4;
  end
  
endmodule