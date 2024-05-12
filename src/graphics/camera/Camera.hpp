/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Camera
*/

#pragma once

#include <atomic>
#include "../../math/vector3d/Vector3D.hpp"
#include "../ray/Ray3D.hpp"
#include "../../objects/shapes/sphere/Sphere.hpp"
#include "../../models/RenderMode.hpp"
#include "../../display/SfmlDisplay.hpp"
#include "../../objects/objectlist/ObjectList.hpp"
#include "memory"

namespace Rtx {;
    /**
    * @brief Camera class
    * @details Camera class represents the camera of the scene to see the objects
    * **/
    class Camera {
    public:
        static std::mutex totalLinesMutex;
        static std::atomic<int> totalLinesProcessed;
        static std::atomic<int> threadFinished;

        Color backgroundColor = Color(0.8, 0.8, 0.8);

        Camera(
            Math::Vec3 cameraCenter,
            int imageWidth,
            RenderMode renderMode,
            Math::Vec3 lookAt,
            double fov,
            double samplesPerPixel
        );

        /**
        * @brief Initialize the camera properties
        **/
        void init();

        /**
        * @brief Cast a ray from the camera to the scene and check if it intersects with an object
        * @param x The x coordinate of the pixel
        * @param y The y coordinate of the pixel
        * @param objets The list of objects in the scene
        **/
        Color castRay(int x, int y, ObjectList &objets);

        /**
        * @brief Generate the image
        * @param objects The list of objects in the scene
        **/
        void generateImage(ObjectList &objects);

        /**
        *  @brief Fill the Uint8Array with the pixels of the image
        **/
        void fillUint8Array(ObjectList &objects);

        /**
        * @brief Fill the pixels of the image with the color of the objects for a thread
        * @param startRow The start row of the image
        * @param endRow The end row of the image
        **/
        void fillPixelsThread(int startRow, int endRow, int width, int samplesPerPixel, ObjectList& objects,
                              std::vector<sf::Uint8>& pixels, std::shared_ptr<SfmlDisplay>& display, int mode);

        /**
        * @brief Render the image depending on rendermode (generateImage if IMAGE, fillUint8Array if SFML)
        **/
        void render(ObjectList &objects);

        void inline setAspectRatio(double aspectRatio) { _aspectRatio = aspectRatio; }

        void inline setSamplesPerPixel(int samplesPerPixel) { _samplesPerPixel = samplesPerPixel; }

        void inline setFov(double fov) { this->fov = fov; }

        inline std::shared_ptr<SfmlDisplay> getDisplay() {  return _display; }

        /**
        * @brief Move the camera across the scene
        * @param translation The translation vector
        **/
        void move(Math::Vec3 translation);

    private:
        double _aspectRatio = 16.0 / 9.0; ///< The aspect ratio of the camera
        int _samplesPerPixel = 2; ///< The number of samples per pixel

        double fov = 90; ///< The field of view of the camera
        double _viewportHeight; ///< The height of the viewport
        double _viewportWidth; ///< The width of the viewport
        Math::Vec3 _cameraCenter = Math::Vec3(0, 0, 0); ///< The center of the camera
        int _imageWidth = 0; ///< The width of the image
        int _imageHeight = 0; ///< The height of the image

        RenderMode _renderMode; ///< The render mode of the camera
        std::vector<sf::Uint8> _pixels; ///< The pixels of the image
        std::shared_ptr<SfmlDisplay> _display; ///< The display of the camera

        Math::Vec3 _viewportU; ///< The U vector of the viewport
        Math::Vec3 _viewportV; ///< The V vector of the viewport
        Math::Vec3 _pixelDeltaU; ///< The delta U vector of the pixel
        Math::Vec3 _pixelDeltaV; ///< The delta V vector of the pixel
        Math::Vec3 _viewportUpperLeft; ///< The upper left corner of the viewport
        Math::Vec3 _pixel00Loc; ///< The location of the pixel 0,0

        Math::Vec3 _lookAt = Math::Vec3(0, 0, -1); ///< The look at vector of the camera
        Math::Vec3 _upVector = Math::Vec3(0, 1, 0); ///< The up vector of the camera
    };
} // namespace Rtx