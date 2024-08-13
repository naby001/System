#include <bits/stdc++.h>

class Time {
public:
  int *day;
  int *time;

  void init() {
    day = new int[3]{0};
    time = new int[3]{0};
  }

  void input() {
    std::cout << "Enter date(dd/mm/yyyy)\t";
    std::cin >> day[0] >> day[1] >> day[2];
    std::cout << "Enter time(hh:mm:ss)\t";
    std::cin >> time[0] >> time[1] >> time[2];
  }
  void show() {
    std::cout << day[0] << "/" << day[1] << "/" << day[2] << "  " << time[0]
              << ":" << time[1] << ":" << time[2];
  }
  Time() { init(); }
  void operator = (const Time& a){
    day[0] = a.day[0];
    day[1] = a.day[1];
    day[2] = a.day[2];
    time[0] = a.time[0];
    time[1] = a.time[1];
    time[2] = a.time[2];
  }
};

class Interval {
public:
  Time start;
  Time end;
  bool is_same_day;
  Interval() {
    start = Time();
    end = Time();
  }
  Interval(Time a, Time b) {
    start = Time();
    end = Time();
    is_same_day = false;
  }
  void input() {
    std::cout << "Enter Start time\n";
    start.input();
    std::cout << "Is end on the same day? (y/n)\t";
    char c;
    std::cin >> c;
    if (c=='Y'||c=='y') {
      end = start;
      std::cout << "Enter End time\t";
      std::cin >> end.time[0] >> end.time[1] >> end.time[2];
    } else {
      std::cout << "Enter End time\t";
      end.input();
    }
  }
  void show() {
    start.show();
    std::cout << " - ";
    end.show();
  }
  char compare(Interval a) {
    for (int i = 2; i >= 0; i--) {
      if (end.day[i] < a.start.day[i]) {
        return 'a';
      }
      if (start.day[i] > a.end.day[i]) {
        return 'd';
      }
    }
    long long x1s = start.time[0] * 3600 + start.time[1] * 60 + start.time[2];
    long long x1e = end.time[0] * 3600 + end.time[1] * 60 + end.time[2];
    long long x2s =
        a.start.time[0] * 3600 + a.start.time[1] * 60 + a.start.time[2];
    long long x2e = a.end.time[0] * 3600 + a.end.time[1] * 60 + a.end.time[2];
    if (x1e <= x2s)
      return 'a';
    if (x1s >= x2e)
      return 'd';
    return 's';
  }
};

class Timetable {
public:
  class Node {
  public:
    Interval interval;
    Node *prev, *next;
    Node(Interval a) {
      this->interval = a;
      prev = NULL, next = NULL;
    }
  };
  Node *head;
  void init() { head = NULL; }
  Timetable() { init(); }
  void add(Node *a, Node *b) {
    a->next = b;
    b->prev = a;
  }
  bool insert(Interval a) {
    if (head == NULL) {
      head = new Node(a);
      return true;
    }
    if (a.compare(head->interval) == 'a') {
      Node *t = new Node(a);
      add(t, head);
      head = t;
      return true;
    }
    Node *t = new Node(a);
    Node *cur = head;
    while (cur->next != NULL) {
      if (a.compare(cur->next->interval) == 'd') {
        cur = cur->next;
      } else if (a.compare(cur->next->interval) == 'a') {
        add(cur->prev, t);
        add(t, cur);
        return true;
      } else if (a.compare(cur->next->interval) == 's') {
        return false;
      }
    }
    if (a.compare(cur->interval) == 'a') {
      add(cur->prev, t);
      add(t, cur);
      return true;
    }
    if (a.compare(cur->next->interval) == 's') {
      return false;
    }
    add(cur, t);
    t->next = NULL;
    return true;
  }
  void show() {
    if(head==NULL)return;
    int i = 1;
    Node *cur = head;
    while (cur != NULL) {
      std::cout << i++ << ". ";
      cur->interval.show();
      std::cout<<std::endl;
      cur=cur->next;
    }
    std::cout << std::endl;
  }
  bool empty(){
    return (head==NULL);
  }
};