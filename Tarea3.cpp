class Led{
public:
  Led(int _pin){
  	pin=_pin;
    pinMode(pin, OUTPUT);
  }

  bool cambiarEstado(bool estado){
    if(estado){
    	digitalWrite(pin, HIGH);
      	delay(70);
    }else{
    	digitalWrite(pin,LOW);
      	delay(50);
    }
  }
private:
  int pin;
};

class Boton{
	public:
  	  Boton(int _pin){
  		pin=_pin;
  	  }
  

  bool Precionarboton(){
    if(digitalRead(pin)){     
      return 1;
    }else{
      return 0;
    }
  
  
 
  }
  private:
  	int pin;
};

Led luzVerde(13);
Led luzRoja(7);
Boton botonIncremento(4);
Boton botonDecremento(2);
int cont =0; 

void setup()
{
Serial.begin(9600); 

}


void loop()
{
	
   if(botonIncremento.Precionarboton()){
  		luzVerde.cambiarEstado(1);
     		cont ++;
    		 Serial.println(cont);
     			delay(100);
  	}else if(botonDecremento.Precionarboton()){
    		luzRoja.cambiarEstado(1);
    		 cont --;
    		  Serial.println(cont);
     			delay(100);
  		}else{ 			
     		  luzRoja.cambiarEstado(0);
    			luzVerde.cambiarEstado(0);
     				Serial.println(cont);
    				
  }
 

}
