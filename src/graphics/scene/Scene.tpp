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

        for (auto &row: _pixels) {
            row.fill(Color(0, 0, 0));
        }
    }

    template<int Width, int Height>
    void Scene<Width, Height>::generateImage() {
        Color pixel_color;
        Sphere sphere(Math::Vec3(0, 0, -1), 0.5);

        std::cout << "P3\n" << _width << ' ' << _height << "\n255\n";
        for (int j = 0; j < _height; j++) {
            std::clog << "\rScanlines remaining: " << (_height - j) << ' ' <<
                      std::flush;
            for (int i = 0; i < _width; i++) {
                Ray3D ray = _camera.castRay(i, j);
                double t = sphere.hit(ray);
                pixel_color = ray.color(t);
                _pixels[j][i] = pixel_color;
                pixel_color.write_color(std::cout);
            }
        }
        std::clog << "\rDone.\n";
    }
}