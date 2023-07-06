module testeOneTimePad();
  integer i;
  reg [31:0] mensagem = 32'b01100111011000010110110001101111; // Galo
  wire [31:0] resultadoCifrado;
  wire [31:0] resultadoDescifrado;
  
  
  OneTimePad cifrador(.mensagem(mensagem),
                      .mensagemCifrada(resultadoCifrado));
  
  OneTimePad descifrador(.mensagem(resultadoCifrado),
                         .mensagemCifrada(resultadoDescifrado));
  
  initial begin
    $monitor("mensagem original: %b | mensagem cifrada: %b | mensagem descifrada: %b",  mensagem, resultadoCifrado, resultadoDescifrado);
  end
endmodule