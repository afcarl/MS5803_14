This library is a modification of an existing Arduino [library](https://github.com/millerlp/MS5803_14) for the 
Measurement Specialties MS5803-14BA pressure sensor modules. The modification allows it to be used
with the Teensy 3.1, 3.2, 3.5, and 3.6 microcontroller boards.  Specifically, you can:

<ul>
<li> Specify which I^2C address you wish to use (default 0x76, or 0x77)
<p>  Specify which I^2C Wire interface you wish to use (<tt>Wire</tt>, <tt>Wire1</tt>, or <tt>Wire2</tt>),
useful on the Teensy 3.5 and 3.6.
</ul>
