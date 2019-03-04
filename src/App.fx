cbuffer VS_CONSTANT_BUFFER : register(b0)
{
	float cb_a;
	float cb_b;
	float cb_c;
	float cb_d;
};

//--------------------------------------------------------------------------------------
// Vertex Shader
//--------------------------------------------------------------------------------------
float4 VS(float4 Pos : POSITION) : SV_POSITION
{
	return Pos + float4(cb_d, 0, 0, 0);
}

//--------------------------------------------------------------------------------------
// Pixel Shader
//--------------------------------------------------------------------------------------
float4 PS(float4 Pos : SV_POSITION) : SV_Target
{
	return float4(cb_a, cb_b, cb_c, 1);
}