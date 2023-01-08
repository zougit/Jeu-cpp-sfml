#include "headers/player.hpp"
using namespace std;
using namespace sf;

Player::Player() : _name("player"), _currentHp(50), _hpMax(50), _currentExp(0), _expMax(50), _lvl(1), _x(0), _y(0)
{
}

Player::Player(string name) : _name(name), _currentHp(50), _hpMax(50), _currentExp(0), _expMax(50), _lvl(1), _x(0), _y(0)
{
}

Player::Player(string name, int currentHp, int hpMax, int currentExp, int expMax, int lvl, int x, int y, Weapon weapon, Armor armor, Inventory inventory) : _name(name), _currentHp(currentHp), _hpMax(hpMax), _currentExp(currentExp), _expMax(expMax), _lvl(lvl), _x(x), _y(y), _weapon(weapon), _armor(armor), _inventory(inventory)
{
}

int Player::getCurrentHp() const
{
    return _currentHp;
}

int Player::getHpMax() const
{
    return _hpMax;
}

int Player::getCurrentExp() const
{
    return _currentExp;
}

int Player::getExpMax() const
{
    return _expMax;
}

int Player::getLvl() const
{
    return _lvl;
}

int Player::getX() const
{
    return _x;
}

int Player::getY() const
{
    return _y;
}

Inventory Player::getInventory() const
{
    return _inventory;
}

void Player::setXY(int x, int y)
{
    _x = x;
    _y = y;
}

void Player::move(Keyboard::Key move)
{
    switch (move)
    {
    case Keyboard::Z:
        _x -= 1;
        break;
    case Keyboard::Q:
        _y -= 1;
        break;
    case Keyboard::S:
        _x += 1;
        break;
    case Keyboard::D:
        _y += 1;
        break;
    default:
        cout << "nope" << endl;
        break;
    }
    // cout << "x: " << _x << "y: " << _y << endl;
}

void Player::displayPlayer()
{
    cout << "PLAYER : " << endl
         << "name: " << _name << endl
         << "hp: " << _currentHp << "/" << _hpMax << endl
         << "exp: " << _currentExp << "/" << _expMax << endl
         << "lvl: " << _lvl << endl;
    cout << "ARME :" << endl;
    _weapon.displayWeapon();
    cout << "ARMURE :" << endl;
    _armor.displayArmor();
    cout << endl;
}

void Player::changeWeapon(string name, int damage)
{
    _weapon.changeWeapon(name, damage);
    cout << "arme changée! \n"
         << "nouvelle arme : " << endl;
    _weapon.displayWeapon();
    cout << endl;
}

void Player::changeArmor(string name, int resistance)
{
    _armor.changeArmor(name, resistance);
    cout << "armure changée! \n"
         << "nouvelle armure : " << endl;
    _armor.displayArmor();
    cout << endl;
}

void Player::leveling()
{
    while (_currentExp >= _expMax)
    {
        _lvl++;
        _hpMax += 30;
        _currentHp = _hpMax;
        _expMax += 50 * (1.00 + (_lvl / 50));
        cout << "lvl up! \n"
             << "lvl : " << _lvl << endl;
    }
}

