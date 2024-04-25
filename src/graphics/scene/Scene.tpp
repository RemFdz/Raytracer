/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Scene class
*/

namespace Rtx {
    template<int Width, int Height>
    Scene<Width, Height>::Scene(
        double aspectRatio,
        Camera camera
    ) : _aspectRatio(aspectRatio), _camera(camera) {

        _width = Width;
        _height = Width / _aspectRatio;

        if (_height < 1)
            _height = 1;

        _pixels.clear();
        _pixels.reserve(Width * Height * 4);
    }

    template<int Width, int Height>
    void Scene<Width, Height>::generateImage() {
        Color pixel_color;
        Sphere sphere(Math::Vec3(0, 0, -1), 0.5);
        add_object(std::make_shared<Sphere>(sphere));

        std::cout << "P3\n" << _width << ' ' << _height << "\n255\n";
        for (int j = 0; j < _height; j++) {
            std::clog << "\rScanlines remaining: " << (_height - j) << ' ' <<
                std::flush;
            for (int i = 0; i < _width; i++) {
                Ray3D ray = _camera.castRay(i, j);
                pixel_color = ray.color(_objects);
                pixel_color.write_color(std::cout);
            }
        }
        std::clog << "\rDone.\n";
    }

    template<int Width, int Height>
    void Scene<Width, Height>::fillSfUint8Pixels() {
        Color pixel_color;
        Sphere sphere_1(Math::Vec3(0, 0, -1), 0.5);
        add_object(std::make_shared<Sphere>(sphere_1));
        Sphere sphere_2(Math::Vec3(0, 1, -4), 0.5);
        add_object(std::make_shared<Sphere>(sphere_2));

        this->_pixels.clear();
        this->_pixels.reserve(Width * Height * 4);

        for (int j = 0; j < _height; j++) {
            for (int i = 0; i < _width; i++) {
                Ray3D ray = _camera.castRay(i, j);
                pixel_color = ray.color(_objects);
                _pixels.push_back(static_cast<sf::Uint8>(pixel_color.r() * 255.999));
                _pixels.push_back(static_cast<sf::Uint8>(pixel_color.g() * 255.999));
                _pixels.push_back(static_cast<sf::Uint8>(pixel_color.b() * 255.999));
                _pixels.push_back(static_cast<sf::Uint8>(pixel_color.a() *
                    255.999));
            }
        }
    }
}