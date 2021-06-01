# from other code

var down;
		in = in.round(0.5 ** bits);
		down = Latch.ar(
			in,
			Impulse.ar(SampleRate.ir / downsamp.max(2))
		); 

		// below 1/2 downsamp, do xfade:
blend(in, down, (downsamp - 1).clip(0, 1));

# previous sc code

(
{
var in;
var signal;
signal = AudioIn.ar(1);
d=DelayL.ar(
HPF.ar(signal, 4000.0, 40),2,2
);
//Out.ar(0,in);

(d).dup

}.play(s)

)

# try to merge

(
{
	var in;
	var bits=16; # bits=16, downsamp=2|
	var down;
	var downsamp=2;
	var signal;
	signal = AudioIn.ar(1);
	in = signal.round(0.5 ** bits);
	down = Latch.ar(
		in,
		Impulse.ar(SampleRate.ir / downsamp.max(2))
	); 
	signal=blend(in, down, (downsamp - 1).clip(0, 1));
	d=DelayL.ar(
		HPF.ar(signal, 4000.0, 40),2,2
	);
	//Out.ar(0,in);

	(d).dup
	
}.play(s)

)