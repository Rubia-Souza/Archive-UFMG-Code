/* Linear Feedback Shift Register com 4 bits
 * Representando o polinômio: X^8 + X^6 + X^5 + X^4 + 1
 * Logo, utilizamos os taps 8, 6, 5 e 4
 */
module LinearFeedbackShiftRegister(
  input clock,
  input reset,
  output reg [1:8] sequencia
);
  wire proximoBit;
  
  assign proximoBit = sequencia[8] ^ sequencia[6] ^ sequencia[5] ^ sequencia[4];
  
  always @ (posedge clock) begin
    if(reset) begin
      sequencia <= 4'b0111;
    end
    else begin
      sequencia <= {proximoBit, sequencia[1:7]};
    end
  end
  
endmodule