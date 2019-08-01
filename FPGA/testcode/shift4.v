// now 8 bit shift register with all led outs

// c18 in first one pcf to measure out 1.5 MHz -> as we have 12 MHz clock on lattice board///
// that was with simple shift of one bit - for 10101010 =170DEC we have 6 MHz as expected...

// TODO:

/*
 
- 32 bits
- RNG shift reg LFSR  - now working below!

 - how do we deal with inputs? - say we want inputs ANDed into various bits of that array (we pull up) or just floating

 - selectings of different functions
 - PWM outputs
 - CPU etc. see notes...
 
 */
 
//-------------------------------------------------------------------
//-- Ejemplo de uso de un registro de desplazamiento de 4 bits
//-- para generar una secuencia de rotacion de bits
//-------------------------------------------------------------------
//-- (C) BQ. August 2015. Written by Juan Gonzalez (obijuan)
//-- GPL license
//-------------------------------------------------------------------
module shift4(input wire clk, input wire in1, input wire in2, input wire in3, input wire in4, input wire in5, input wire in6, input wire in7, input wire in1, output reg [7:0] data);

//-- Parametros del secuenciador
parameter NP = 21;  //-- Bits del prescaler
parameter INI = 171;  //-- Valor inicial a cargar en el registro
   
reg [31:0] shifter;
   

//-- Reloj de salida del prescaler
wire clk_pres;

//-- Shift / load. Señal que indica si el registro
//-- se carga o desplaza
//-- shift = 0: carga
//-- shift = 1: desplaza
reg load_shift = 0;

//-- Entrada serie del registro
wire serin;
wire inpt;
   

//-- Instanciar el prescaler de N bits
prescaler #(.N(NP))
  pres1 (
    .clk_in(clk),
    .clk_out(clk_pres)
  );
   
wire in1_din; // for pullups!
   SB_IO #(
           .PIN_TYPE(6'b0000_01),
           .PULLUP(1'b1)
	   ) in1_config (
        .PACKAGE_PIN(in1),
        .D_IN_0(in1_din)
    );

wire in2_din; // for pullups!
   SB_IO #(
           .PIN_TYPE(6'b0000_01),
           .PULLUP(1'b1)
	   ) in2_config (
        .PACKAGE_PIN(in2),
        .D_IN_0(in2_din)
    );

wire in3_din; // for pullups!
   SB_IO #(
           .PIN_TYPE(6'b0000_01),
           .PULLUP(1'b1)
	   ) in3_config (
        .PACKAGE_PIN(in3),
        .D_IN_0(in3_din)
    );

wire in4_din; // for pullups!
   SB_IO #(
           .PIN_TYPE(6'b0000_01),
           .PULLUP(1'b1)
	   ) in4_config (
        .PACKAGE_PIN(in4),
        .D_IN_0(in4_din)
    );

wire in5_din; // for pullups!
   SB_IO #(
           .PIN_TYPE(6'b0000_01),
           .PULLUP(1'b1)
	   ) in5_config (
        .PACKAGE_PIN(in5),
        .D_IN_0(in5_din)
    );

wire in6_din; // for pullups!
   SB_IO #(
           .PIN_TYPE(6'b0000_01),
           .PULLUP(1'b1)
	   ) in6_config (
        .PACKAGE_PIN(in6),
        .D_IN_0(in6_din)
    );

wire in7_din; // for pullups!
   SB_IO #(
           .PIN_TYPE(6'b0000_01),
           .PULLUP(1'b1)
	   ) in7_config (
        .PACKAGE_PIN(in7),
        .D_IN_0(in7_din)
    );

wire in8_din; // for pullups!
   SB_IO #(
           .PIN_TYPE(6'b0000_01),
           .PULLUP(1'b1)
	   ) in8_config (
        .PACKAGE_PIN(in8),
        .D_IN_0(in8_din)
    );
   
//-- Inicializador
always @(posedge(clk_pres)) begin
    load_shift <= 1;
end

assign serin = (shifter[31] ^ shifter[29]  ^ shifter[25]  ^ shifter[24]) ^ in1_din; // but if we zero everything there is no way out???
   
//-- Registro de desplazamiento
always @(posedge(clk)) begin // was clk_pres for prescalar
  if (load_shift == 0)  //-- Load mode
    shifter <= INI;
  else
    shifter <= {shifter[30:0], serin};
   // can we do xor here?
   //  bit= ((shift_register >> 31) ^ (shift_register >> 29) ^ (shift_register >> 25) ^ (shift_register >> 24)) & 1u; // 32 is 31, 29, 25, 24
   //   shift_register=shift_register<<1; // we are shifting left << so bit 31 is out last one
   //  shift_register+=bit;         
   //  return bit;   //
   data=shifter[7:0];
//   shifter[7] <= inpt;
 
end

//-- Salida de mayor peso se re-introduce por la entrada serie
// assign serin = shifter[31];

endmodule

