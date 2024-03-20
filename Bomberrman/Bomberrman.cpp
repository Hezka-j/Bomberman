#include<iostream>
#include"Map.h"
#include<SFML/Graphics.hpp>
#include"View.h"
using namespace std;
using namespace sf;
class Player {
    Texture texture;
    string file;
    Sprite sprite;
    Image image;
    float x;
    float y;
    float speed = 0;
    float dx;
    float dy;
    float height;// высота одного перса
    float width;// ширина одного перса
    int direction = 0;// направление
public:

    Player(string file, float x, float y, float width, float height) {
        speed = 0;
        direction = 0;
        dx = 0;
        dy = 0;
        SetWidth(width);
        SetHeight(height);
        SetFile(file);
        SetImage(file);
        SetTexture(image);
        SetSprite(texture);
        SetX(x);
        SetY(y);
        sprite.setTextureRect(IntRect(0, 0, width, height));
        /*this->file = file;
        this->width = width;
        this->height = height;
        image.loadFromFile("D:\\Проекты\\Bomberrman\\" + file);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        this->x = x;
        this->y = y;
        sprite.setTextureRect(IntRect(0, 0, width, height));*/
    }

    void SetDirection(int direction)
    {
        this->direction = direction;
    }

    int GetDirection()
    {
        return direction;
    }

    void SetSpeed(float speed)
    {
        this->speed = speed;
    }

    float GetSpeed()
    {
        return speed;
    }

    void SetSprite(Texture& texture) {
        sprite.setTexture(texture);
    }

    Sprite& GetSprite() {
        return sprite;
    }

    void SetHeight(float height) {
        this->height = height;
    }

    float GetHeight() {
        return height;
    }

    void SetWidth(float width) {
        this->width = width;
    }

    float GetWidth() {
        return width;
    }

    void SetX(float x) {
        this->x = x;
    }

    float GetX() {
        return x;
    }

    void SetY(float y) {
        this->y = y;
    }

    float GetY() {
        return y;
    }

    void SetDx(float dx) {
        this->dx = dx;
    }

    float GetDx() {
        return dx;
    }

    void SetDy(float dy) {
        this->dy = dy;
    }

    float GetDy() {
        return dy;
    }

    void SetTexture(Image& image){
        this->texture.loadFromImage(image);
    }

    Texture& GetTexture() {
        return this->texture;
    }

    void SetImage(string file) {
        image.loadFromFile("D:\\Проекты\\Bomberrman\\" + file);
    }

    Image& GetImage() {
        return image;
    }

    void SetFile(string file) {
        this->file = file;
    }

    string GetFile() {
        return file;
    }

    void Move(float time) {
        float current_frame = 0;
        switch (direction)
        {
            case 0:
            {
                dx = speed;
                dy = 0;
                break;
            }
            case 1:
            {
                dx = -speed;
                dy = 0;
                break;
            }
            case 2:
            {
                dx = 0;
                dy = speed;
                break;
            }
            case 3:
            {
                dy = -speed;
                dx = 0;
                break;
            }
        }
        x += dx * time;
        y += dy * time;
        speed = 0;
        sprite.setPosition(x, y);
    }

    void Animation(Player& player, float& current_frame, float& time) {
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            player.SetDirection(0);
            player.SetSpeed(0.1);
            current_frame += 0.005 * time;
            if (current_frame > 4)
                current_frame -= 4;
            //sprite.move(0.1 * time, 0);
            player.GetSprite().setTextureRect(IntRect(64 * int(current_frame), 128, 64, 64));
            GetPlayerCordinate(player.GetX(), player.GetY());
        }
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            player.SetDirection(1);
            player.SetSpeed(0.1);
            current_frame += 0.005 * time;
            if (current_frame > 4)
                current_frame -= 4;
            //sprite.move(-0.1 * time, 0);
            player.GetSprite().setTextureRect(IntRect(64 * int(current_frame), 64, 64, 64));
            GetPlayerCordinate(player.GetX(), player.GetY());
        }
        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            player.SetDirection(3);
            player.SetSpeed(0.1);
            current_frame += 0.005 * time;
            if (current_frame > 4)
                current_frame -= 4;
            //sprite.move(0, -0.1 * time);
            player.GetSprite().setTextureRect(IntRect(64 * int(current_frame), 192, 64, 64));
            GetPlayerCordinate(player.GetX(), player.GetY());
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            player.SetDirection(2);
            player.SetSpeed(0.1);
            current_frame += 0.005 * time;
            //cout << current_frame << "\n";
            if (current_frame > 4)
                current_frame -= 4;
            //sprite.move(0, 0.1 * time);
            player.GetSprite().setTextureRect(IntRect(64 * int(current_frame), 0, 64, 64));
            GetPlayerCordinate(player.GetX(), player.GetY());
        }
    }

};

