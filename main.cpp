#include "Cal.h"
#include <iostream>
using namespace std;
int booking_number = 1;

void listinsert(vector<Timetable *> arr, Interval x) {
  int i;
  for (i = 0; i < arr.size(); i++) {
    if (arr[i]->insert(x)) {
      cout << "The slot is successfully booked\nYour booking number is "
           << booking_number++;
      return;
    }
  }
  if (i == arr.size()) {
    cout << "The slot is not available\n";
  }
}
int main() {
  Timetable lab, meeting, kitchen;
  vector<Timetable *> coffee(3, new Timetable()), lean_back(6, new Timetable()),
      break_room(6, new Timetable());
  bool flag = true;

  while (flag) {
    int choice;
    cout << "\n\t\tWelcome to Booking system\n" << endl;
    cout << "\ttype 1 to book lab" << endl
         << "\ttype 2 to book meeting" << endl
         << "\ttype 3 to book lean back" << endl
         << "\ttype 4 to book coffee" << endl
         << "\ttype 5 to book kitchen" << endl
         << "\ttype 6 to book break room" << endl
         << "\ttype 0 to exit" << endl;
    cin >> choice;
    Interval temp;
    switch (choice) {
    case 1:
      temp.input();
      if (!lab.insert(temp)) {
        cout << "This slot is overlapping with previously booked slot. Pls try "
                "again";
      } else {
        cout << "The slot is successfully booked\nYour booking number is "
             << booking_number++;
      }
      break;
    case 2:
      temp.input();
      if (!meeting.insert(temp)) {
        cout << "This slot is overlapping with previously booked slot. Pls try "
                "again";
      } else {
        cout << "The slot is successfully booked\nYour booking number is "
             << booking_number++;
      }
      break;
    case 3:
      temp.input();
      listinsert(lean_back, temp);
      break;
    case 4:
      temp.input();
      listinsert(coffee, temp);
      break;
      break;
    case 5:
      temp.input();
      if (!kitchen.insert(temp)) {
        cout << "This slot is overlapping with previously booked slot. Pls try "
                "again";
      } else {
        cout << "The slot is successfully booked\nYour booking number is "
             << booking_number++;
      }
      break;
    case 6:
      temp.input();
      listinsert(break_room, temp);
      break;
      break;
    case 0:
      flag = false;
      break;
    }
    if (!flag)
      break;
  }

  if (!lab.empty())
    cout << "Lab is booked at\n";
  lab.show();
  if (!meeting.empty())
    cout << "Meeting is booked at\n";
  meeting.show();
  for (int i = 0; i < 6; i++) {
    if (!lean_back[i]->empty())
      cout << "Lean back " << i + 1 << " is booked at\n";
    lean_back[i]->show();
  }
  for (int i = 0; i < 3; i++) {
    if (!coffee[i]->empty())
      cout << "coffee " << i + 1 << " is booked at\n";
    coffee[i]->show();
  }
  if (!kitchen.empty())
    cout << "kitchen is booked at\n";
  kitchen.show();
  for (int i = 0; i < 6; i++) {
    if (!break_room[i]->empty())
      cout << "break slot " << i + 1 << " is booked at\n";
    break_room[i]->show();
  }
  return 0;
}