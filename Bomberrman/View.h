#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;

View view;

View GetPlayerCordinate(float x, float y)
{
	view.setCenter(x + 100, y);
	/*cout << x << " ";*/
	//cout << y << " ";
	return view;
}

//void GetPlayerCordView(float x, float y) {
//	float tempx = 0;
//	float tempy = 0;
//	/*cout << x << " ";*/
//
//	/*if (x < 300) tempx = 600;
//	else if (y > 235) tempy = 435;
//	else if (y < 230) tempy = 330;
//	else if (x > 300) tempx = 300;
//
//	view.setCenter(tempx, tempy);*/
//}

View ChangeView() {
	if (Keyboard::isKeyPressed(Keyboard::Z)) // zoom out view
	{
		view.zoom(1.0006f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::R))// rotate 
	{
		view.rotate(0.1);
	}
	else if (Keyboard::isKeyPressed(Keyboard::N)) // normal view
	{
		view.setSize(800, 480);
	}
	else if (Keyboard::isKeyPressed(Keyboard::B))// zoom in view
	{
		view.setSize(500, 300);
	}
	return view;
}