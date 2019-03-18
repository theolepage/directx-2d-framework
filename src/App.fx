cbuffer VS_CONSTANT_BUFFER : register(b0)
{
	float colorR;
	float colorG;
	float colorB;

	float positionX;
	float positionY;
};

//--------------------------------------------------------------------------------------
// Vertex Shader
//--------------------------------------------------------------------------------------
float4 VS(float4 Pos : POSITION) : SV_POSITION
{
	return Pos + float4(positionX, positionY, 0, 0);
}

//--------------------------------------------------------------------------------------
// Pixel Shader
//--------------------------------------------------------------------------------------
float4 PS(float4 Pos : SV_POSITION) : SV_Target
{
	return float4(colorR, colorG, colorB, 1);
}