#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Joystick
const int joyX = 34;
const int joyMid = 2048; // Center value for analog joystick

// Paddle
int paddleX = 64;
const int paddleWidth = 30;

// Ball
float ballX = 64, ballY = 10;
float ballDX = 1.5, ballDY = 1.5;

void setup() {
  Serial.begin(115200);
  pinMode(joyX, INPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    while (true);
  }

  display.clearDisplay();
  display.display();
}

void loop() {
  // Read and process joystick
  int joyVal = analogRead(joyX);
  int delta = joyVal - joyMid;

  // Apply deadzone and proportional movement
  if (abs(delta) > 100) {
    paddleX += delta / 300;  // Sensitivity control
  }

  // Constrain paddle to screen
  paddleX = constrain(paddleX, 0, SCREEN_WIDTH - paddleWidth);

  // Update ball position
  ballX += ballDX;
  ballY += ballDY;

  // Bounce off left and right walls
  if (ballX <= 0 || ballX >= SCREEN_WIDTH) {
    ballDX *= -1;
  }

  // Bounce off top
  if (ballY <= 0) {
    ballDY *= -1;
  }

  // Bounce off paddle
  if (ballY >= SCREEN_HEIGHT - 5 && ballX >= paddleX && ballX <= paddleX + paddleWidth) {
    ballDY *= -1;

    // Speed up the ball a bit
    ballDX *= 1.05;
    ballDY *= 1.05;

    // Clamp max speed
    ballDX = constrain(ballDX, -5, 5);
    ballDY = constrain(ballDY, -5, 5);
  }

  // Game Over
  if (ballY > SCREEN_HEIGHT) {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(20, 25);
    display.println("Game Over");
    display.display();
    delay(2000);

    // Reset game
    paddleX = 64;
    ballX = 64;
    ballY = 10;
    ballDX = 1.5;
    ballDY = 1.5;
  }

  // Draw everything
  display.clearDisplay();
  display.fillRect(paddleX, SCREEN_HEIGHT - 3, paddleWidth, 3, WHITE); // Paddle
  display.fillCircle(ballX, ballY, 2, WHITE); // Ball
  display.display();

  delay(10); // Small delay for smooth animation
}
