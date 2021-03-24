/*****************************************************
 This is my take on the CS Lab for Week 4 (#3) Task 2.
 You can use your mouse to draw lines with two clicks on a blank 800x600 canvas.
 Press keys 2-9 to change the colour of the pen. 
 Key 1 is the default colour– black and 0 is the eraser- white.
 Press the QWERTY keys for thicker pen weights.
 Press C to clear the whole canvas.
 *****************************************************/

// global variable for mouse click:
int click;

void setup() {
  size(800, 600);
  background(255, 255, 255);
  // so you don't start drawing immediately
  click = 255;
}

void draw() {
  // if mouse is clicked, draw until the second mouse click
  if (click == 0) { 
    line(mouseX, mouseY, pmouseX, pmouseY);
  }

  // other features
  if (keyPressed) {
    // To change the pen colour
    if (key == '1') // black
      stroke(0, 0, 0);
    else if (key == '2') // red
      stroke(237, 56, 51);
    else if (key == '3')  // orange
      stroke(231, 97, 53);
    else if (key == '4') // yellow
      stroke(253, 243, 80);
    else if (key == '5')  // green
      stroke(117, 236, 62);
    else if (key == '6')  // cyan
      stroke(106, 243, 243);
    else if (key == '7') // blue
      stroke(7, 104, 238);
    else if (key == '8') // purple
      stroke(127, 72, 239);
    else if (key == '9') // pink
      stroke(227, 85, 241);
    else if (key == '0') // white (essentially an eraser)
      stroke(255, 255, 255);

    // To change the pen tip size
    else if (key == 'q' || key == 'Q')
      strokeWeight(2.0);
    else if (key == 'w' || key == 'W')
      strokeWeight(4.0);
    else if (key == 'e' || key == 'E')
      strokeWeight(8.0);
    else if (key == 'r' || key == 'R')
      strokeWeight(10.0);
    else if (key == 't' || key == 'T')
      strokeWeight(14.0);
    else if (key == 'y' || key == 'Y')
      strokeWeight(18.0);
      
    // clear canvas
    else if (key == 'c' || key == 'C')
      background(255, 255, 255);

    // default condition is black pen and 1px thickness
    else {
      stroke(0, 0, 0);
      strokeWeight(1.0);
    }
  }
}

void mousePressed() {
  if (click == 0) {
    click = 255;
  } else {
    click = 0;
  }
}
