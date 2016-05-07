#pragma once

#include "math\Vector3.h"
#include "core\BufferGeometry.h"

namespace engine
{
	class MetaBall
	{
	public:
		MetaBall(float radius = 1) : radius(radius)
		{ }

	public:
		float radius;
		Vector3 position;
	};

	/** Marching Cube�㷨���Ƶ����棬������������meta ball
	 *  �ο�http://paulbourke.net/geometry/polygonise/
	 */
	class MarchingCube
	{
	public:
		typedef struct
		{
			float value;
			Vector3 position;
		} Vertex;

		typedef Vertex* Cube[8];

		MarchingCube(float interval, int segments);

		~MarchingCube()
		{
			delete[] vertices;
			delete[] cubes;
		}

		BufferGeometry* createSurface(float threshold);

		void addBall(MetaBall& ball)
		{
			metaballs.push_back(&ball);
		}

	public:
		float interval;
		int segments;
		std::vector<MetaBall*> metaballs;

	private:
		Vertex* vertices;
		Cube*   cubes;

		static const int EndOfEdge[24];
		static const int EdgeTable[256];
		static const int TriangleTable[256][16];
	};
}
