#include "Ray3D.hpp"

namespace Rtx {
    Math::Vec3 Ray3D::at(double t) {
        return _origin + _direction * t;
    }


    // Corrected color method in Ray3D.cpp
    Color Ray3D::color(std::vector<std::shared_ptr<IObject3D>>& objects, int depth) {
        if (depth <= 0) {
            return Color(); // Return some base case color, e.g., background color
        }

        HitData_t hitData;
        Color best_color;
        bool hit_anything = false;
        double closest_so_far = std::numeric_limits<double>::infinity();

        for (const auto& object : objects) {
            if (object->hit(*this, hitData, 0.001, closest_so_far)) {
                std::cout << "Hit at distance: " << hitData.distanceFromOrigin << std::endl;
                hit_anything = true;
                closest_so_far = hitData.distanceFromOrigin;
                // Use the hit normal to generate a direction on the hemisphere
                Math::Vector3D target = hitData.position + hitData.normal +
                                        Math::random_on_hemisphere(hitData.normal); // Correctly pass the normal vector
                Ray3D bounced_ray(hitData.position, target - hitData.position);
                best_color = 0.5 * bounced_ray.color(objects, depth - 1); // Recursive call
                std::cout << "Color after hit: (" << best_color.x() << ", " << best_color.y() << ", " << best_color.z() << ")" << std::endl;
            }
        }

        if (!hit_anything) {
            Math::Vector3D unit_direction = _direction.unitVector();
            double t = 0.5 * (unit_direction.y() + 1.0);
            return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0); // Correct the namespace if needed
            std::cout << "Background color: (" << best_color.x() << ", " << best_color.y() << ", " << best_color.z() << ")" << std::endl;
        }
        best_color.applyGammaCorrection(2.2);

        return best_color;
    }
}
