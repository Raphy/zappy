/*
 ** Binder.cpp for zappy in /home/marie/modules/unix/zappy/zappy/project/world/sources
 **
 ** Made by Marie Lefebvre
 ** Login   <lefebv_z@epitech.eu>
 **
 ** Started on  Mon May  19 14:38:40 2014 Marie Lefebvre
 ** Last update Mon May  19 14:43:04 2014 Marie Lefebvre
 */

#include "Binder.hh"

Binder* Binder::getInstance(int winW, int winH,
	bool realUserMode)
{
    static Binder instance(winW, winH, realUserMode);
    return (&instance);
}

Binder::Binder(int winW, int winH, bool realUserMode)
: _winW(winW), _winH(winH), _realUserMode(realUserMode)
{}
Binder::~Binder()
{}
