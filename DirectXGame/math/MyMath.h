#pragma once
#include"Vector3.h"
#include"Matrix4x4.h"


class MyMath
{
		


	public:
	
		struct Line {
			Vector3 origin;
			Vector3 diff;
		};

		struct Ray {
			Vector3 origin;
			Vector3 diff;
		};

		struct Segment {
			Vector3 origin;
			Vector3 diff;
		};

		static const int kColumnWidth = 60;

		//加算
		static Vector3 Add(const Vector3& v1, const Vector3& v2);
		//減算
		static Vector3 Subtract(const Vector3& v1, const Vector3& v2);
		//スカラー倍
		static Vector3 Multiply(float scalar, const Vector3& v);
		//内積
		static float Dot(const Vector3& v1, const Vector3& v2);
		//長さ(ノルム)
		static float Length(const Vector3& v);
		//正規化
		static Vector3 Normalize(const Vector3& v);
		//
		static void VectorScreenPrintf(int x, int y, const Vector3& vector,const char*label);
		//座標変換
		static Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix);
		

		//
		static Vector3 Cross(const Vector3& v1, const Vector3& v2);

		//
		static Vector3 Project(const Vector3& v1, const Vector3& v2);
		//
		static Vector3 ClosePoint(const Vector3& point, const Segment& segment);

};

