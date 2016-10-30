#include <iostream>
#include <string>

using namespace std;

class Enemy {
public:
	Enemy();
	~Enemy();
	int get_hit_points() const;
	int get_score() const;
	void set_hit_points(int new_hit_points);
	void set_score(int new_score);
private:
	int hit_points;
	int* score;
};

class Player {
public:
	Player();
	~Player();
	int get_hit_points() const;
	int get_score() const;
	string get_name();
	void set_hit_points(int new_hit_points);
	void set_score(int new_score);
	void set_name(string name);
private:
	string *name;
	int hit_points;
	int* score;
};

Enemy::Enemy() {
	hit_points = 10;
	score = new int(0);
}

Player::Player() {
	int *hps = &hit_points;
	score = 0;
	name = new string("");
}

Enemy::~Enemy() {
	delete score;
}
Player::~Player() {
	delete score;
}
int Enemy::get_hit_points() const {
	return hit_points;
}
int Player::get_hit_points() const {
	return hit_points;
}
int Enemy::get_score() const {
	return *score;
}
int Player::get_score() const {
	return *score;
}
void Enemy::set_hit_points(const int new_hit_points) {
	hit_points = new_hit_points;
}
void Player::set_hit_points(const int new_hit_points) {
	hit_points = new_hit_points;
}
void Enemy::set_score(const int new_score) {
	*score = new_score;
}
void Player::set_score(const int new_score) {
	*score = new_score;
}
void Player::set_name(string name) {
	*(this->name) = name;
}
string Player::get_name() {
	return *name;
}
int main(void) {

	/*Player* a = new Player();
	cout << "Enter your name : " <<a.get_name()<< endl;*/

	Player* b1 = new Player();
	b1 ->set_name("Yuzhou Jin");
	cout << "Welcome Warrior : " << b1->get_name() << endl;

	Enemy e1;
	cout << "hit points = " << e1.get_hit_points() << endl;

	Enemy* e2 = new Enemy();
	e2->set_hit_points(3);
	cout << "hit points = " << e2->get_hit_points() << endl;

	e2->set_score(2);
	cout << "score = " << e2->get_score() << endl;

	//delete e2;
	//e2 = NULL;
	//delete b1;
	//b1 = NULL;

	cin.ignore();
	cin.get();

	return 0;
}
