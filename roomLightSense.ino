int photosensor = A0; 

int analogvalue;



void setup() {
	Serial.begin();

	pinMode(led, OUTPUT);
	digitalWrite(led, HIGH);

	Particle.variable("analogvalue", &analogvalue, INT);

}



void loop() {

	int analogvalue = analogRead(photosensor);

	Serial.printlnf("%d", analogvalue);
	
	String lux = String(analogvalue);
	Particle.publish("lux", lux, PRIVATE);
    delay(30000); 