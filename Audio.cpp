// Header Files
#include "Audio.h"

bool Audio::Initialise(int frequency, int chunksize)
{
    if (Mix_OpenAudio(frequency, AUDIO_S16SYS, 2, chunksize) == -1)
    {
        Utility::Log(Utility::Destination::WindowsMessageBox, "Audio did not initialise successfully!", Utility::Severity::Failure);
        return false;
    }

    return true;
}

bool Audio::Load(const std::string& filename, bool fileIsMusic)
{
    if (fileIsMusic)
    {
        music = Mix_LoadMUS(filename.c_str());
        isFileMusic = true;
        if (!music)
        {
            Utility::Log(Utility::Destination::WindowsMessageBox, "Error Loading File", Utility::Severity::Failure);
            return false;
        }
    }

    else
    {
        sound = Mix_LoadWAV(filename.c_str());
        if (!sound)
        {
            Utility::Log(Utility::Destination::WindowsMessageBox, "Error Loading File", Utility::Severity::Failure);
            return false;
        }
    }

    return true;
}

void Audio::Unload()
{
    if (isFileMusic)
    {
        Mix_FreeMusic(music);
    }

    else
    {
        Mix_FreeChunk(sound);
    }
}

void Audio::CloseAudio()
{
    Mix_CloseAudio();
}

void Audio::SetVolume(float volume)
{
    if (isFileMusic)
    {
        volume = std::clamp(volume, 0.0f, 1.0f);
        Mix_VolumeMusic(static_cast<int>(volume * 128.0f));
    }

    else
    {
        volume = std::clamp(volume, 0.0f, 1.0f);
        Mix_VolumeChunk(sound, static_cast<int>(volume * 128.0f));
    }
}

bool Audio::Play(Loop loop)
{
    if (isFileMusic)
    {
        if (!Mix_PlayingMusic())
        {
            if (Mix_PlayMusic(music, static_cast<int>(loop)) == -1)
            {
                Utility::Log(Utility::Destination::WindowsMessageBox, "Error Playing Music", Utility::Severity::Failure);
                return false;
            }
        }
    }

    else
    {
        if (Mix_PlayChannel(-1, sound, static_cast<int>(loop)) == -1)
        {
            Utility::Log(Utility::Destination::WindowsMessageBox, "Error Playing Sound", Utility::Severity::Failure);
            return false;
        }
    }

    return true;
}

void Audio::Pause()
{
    if (!Mix_PausedMusic())
    {
        Mix_PauseMusic();
    }
}

void Audio::Resume()
{
    if (Mix_PausedMusic())
    {
        Mix_ResumeMusic();
    }
}

void Audio::Stop()
{
    if (Mix_PlayingMusic())
    {
        Mix_HaltMusic();
    }
}