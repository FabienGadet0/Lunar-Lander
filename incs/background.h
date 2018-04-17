// #ifndef BACKGROUND_H_
// #define BACKGROUND_H_

// #include <SFML/Graphics.hpp>

// class Background{
//   private:
//     // You only need an image and a background, if that.
//     sf::Texture BGI;
//     sf::Sprite BG;

//   public:
//     // Use a constructor.
//     Background() 
//     {
//         SetBackground("./assets/background.jpg",sf::Vector2f(0.f, 0.f));
//     }
//     Background(std::string name)
//     {
//       SetBackground(name, sf::Vector2f(0.f, 0.f));
//     }
//     void SetBackground(std::string name, sf::Vector2f pos)
//     {
//       BGI.loadFromFile(name);
//       BG.setTexture(BGI);
//       BG.setPosition(pos);
//     }
//     void setPos(const sf::Vector2f &p)
//     {
//         BG.setPosition(p);
//     }
//     void draw(sf::RenderWindow &w)
//     {
//         w.draw(BG);
//     }
// };

// #endif