#pragma once
#include "Sprite2D.h"
class AnimationSprite :
	public Sprite2D
{
private:
	std::string		m_Text;
	void			CaculateWorldMatrix();
protected:
	Vector2			m_Vec2DPos;
	GLint			m_iHeight;
	GLint			m_iWidth;
	float			m_currentTime;
	float			u_numFrames;
	float			u_currentFrame;
	float			m_frameTime;

public:
	AnimationSprite(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture, float numFrames, float frameTime);
	AnimationSprite(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, Vector4 color, float numFrames, float frameTime);
	~AnimationSprite();

	void		Init() override;
	void		Draw() final;
	void		Update(GLfloat deltatime) override;

	void		SetText(std::string text);
	std::string	GetText();

	void		Set2DPosition(GLfloat x, GLfloat y);
	void		Set2DPosition(Vector2 pos);

	Vector2		Get2DPosition();
	void		SetSize(GLint width, GLint height);
};