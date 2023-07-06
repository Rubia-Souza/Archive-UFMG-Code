/* Linear Feedback Shift Register com 4 bits
 * Representando o polinômio: X^4 + X^3 + 1
 * Logo, utilizamos os taps 3 e 4
 */
module LinearFeedbackShiftRegister(
  input clock,
  input reset,
  output reg [1:4] sequencia
);
  wire proximoBit;
  
  assign proximoBit = sequencia[3] ^ sequencia[4];
  
  always @ (posedge clock) begin
    if(reset) begin
      sequencia <= 4'b0111;
    end
    else begin
      sequencia <= {proximoBit, sequencia[1:3]};
    end
  end
  
endmodule