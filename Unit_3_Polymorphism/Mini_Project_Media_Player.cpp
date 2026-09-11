#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Media {
protected:
    string title;

public:
    Media(string t) : title(t) {}

    virtual void play() const = 0;
    virtual void pause() const = 0;
    virtual void stop() const = 0;
    virtual void showDetails() const = 0;

    virtual ~Media() = default;
};

class Audio : public Media {
private:
    string artist;

public:
    Audio(string t, string a)
        : Media(t), artist(a) {}

    void play() const override {
        cout << "Playing audio: " << title << endl;
    }

    void pause() const override {
        cout << "Audio paused: " << title << endl;
    }

    void stop() const override {
        cout << "Audio stopped: " << title << endl;
    }

    void showDetails() const override {
        cout << "Audio | Title: " << title
             << " | Artist: " << artist << endl;
    }
};

class Video : public Media {
private:
    string resolution;

public:
    Video(string t, string r)
        : Media(t), resolution(r) {}

    void play() const override {
        cout << "Playing video: " << title << endl;
    }

    void pause() const override {
        cout << "Video paused: " << title << endl;
    }

    void stop() const override {
        cout << "Video stopped: " << title << endl;
    }

    void showDetails() const override {
        cout << "Video | Title: " << title
             << " | Resolution: " << resolution << endl;
    }
};

class Image : public Media {
private:
    string format;

public:
    Image(string t, string f)
        : Media(t), format(f) {}

    void play() const override {
        cout << "Displaying image: " << title << endl;
    }

    void pause() const override {
        cout << "Image display paused: " << title << endl;
    }

    void stop() const override {
        cout << "Image display stopped: " << title << endl;
    }

    void showDetails() const override {
        cout << "Image | Title: " << title
             << " | Format: " << format << endl;
    }
};

int main() {
    vector<unique_ptr<Media>> mediaList;

    mediaList.push_back(
        make_unique<Audio>("Shape of You", "Ed Sheeran")
    );

    mediaList.push_back(
        make_unique<Video>("C++ Tutorial", "1080p")
    );

    mediaList.push_back(
        make_unique<Image>("College Campus", "JPG")
    );

    cout << "=== Media Player ===" << endl;

    for (const auto& media : mediaList) {
        media->showDetails();
        media->play();
        media->pause();
        media->stop();
        cout << endl;
    }

    return 0;
}