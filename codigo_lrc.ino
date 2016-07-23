/* LAGUNA ROBOT CHALLENGE  FALTA LIBRERIA PARA USAR PINES 8 y 9 DE ARDUINO COMO TX RX
 *  9 de puente en 7 de arduino 
 *  1 de puente en 11 de arduino 
 * deberian de ir a 5v 
 *  se pusieron en PWM para troubleshooting
 ARDUINO   L293D(Puente H)        
 5          10
 4          15
 13          7
 12         2
 5V         1*, 9*, 16
 GND        4, 5, 12, 13
 
 El motor izquierdo se conecta a los pines 3 y 6 del Puente H
 El motor derecho se con´´´/ecta a los pines 11 y 14 del Puente H
 
 La alimentacion de motores se conecta a tierra y
 al positivo al pin 8 del puente H. (Se alimentara diferente al arduino)
 
 Conexion del Modulo Bluetooth HC-06 y el Arduino
 ARDUINO    Bluetooth HC-06 
 8 (RX)       TX
 9 (TX)       RX
 5V           VCC
 GND          GND
NOTA IMPORTANTE: Las conexiones de TX y RX al modulo Bluetooth deben estar desconectadas
 en el momento que se realiza la carga del codigo al Arduino.
 
 */
 
int izquierdoA = 5; 
int izquierdoB = 4; 
int derechoA= 2; 
int derechoB = 3; 
int vel = 175;      // Velocidad de los motores (0-255)AQUI CAMBIAS LA VELOCIDAD SIENDO 255 EL 100%
int estado = 'S';         // inicia detenido


void setup()  { 
  Serial.begin(9600);    // inicia el puerto serial para comunicacion con el Bluetooth
  pinMode(izquierdoA, OUTPUT);
  pinMode(izquierdoB, OUTPUT);
  pinMode(derechoA, OUTPUT);
  pinMode(derechoB, OUTPUT);

  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  digitalWrite(6, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(9 , HIGH);   // turn the LED on (HIGH is the voltage level)
 

} 

void loop()  { 

  if(Serial.available()>0){        // lee el bluetooth y almacena en estado
    estado = Serial.read();
   }  
   
  if(estado=='F'){           // Boton desplazar al Frente
    analogWrite(izquierdoA, vel);     
    analogWrite(izquierdoB, 0); 
    analogWrite(derechoA, vel);  
    analogWrite(derechoB, 0);     
    Serial.println ("Adelante");
  }
  if(estado=='R'){          // Boton IZQ 
    analogWrite(izquierdoA, 0);     
    analogWrite(izquierdoB, 0); 
    analogWrite(derechoA, vel);  
    analogWrite(derechoB, 0);     
    Serial.println ("Izquierda");    
  }
  if(estado=='L'){         // Boton Parar
    analogWrite(izquierdoA, 0);     
    analogWrite(izquierdoB, 0); 
    analogWrite(derechoA, 0);  
    analogWrite(derechoB, 0);     
    Serial.println ("Freno");
  }
  if(estado=='R'){          // Boton DER
    analogWrite(izquierdoA, vel);     
    analogWrite(izquierdoB, 0); 
    analogWrite(derechoA, 0);  
    analogWrite(derechoB, 0);     
    Serial.println ("Derecha");
  } 

  if(estado=='B'){          // Boton Reversa
    analogWrite(izquierdoA, 0);     
    analogWrite(izquierdoB, vel); 
    analogWrite(derechoA, 0);  
    analogWrite(derechoB, vel);     
    Serial.println ("Reversa"); 
  } 
  }
