#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Structures section
struct Race {
  int numberOfLaps;
  int currentLap;
  char firstPlaceDriverName[20];
  char firstPlaceRaceCarColor[20];
};
struct RaceCar {
  char driverName[20];
  char raceCarColor[20];
  int totalLapTime;
};
// Print functions section
void printIntro() {
  printf("Welcome to our main event digital race fans!\n");
  printf("I hope everybody has their snacks because we are about to begin!\n");
}
void printCountDown() {
  printf("Racers Ready! In...\n");
  printf("5\n4\n3\n2\n1\nRace!\n\n");
}
void printFirstPlaceAfterLap(struct Race race) {
  printf("After lap number %i\n", race.currentLap);
  printf("First Place is %s in the %s race car!\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}
void printCongratulation(struct Race race) {
  printf("\nLet's all congratulate %s in the %s car for an amazing performance.", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
  printf("It truly was a great race and everybody have a goodnight!");
}
// Logic functions section
int calculateTimeToCompleteLap() {
  srand(time(0));
  int speed = (rand() % 3) + 1;
  int acceleration = (rand() % 3) + 1;
  int nerves = (rand() % 3) + 1;
  int sum = speed + acceleration + nerves;
  return sum;
}
void updateRaceCar(struct RaceCar* raceCar) {
  int lapTime = calculateTimeToCompleteLap();
  (*raceCar).totalLapTime += lapTime;
}
void updateFirstPlace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
  if (raceCar1->totalLapTime <= raceCar2->totalLapTime) {
    strcpy(race->firstPlaceDriverName, raceCar1->driverName);
    strcpy(race->firstPlaceRaceCarColor, raceCar1->raceCarColor);
  } else {
    strcpy(race->firstPlaceDriverName, raceCar2->driverName);
    strcpy(race->firstPlaceRaceCarColor, raceCar2->raceCarColor);
  }
  printf("%s total lap time: %i\n", raceCar1->driverName, raceCar1->totalLapTime);
  printf("%s total lap time: %i\n", raceCar2->driverName, raceCar2->totalLapTime);
}
void startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
  struct Race race = {5, 1, "", ""};
  for (int i = 0; i < race.numberOfLaps; i++) {
    updateRaceCar(raceCar1);
    updateRaceCar(raceCar2);
    updateFirstPlace(&race, raceCar1, raceCar2);
    printFirstPlaceAfterLap(race);
    race.currentLap += 1;
  }
  printCongratulation(race);
}
int main() {
	srand(time(0));
  printIntro();
  printCountDown();
  struct RaceCar car1 = {"Person 1", "Orange", 0};
  struct RaceCar car2 = {"Person 2", "Green", 0};
  startRace(&car1, &car2);
};