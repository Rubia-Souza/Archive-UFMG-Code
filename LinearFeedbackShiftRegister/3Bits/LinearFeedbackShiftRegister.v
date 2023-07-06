/* Linear Feedback Shift Register com 4 bits
 * Representando o polinômio: X^3 + X^2 + 1
 * Logo, utilizamos os taps 3 e 4
 */
module LinearFeedbackShiftRegister(
  input clock,
  input reset,
  output reg [1:3] sequencia
);
  wire proximoBit;
  
  assign proximoBit = sequencia[2] ^ sequencia[3];
  
  always @ (posedge clock) begin
    if(reset) begin
      sequencia <= 4'b011;
    end
    else begin
      sequencia <= {proximoBit, sequencia[1:2]};
    end
  end
  
endmodule