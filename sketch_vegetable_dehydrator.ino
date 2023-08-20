#include &lt;SimpleDHT.h&gt;
// for DHT11,
// VCC: 5V or 3V
// GND: GND
// DATA: 2
float pinDHT11 = 14; //back sensor working
float pin2DHT11 = 5;// front sensor working
float pin3DHT11 = 4; // external sensor
SimpleDHT11 dht11(pinDHT11);
SimpleDHT11 dht21(pin2DHT11);
SimpleDHT11 dht31(pin3DHT11);
void setup() {
// start working...
Serial.begin(9600);
Serial.println(&quot;Temperature and humidity data&quot;);
}
void loop() {
// pinDHT11 code - back------------------------------------------------------------
delay(250);
// read without samples.
byte temperature_1 = 0;
byte humidity_1 = 0;
int err = SimpleDHTErrSuccess;
if ((err = dht11.read(&amp;temperature_1, &amp;humidity_1, NULL)) != SimpleDHTErrSuccess) {
Serial.print(&quot;Read DHT11 failed, err=&quot;); Serial.print(SimpleDHTErrCode(err));
Serial.print(&quot;,&quot;); Serial.println(SimpleDHTErrDuration(err)); delay(1000);
return;
}
Serial.print((float)temperature_1, 4); Serial.print(&quot; *C, &quot;);
Serial.print((float)humidity_1, 4); Serial.print(&quot; H, &quot;);
//pin2DHT11 - front--------------------------------------------------------------------------------
byte temperature_2 = 0;

byte humidity_2 = 0;
int err2 = SimpleDHTErrSuccess;
if ((err2= dht21.read(&amp;temperature_2, &amp;humidity_2, NULL)) != SimpleDHTErrSuccess) {
Serial.print(&quot;Read DHT11 failed, err=&quot;); Serial.print(SimpleDHTErrCode(err2));
Serial.print(&quot;,&quot;); Serial.println(SimpleDHTErrDuration(err2)); delay(1000);
return;
}
Serial.print((float)temperature_2, 4); Serial.print(&quot; *C, &quot;);
Serial.print((float)humidity_2, 4); Serial.print(&quot; H, &quot;);
//pin3DHT11 - external------------------------------------------------------------------------------------
byte temperature_3 = 0;
byte humidity_3 = 0;
int err3 = SimpleDHTErrSuccess;
if ((err3 = dht31.read(&amp;temperature_3, &amp;humidity_3, NULL)) != SimpleDHTErrSuccess) {
Serial.print(&quot;Read DHT11 failed, err=&quot;); Serial.print(SimpleDHTErrCode(err3));
Serial.print(&quot;,&quot;); Serial.println(SimpleDHTErrDuration(err3)); delay(1000);
return;
}
Serial.print((float)temperature_3, 4); Serial.print(&quot; *C, &quot;);
Serial.print((float)humidity_3, 4); Serial.println(&quot; H, &quot;);
// DHT11 sampling rate is 1HZ.
delay(120000);
}