void Player::battle(Monster m, RenderWindow &window)
{
window.clear();

        Texture bg;
        if (!bg.loadFromFile("bg-battle.png"))
            cout << "Loading failure" << endl;

        Sprite bgSprite(bg);
        bgSprite.setTextureRect(IntRect(259, 147, 259, 147));
        bgSprite.scale(4.7, 6);
        Vector2f pos = bgSprite.getScale();

        Texture textBox;
        if (!textBox.loadFromFile("textBox.png"))
            cout << "Loading failure" << endl;

        Sprite textBoxSprite(textBox);
        textBoxSprite.setTextureRect(IntRect(0, 0, 252, 44));
        Sprite textBox1 = textBoxSprite;
        textBox1.setPosition(0, (147 * pos.y) - 10);
        textBox1.scale(4.8, 2);
        Vector2f posText = textBox1.getPosition();
        Vector2f textScale = textBox1.getScale();

        sf::Font font;
        if (!font.loadFromFile("arial_narrow_7.ttf"))
        {
            cout << "error";
        }

        Text text("monster appeared", font, 24);
        text.setFillColor(Color::Black);
        text.setPosition(50, posText.y + 30);

        window.draw(bgSprite);
        window.draw(textBox1);
        window.draw(text);
        window.display();

    srand(time(0));
    InitList l;
    bool turn = true, escape = false;
    int chance = 0;
    m.displayMonster();
    Event event;
    while (!escape)
    {
        
        window.pollEvent(event);
        if (event.type == Event::KeyPressed)
        {
            if (turn && m.getHp() > 0 && _currentHp > 0)
            {
                // cout << "\nPlayer turn" << endl;
                // cout << "Actions : " << endl
                //     << "1) attaquer" << endl
                //     << "2) se soigner" << endl
                //     << "3) fuir" << endl;
                // cout << "choisissez une action : " << endl;
                // cin >> choix;
                textBoxSprite.setTextureRect(IntRect(0, 270, 252, 44));
                Sprite textBox2 = textBoxSprite;
                textBox2.setPosition(198 * textScale.x, (147 * pos.y) - 10);
                textBox2.scale(1, 2);

                Text text("choose an action", font, 24);
                text.setFillColor(Color::Black);
                text.setPosition(50, posText.y + 30);

                Text text1("1) attaquer", font, 24);
                text1.setFillColor(Color::Black);
                text1.setPosition(198 * textScale.x, posText.y + 10);

                Text text2("2) se soigner", font, 24);
                text2.setFillColor(Color::Black);
                text2.setPosition(198 * textScale.x, posText.y + 30);

                Text text3("3) fuir", font, 24);
                text3.setFillColor(Color::Black);
                text3.setPosition(198 * textScale.x, posText.y + 50);

                window.draw(textBox2);
                window.draw(text);
                window.draw(text1);
                window.draw(text2);
                window.draw(text3);
                window.display();

                Keyboard::Key choice = event.key.code;
                switch (choice)
                {
                case Keyboard::Num1:
                    m.recieveDamage(_weapon.getDamage());
                    // cout << "pv Monstre : " << m.getHp() << endl;
                    break;
                case Keyboard::Num2:
                    if (_currentHp + l.getHeals()[0].getHealing() > _hpMax)
                    {
                        _currentHp = _hpMax;
                    }
                    else
                    {
                        _currentHp += l.getHeals()[0].getHealing();
                    }
                    // cout << "player soigné : " << _currentHp << '/' << _hpMax << endl;
                    break;
                case Keyboard::Num3:
                    chance = 1 + (rand() % 100);
                    if (chance < 30)
                    {
                        escape = true;
                        // cout << "fuite réussi" << endl;
                        return;
                    }
                    else
                    {
                        // cout << "fuite foirée" << endl;
                    }
                    break;
                default:
                    // cout << "ceci n'est pas une action"<< endl;
                    continue;
                }
                turn = false;
            }

            if (!turn && m.getHp() > 0 && _currentHp > 0)
            {
                // cout << "\nMonster turn" << endl;
                _currentHp -= (m.getDamage() - _armor.getResistance());
                // cout << "pv Player : " << _currentHp << "/" << _hpMax << endl;
                window.draw(textBox1);
                window.draw(text);
                window.display();
                turn = true;
            }

            if (m.getHp() <= 0)
            {
                // cout << _name << " win!"<<endl;
                _currentExp += m.getExp();
                // cout << "exp: " << _currentExp << "/" << _expMax << endl << endl;
                leveling();
                m.monsterDie();
                return;
            }
            if (_currentHp <= 0)
            {
                // cout <<"Monster win!" << endl << endl;
                return;
            }
        }
    }
    window.display();
}
