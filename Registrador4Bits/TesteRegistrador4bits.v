module TesteRegistrador4bits();
  reg clock;
  reg d1;
  reg d2;
  reg d3;
  reg d4;
  wire q1;
  wire q2;
  wire q3;
  wire q4;
  
  Registrador4bits regisrador(.d1(d1),
                              .d2(d2),
                              .d3(d3),
                              .d4(d4),
                              .q1(q1),
                              .q2(q2),
                              .q3(q3),
                              .q4(q4),
                              .clock(clock));
  
  initial begin
    d1 = 1;
    d2 = 0;
    d3 = 1;
    d4 = 1;
    clock = 1;
    display;
    
    d1 = 0;
    d2 = 1;
    d3 = 0;
    d4 = 0;
    clock = 1;
    display;
    
    clock = 0;
    clock = 1;
    display;
  end
  
  task display;
    #1 $display("d1:%0h, d2:%0h, d3:%0h, d4:%0h, q1:%0h, q2:%0h, q3:%0h, q4:%0h, clock:%0h", d1, d2, d3, d4, q1, q2, q3, q4, clock);
  endtask
endmodule