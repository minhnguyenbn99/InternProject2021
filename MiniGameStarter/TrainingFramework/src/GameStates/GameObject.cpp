#include "GameObject.h"
//#include <conio.h>
//
//GameObject::GameObject(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture)
//	: Sprite2D(-1, model, shader, texture)
//{
//}
//
//GameObject::~GameObject()
//{
//}
//
//void GameObject::Running() {
//	if (_kbhit())
//	{
//		int key = _getch();
//		HandleKeyEvents(key, true);
//
//	}
//
//}
//bool GameObject::HandleKeyEvents(int key, bool bIsPressed)
//{
//	if (bIsPressed == true) {
//		switch (key)
//		{
//		case 'A':
//			m_keyPressed |= KEY_MOVE_LEFT;
//			break;
//		case 'D':
//			m_keyPressed |= KEY_MOVE_RIGHT;
//			break;
//		case 'W':
//			m_keyPressed |= KEY_MOVE_FORWORD;
//			break;
//		case 'S':
//			m_keyPressed |= KEY_MOVE_BACKWORD;
//			break;
//		default:
//			break;
//		}
//	}
//	else {
//
//		switch (key)
//		{
//		case 'A':
//			m_keyPressed ^= KEY_MOVE_LEFT;
//			break;
//		case 'D':
//			m_keyPressed ^= KEY_MOVE_RIGHT;
//			break;
//		case 'W':
//			m_keyPressed ^= KEY_MOVE_FORWORD;
//			break;
//		case 'S':
//			m_keyPressed ^= KEY_MOVE_BACKWORD;
//			break;
//		default:
//			break;
//		}
//	}
//	return bIsPressed;
//}
//
////bool GameObject::IsHolding()
////{
////	return m_isHolding;
////}
