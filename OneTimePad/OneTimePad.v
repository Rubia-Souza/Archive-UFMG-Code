module OneTimePad(mensagem, mensagemCifrada);
  input [31:0] mensagem;
  output wire [31:0] mensagemCifrada;
  
  reg [31:0] cifra = 32'b01011110010000110010111101111100;
  
  assign mensagemCifrada = mensagem ^ cifra;
endmodule