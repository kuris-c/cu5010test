// Header Files
#include "Background.h"

Background::~Background()
{
	music.Unload();
	image.Unload();
}

void Background::Load(const std::string& imageFilename, const std::string& musicFilename)
{
	auto resolution = Window::Instance()->GetResolution();

	if (musicFilename != "")
	{
		music.Initialise();
		music.Load(musicFilename, true);
		music.SetVolume(0.5f);
	}

	image.Load(imageFilename, "bg");
	image.SetTexture("bg");
	image.SetDimension(resolution.x, resolution.y);
	image.SetSourceDimension(1, 1, resolution.x, resolution.y);
}

void Background::PlayMusic()
{
	if (!isPlaying)
	{
		music.Play(Audio::Loop::Ongoing);
		isPlaying = true;
	}
}

void Background::StopMusic()
{
	music.Stop();
	isPlaying = false;
}

bool Background::Render()
{
	image.Render();
	return true;
}
