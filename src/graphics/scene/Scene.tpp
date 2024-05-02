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
        Sphere sphere_1(Math::Vec3(0, 0, -1), 0.5);
        add_object(std::make_shared<Sphere>(sphere_1));
        Sphere sphere_3(Math::Vec3(0, -100.5, -1), 100);
        add_object(std::make_shared<Sphere>(sphere_3));
        this->pixelSampleScale = 1.0 / this->samplePerPixels;
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
        this->_pixels.clear();
        this->_pixels.resize(Width * Height * 6);

        Threads rend_threads;
        const size_t num_threads = std::thread::hardware_concurrency();

        auto render_segment = [this](int start_row, int end_row) {
            for (int j = start_row; j < end_row; j++) {
                for (int i = 0; i < _width; i++) {
                    calculatePixelColor(i, j);
                }
            }
        };
        rend_threads.execute(render_segment, 0, _height, num_threads);
    }

    template<int Width, int Height>
    void Scene<Width, Height>::calculatePixelColor(int i, int j) {
        Color pixel_color(0,0,0);

        for (int sample = 0; sample < this->samplePerPixels; sample++) {
            Ray3D ray = _camera.castRay(i, j);
            pixel_color += ray.color(_objects);
        }
        pixel_color = pixel_color / this->samplePerPixels;
        pixel_color *= this->pixelSampleScale;
        size_t pixel_index = (j * _width + i) * 4;
        _pixels[pixel_index] = static_cast<sf::Uint8>(pixel_color.r() * 256);
        _pixels[pixel_index + 1] = static_cast<sf::Uint8>(pixel_color.g() * 256);
        _pixels[pixel_index + 2] = static_cast<sf::Uint8>(pixel_color.b() * 256);
        _pixels[pixel_index + 3] = static_cast<sf::Uint8>(255);  // Full alpha
    }
}
