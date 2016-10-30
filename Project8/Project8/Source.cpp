#include <iostream> 

using namespace std;

// declare enemy class

class Enemy {
public:
	Enemy(int hps);
	virtual ~Enemy();
	virtual int get_hit_points() const = 0;
	virtual int get_score() const = 0;
	virtual void set_hit_points(int new_hit_points) = 0;
	virtual	void set_score(int new_score) = 0;
	virtual void arg() = 0;
protected:
	int hit_points = 0;
	int* score = 0;
};

Enemy::Enemy(int hps) :
	hit_points(hps) {
	score = new int(0);
}

Enemy::~Enemy() {
	delete score;
}

int Enemy::get_hit_points() const {
	return hit_points;
}

int Enemy::get_score() const {
	return *score;
}

void Enemy::set_hit_points(const int new_hit_points) {
	hit_points = new_hit_points;
}

void Enemy::set_score(const int new_score) {
	*score = new_score;
}

// declare flying enemy class

class ArmedEnemy : public Enemy
{
public:
	ArmedEnemy(int hps, int ammo);
	virtual ~ArmedEnemy();
	virtual int get_hit_points() const {
		return hit_points;
	};
	virtual int get_score() const {
		return *score;
	};
	virtual void set_hit_points(int new_hit_points) {
		hit_points = new_hit_points;
	};
	virtual void set_score(const int new_score) {
		*score = new_score;
	};
	virtual void shoot() {
		if (ammo_level > 0)
		{
			cout << "bang!\n";
			--ammo_level;
		}
		else
		{
			cout << "out of ammo\n";
		}
	};
	virtual void arg() {
		hit_points--;
	};
protected:
	int ammo_level;
};

class Boss : public ArmedEnemy {
public:
	Boss(int hps,int ammo);
	virtual ~Boss();
	virtual int get_armor() {
		return armor;
	};
	virtual void set_armor(int ar) {
		armor = ar;
	};
	virtual void arg() {
		hit_points = 8;
	};
protected:
	int armor;
};


// define enemy class
Boss::Boss(int hps, int ammo) :
	ArmedEnemy(hps,ammo) {
}
Boss::~Boss() {
}

// define flying enemy class

ArmedEnemy::ArmedEnemy(int hps, int ammo) :
	Enemy(hps),
	ammo_level(ammo) {
}

ArmedEnemy::~ArmedEnemy() {
}

void some_func(Enemy& enemy) {
	enemy.arg();
}

int main(void) {
	ArmedEnemy a1(3, 3), a2(3, 3), a3(3, 3), a4(3, 3), a5(3, 3), a6(3, 3), a7(3, 3), a8(3, 3), a9(3, 3), a10(3, 3);
	Boss b(3,5);
	ArmedEnemy* fml[11] = {&a1,&a2,&a3,&a4,&a5,&a6,&a7,&a8,&a9,&a10,&b};
	//ArmedEnemy* ae = new ArmedEnemy(2, 5);
	b.set_armor(3);
	//ae->set_hit_points(3);
	//cout << "hit points = " << ae->get_hit_points() << "\n";
	cout << "hit points of Boss = " << b.get_hit_points() << endl;
	cout << "the armor of Boss = " << b.get_armor()<< endl;
	//ae->shoot();
	b.shoot();
	for (int i = 0;i < 11; i++) {
		some_func(*fml[i]);
		cout << fml[i]->get_hit_points() << endl;
	}
	
	system("pause");
	return 0;
}