int main()
{    
    srand(time(0));
    Clock clock;
    RenderWindow window(VideoMode(800, 500), "Works!"/*, Style::Fullscreen*/);
    view.reset(FloatRect(0,0, 800, 500));
    Player player("hero.png", 250, 0, 64, 64);

    Image map_image;
    map_image.loadFromFile("D:\\Проекты\\Bomberrman\\field2.0.png");
    Texture texture_map;
    texture_map.loadFromImage(map_image);
    Sprite map_sprite;
    map_sprite.setTexture(texture_map);

    float current_frame = 0;
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == event.Closed)
                window.close();
        }
        player.Animation(player, current_frame, time);
        player.Move(time);
        ChangeView();
        window.setView(view);
        window.clear(Color(95, 95, 95));

        for (int i = 0; i < height_map; i++)
        {

            for (int j = 0; j < width_map; j++)
            {
                if (main_map[i][j] == '0')
                    map_sprite.setTextureRect(IntRect(64, 0, 32, 32));
                else if (main_map[i][j] == ' ')
                    map_sprite.setTextureRect(IntRect(0, 0, 32, 32));
                map_sprite.setPosition(j * 32, i * 32);
                window.draw(map_sprite);
            }
        }

        window.draw(player.GetSprite());
        window.display();
    }

    return 0;
}




//Texture texture;
//texture.loadFromFile("D:\\Проекты\\ConsoleApplication1\\field.jpg");
//Sprite sprite(texture);
//Texture texture_wall;
//texture_wall.loadFromFile("D:\\Проекты\\ConsoleApplication1\\walls.jpg");
//Sprite sprite_wall(texture_wall);
//Image hero;
//hero.loadFromFile("D:\\Проекты\\ConsoleApplication1\\hero.png");   
//Texture hero_texture;
//hero_texture.loadFromImage(hero);
//Sprite hero_sprite(hero_texture);
//hero_sprite.setTextureRect(IntRect(0, 64, 64, 64));
//Clock clock;
//// Главный цикл приложения: выполняется, пока открыто окно
//float current_frame = 0;// текущий кадр
//while (window.isOpen())
//{
//    float time = clock.getElapsedTime().asMicroseconds();
//    clock.restart();
//    time = time / 800;
//    //cout << time << "\n";
//    // Обрабатываем очередь событий в цикле
//    Event event;
//    while (window.pollEvent(event))
//    {
//        // Пользователь нажал на «крестик» и хочет закрыть окно?
//        if (event.type == Event::Closed)
//            window.close(); // тогда закрываем его
//    }
//    if (Keyboard::isKeyPressed(Keyboard::Right))
//    {
//        current_frame += 0.005 * time;
//        if (current_frame > 4)
//            current_frame -= 4;
//        hero_sprite.move(0.1 * time, 0);
//        hero_sprite.setTextureRect(IntRect(64 * int(current_frame), 128, 64, 64));
//    }
//    if (Keyboard::isKeyPressed(Keyboard::Left))
//    {
//        current_frame += 0.005 * time;
//        if (current_frame > 4)
//            current_frame -= 4;
//        hero_sprite.move(-0.1 * time, 0);
//        hero_sprite.setTextureRect(IntRect(64 * int(current_frame), 64, 64, 64));
//    }
//    if (Keyboard::isKeyPressed(Keyboard::Up))
//    {
//        current_frame += 0.005 * time;
//        if (current_frame > 4)
//            current_frame -= 4;
//        hero_sprite.move(0, -0.1 * time);
//        hero_sprite.setTextureRect(IntRect(64 * int(current_frame), 192, 64, 64));
//    }
//    if (Keyboard::isKeyPressed(Keyboard::Down))
//    {
//        current_frame += 0.005 * time;
//        //cout << current_frame << "\n";
//        if (current_frame > 4)
//            current_frame -= 4;
//        hero_sprite.move(0, 0.1 * time);
//        hero_sprite.setTextureRect(IntRect(64 * int(current_frame), 0, 64, 64));
//    }
    // Установка цвета фона
    //window.clear(Color::White);

    /*const int width = 20;
    const int height = 20;
    int mass[height][width];
    int w = 32;
    for (int i = 1; i < height - 1; i++)
    {
        for (int j = 1; j < width - 1; j++)
        {
            int random_number = rand() % 3;
            if (random_number == 1)
            {
                mass[i][j] = 1;
            }
            else if(random_number == 2)
            {
                mass[i][j] = 2;
            }
            else
            {
                mass[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < height - 1; i++)
    {
        for (int j = 1; j < width - 1; j++)
        {
            sprite.setTextureRect(IntRect(mass[i][j] * w, 0, w, w));
            sprite.setPosition(i * w, j * w);

            window.draw(sprite);
        }
    } */
    /*window.clear();
    window.draw(hero_sprite);
    window.display();*/
    /* }*/
     /*window.draw(hero_sprite);
     window.display();*/