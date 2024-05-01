/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** plane shape
*/

#include "Plane.hpp"

bool Plane::hit(const Rtx::Ray3D &ray, HitData_t &hitData, double t_min, double t_max) {
    double denominator = _normal.dot(ray.getDirection());

    // Vérifie si le rayon est parallèle au plan
    if (denominator == 0)
        return false;

    // Calcul de la distance entre l'origine du rayon et le plan
    double t = (_center - ray.getOrigin()).dot(_normal) / denominator;

    // Vérifie si l'intersection est en dehors de l'intervalle spécifié
    if (t < t_min || t > t_max)
        return false;

    // Remplit les données de collision
    hitData.distanceFromOrigin = t;
    hitData.position = ray.at(t);
    hitData.normal = _normal;

    // Détermine l'orientation de la normale en fonction de la direction du rayon
    hitData.front_face = (ray.getDirection().dot(_normal) < 0);
    if (!hitData.front_face)
        hitData.normal = -_normal;

    return true;
}