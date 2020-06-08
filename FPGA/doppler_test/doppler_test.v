`default_nettype none

module top ( 				input 	     cfg_cs, input cfg_si, input cfg_sck, // SPI:     samd51 <-> ice40  for bitstream and user cases
					output 	     cfg_so, // SPI Out
					output 	     pa22, 
					 );												
	
   // use ice40up5k 48Mhz internal oscillator
   wire 					     clk; 
   //wire clk48; 
   SB_HFOSC inthosc ( .CLKHFPU(1'b1), .CLKHFEN(1'b1), .CLKHF(clk) );
   // pll my100mhz(.clock_in(clk48), .clock_out(clk) /* , output locked */ );


   wire 					     pwmout;
   

   SB_IO #( .PIN_TYPE(6'b 011001) ) pin_out_driver ( .PACKAGE_PIN(pa22),	.D_OUT_0(pwmout) );
 	

// for PWM testcode: https://hackaday.io/project/162557-fpga-dabbling
   
   reg reset = 0;

//   wire clk_dc;
   reg [15:0] dc = 0;
//   clockdivider clkdiv(clk, 12000000, clk_dc);

   pwm #(.bits(16)) pwm0(clk, reset,16'd15999,dc,pwmout); // pinbank1[0]
   always @(posedge clk)
     begin
	dc <= (dc == 16000) ? 0 : (dc + 1);
     end
		
endmodule		// end top module

module pwm #(
  parameter bits = 4
  )(
  input wire clkin,
  input reset,
  input[bits-1:0] max,
  input[bits-1:0] compare,
  output out
);

reg[bits-1:0] count = 0;
reg[bits-1:0] compareLatched = 0;

always @(posedge clkin)
begin
  if(reset == 1)
    begin
      count <= 0;
      compareLatched <= 0;
    end
  else
    begin
      if(count == 0)
        begin
          count <= max-1;
          compareLatched <= compare;
        end
      else
        count <= count-1;
    end
end
assign out = count < compareLatched;

endmodule
