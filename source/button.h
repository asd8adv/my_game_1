#include <functional>
#include <utility>
#include "object.h"
#include "icons.h"

class BaseButton:public Icon
{
	using Base = Icon;
	enum class State {
		enabled = 0,
		pressed,
		scaled,
		hovered,
		disabled,
		unvisible
	};
protected:

	State state_;
	float scale_=1.0f;
	//float borderScale_;
	bool enabled_;
	bool visible_;
	bool isHovered_;
	bool isScaled;
	float scaleTime_ = 0.5f;
	const float SCALETIME_ = 0.5f;
	std::function<void()> callback_;

public:
	BaseButton(const std::string& resourceName):Icon(resourceName) {
		Base::setScale(1);
	}

	template<typename F>
	void setCallback(F&& f) {
		callback_= std::forward<F>(f) ;
	}

	virtual void setState(State state) {
		state_ = state;
	}
	virtual void setScale(float scale) {
		scale_ = scale;
		Base::setScale(scale);
	}

	void updateScale(float dt) {
		if(isScaled){
			scaleTime_ -= dt;
			if (scaleTime_ > 0.3f) {
				scale_ = 1+0.5-scaleTime_;
			}
			if (scaleTime_ > 0.2f && scaleTime_ < 0.3f) {
				scale_ = 1.2;
			}
			if (scaleTime_ < 0.2f) {
				scale_ = 1 + scaleTime_;
			}
		}
		else {
			scaleTime_ = SCALETIME_;
			scale_ = 1;
		}
		Base::setScale(scale_);
	}

	virtual void update(float dt) {
		Base::setScale(scale_);
		
		//updateState();
		//updateScale(dt);
	}

	void updateState() {
		switch (state_) {
		case BaseButton::State::enabled:
			enabled_ = true;

			break;
		case BaseButton::State::pressed:
			if (enabled_) {
				scale_ = 1;


			}
		case BaseButton::State::scaled:
			if (enabled_) {

				if (scale_ < 1.01) {
					setState(State::enabled);
				}

			}


			break;
		case BaseButton::State::hovered:
			if (enabled_) {
				if(isHovered_){
					scale_ *= 1.1;
				}
				else {
					setState(State::enabled);
				}

			}


			break;
		case BaseButton::State::disabled:
			enabled_ = false;

			break;
		case BaseButton::State::unvisible:
			enabled_ = false;

			break;
		default:
			break;
		};


	}
	
	virtual bool checkHover(vec2 pos) {
		return false;
	}
	
	virtual void draw(sf::RenderWindow& wind) override {
		Base::draw(wind);
	}
};



class bigButton : public BaseButton, public Text
{
	using Base = BaseButton;
public:
	bigButton(const std::string& resourceName, const std::string& text):Text(text), Base(resourceName) {
		
	}

	virtual void setScale(float scale) override {
		if (scale != scale_) {
			Base::setScale(scale);

			std::cout << "scale=" << scale << "\n";
		}
	}

	virtual void update(float dt) {
		Base::update(dt);
		setScale(scale_);
	}

	virtual void draw(sf::RenderWindow& wind) override {
		Base::draw(wind);
		Text::draw(wind);
	}

	virtual void setPosition(vec2 pos){
		Base::setPosition(pos);
	}

	virtual void setSize(vec2 size) {
		Base::setIconSize(size.x, size.y);
		uint32_t sizeTex = (Text::text_.getCharacterSize() * Text::text_.getString().getSize());
		sizeTex /= 2;
		if (size.x < sizeTex) {
			std::cerr << "btn sizes error, very long text\n";
			Text::setPosition(Base::getPosition());
			return;
		}
		auto iconPos = Base::getPosition();
		vec2 dPos((size.x - sizeTex) / 2, size.y / 2);
		Text::setPosition(iconPos + dPos);
		BaseObject::set(iconPos.x, iconPos.y, size.x, size.y);

	}

	virtual bool checkHover(vec2 pos) override{//to do rename
		auto haveCollision = isCollision(*this, pos);
		if (haveCollision) {
			std::cout << "1\n";
			isHovered_ = true;
			setScale(1.5f);
			return haveCollision;
		}
		std::cout << "0\n";
		setScale(1.0f);
		return haveCollision;
	}



};