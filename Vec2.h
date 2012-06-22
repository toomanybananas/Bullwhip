/**
 * @file Vec2.h
 * @brief Position vector
 * @author neos300
 * @version 1.0
 * @date 2012-06-21
 */

#ifndef VEC2_H
#define VEC2_H
#include <Box2D/Box2D.h>


/**
 * @brief 2D position vector
 */
class Vec2
{
    public:
        Vec2();
        Vec2(float m, float n) {x = m; y = n;};
        float x;
        float y;
	/**
	 * @brief Converts the vector to a box2D vector, with the scale factor in
	 *
	 * @return The box2D vector
	 */
        b2Vec2 toBox();
	/**
	 * @brief Returns a box2D vector without using the scale
	 *
	 * @return 
	 */
        b2Vec2 tob2();
    protected:
    private:
};

#endif // VEC2_H

