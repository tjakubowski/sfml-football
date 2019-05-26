#pragma once
#include <SFML/System/Vector2.hpp>

static double sqrMagnitude(sf::Vector2f vector)
{
	return vector.x * vector.x + vector.y * vector.y;
}

static double sqrMagnitude(sf::Vector2i vector)
{
	return sqrMagnitude(sf::Vector2f(vector));
}

static double sqrMagnitude(sf::Vector2u vector)
{
	return sqrMagnitude(sf::Vector2f(vector));
}

static double magnitude(sf::Vector2f vector)
{
	return sqrt(sqrMagnitude(vector));
}

static double magnitude(sf::Vector2i vector)
{
	return sqrt(sqrMagnitude(vector));
}

static double magnitude(sf::Vector2u vector)
{
	return sqrt(sqrMagnitude(vector));
}

static sf::Vector2f normalize(sf::Vector2f vector)
{
	const auto vectorMagnitude = static_cast<float>(magnitude(vector));

	return vectorMagnitude > 0 ? vector / vectorMagnitude : sf::Vector2f(0, 0);
}

static sf::Vector2f normalize(sf::Vector2i vector)
{
	return normalize(sf::Vector2f(vector));
}

static sf::Vector2f normalize(sf::Vector2u vector)
{
	return normalize(sf::Vector2f(vector));
}

static sf::Vector2f clampMagnitude(sf::Vector2f vector, const float& maxLength)
{
	if (sqrMagnitude(vector) > static_cast<double>(maxLength) * static_cast<double>(maxLength))
		return normalize(vector) * maxLength;

	return vector;
}

static sf::Vector2f clampMagnitude(sf::Vector2i vector, const float& maxLength)
{
	return clampMagnitude(sf::Vector2f(vector), maxLength);
}

static sf::Vector2f clampMagnitude(sf::Vector2u vector, const float& maxLength)
{
	return clampMagnitude(sf::Vector2f(vector), maxLength);
}

static bool isZero(sf::Vector2f vector)
{
	return abs(vector.x) < 0.001 && abs(vector.y) < 0.001;
}

static bool isZero(sf::Vector2i vector)
{
	return isZero(sf::Vector2f(vector));
}

static bool isZero (sf::Vector2u vector)
{
	return isZero(sf::Vector2f(vector));
}

static sf::Vector2f rotate(sf::Vector2f vector, float angle)
{
	angle *= 3.14159 / 180.0f;

	return sf::Vector2f(
		vector.x * cos(angle) - vector.y * sin(angle),
		vector.x * sin(angle) + vector.y * cos(angle)
	);
}

static sf::Vector2i rotate(sf::Vector2i vector, float angle)
{
	angle *= 3.14159 / 180.0f;

	return sf::Vector2i(
		vector.x * cos(angle) - vector.y * sin(angle),
		vector.x * sin(angle) + vector.y * cos(angle)
	);
}

static sf::Vector2u rotate(sf::Vector2u vector, float angle)
{
	angle *= 3.14159 / 180.0f;

	return sf::Vector2u(
		vector.x * cos(angle) - vector.y * sin(angle),
		vector.x * sin(angle) + vector.y * cos(angle)
	);
}