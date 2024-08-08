#include "MyMath.h"
#include<cmath>
#include<Novice.h>
#include <cassert>

Vector3 MyMath::Add(const Vector3& v1, const Vector3& v2)
{
	Vector3 v3;

	v3.x = v1.x + v2.x;
	v3.y = v1.y + v2.y;
	v3.z = v1.z + v2.z;

	return v3;
}

Vector3 MyMath::Subtract(const Vector3& v1, const Vector3& v2)
{
	Vector3 v3;

	v3.x = v1.x - v2.x;
	v3.y = v1.y - v2.y;
	v3.z = v1.z - v2.z;

	return v3;
}

Vector3 MyMath::Multiply(float scalar, const Vector3& v)
{
	Vector3 v3;

	v3.x = v.x * scalar;
	v3.y = v.y * scalar;
	v3.z = v.z * scalar;

	return v3;
}

float  MyMath::Dot(const Vector3& v1, const Vector3& v2)
{
	float v3;

	v3 = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);

	return v3;
}

float  MyMath::Length(const Vector3& v)
{
	float result;

	result = sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z));

	return result;
}

Vector3 MyMath::Normalize(const Vector3& v)
{
	Vector3 result;
	float length;

	length = Length(v);

	result.x = v.x / length;
	result.y = v.y / length;
	result.z = v.z / length;

	return result;
}


void MyMath::VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label) {
	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", vector.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%.02f", vector.z);
	Novice::ScreenPrintf(x + kColumnWidth * 3, y, "%s", label);
}


Vector3 MyMath::Transform(const Vector3& vector, const Matrix4x4& matrix)
{
	Vector3 result;

	result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + vector.z * matrix.m[2][0] + 1.0f * matrix.m[3][0];
	result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + vector.z * matrix.m[2][1] + 1.0f * matrix.m[3][1];
	result.z = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + vector.z * matrix.m[2][2] + 1.0f * matrix.m[3][2];
	float w = vector.x * matrix.m[0][3] + vector.y * matrix.m[1][3] + vector.z * matrix.m[2][3] + 1.0f * matrix.m[3][3];

	assert(w != 0.0f);
	result.x /= w;
	result.y /= w;
	result.z /= w;

	return result;


}

Vector3 MyMath::Cross(const Vector3& v1, const Vector3& v2)
{

	Vector3 result;

	result = { (v1.y * v2.z) - (v1.z * v2.y), (v1.z * v2.x) - (v1.x * v2.z), (v1.x * v2.y) - (v1.y * v2.x) };

	return result;
}

Vector3 MyMath::Project(const Vector3& v1, const Vector3& v2)
{
	//v1��v2�̓���
	float dotProduct = Dot(v1, v2);

	//v2�̒���
	float v2Length = Length(v2);

	float scaleFactor = dotProduct / v2Length;
	Vector3 projection = { v2.x * scaleFactor, v2.y * scaleFactor, v2.z * scaleFactor };

	return projection;
}

Vector3 MyMath::ClosePoint(const Vector3& point, const Segment& segment)
{
	Vector3 toPoint = Subtract(point, segment.origin);

	// �����̕����x�N�g��
	Vector3 segmentDir = segment.diff;

	// �����̕����x�N�g���̒����̓��
	float segmentDirLengthSquared = segmentDir.x * segmentDir.x + segmentDir.y * segmentDir.y + segmentDir.z * segmentDir.z;

	// �����̕����x�N�g����0�x�N�g���ł���ꍇ�A�n�_���ŋߐړ_�ƂȂ�
	if (segmentDirLengthSquared == 0) {
		return segment.origin;
	}

	// �����̕����x�N�g���Ɠ_����n�_�ւ̃x�N�g���̓��ς��v�Z
	float t = Dot(toPoint, segmentDir) / segmentDirLengthSquared;

	// t��0�����̏ꍇ�A�ŋߐړ_�͎n�_���̉�����ɂ���
	if (t < 0) {
		return segment.origin;
	}

	// t��1���傫���ꍇ�A�ŋߐړ_�͏I�_���̉�����ɂ���
	if (t > 1) {
		return Vector3{ segment.origin.x + segment.diff.x, segment.origin.y + segment.diff.y, segment.origin.z + segment.diff.z };
	}
	// �ŋߐړ_���v�Z���ĕԂ�
	return { segment.origin.x + segment.diff.x * t, segment.origin.y + segment.diff.y * t, segment.origin.z + segment.diff.z * t };
}
}


