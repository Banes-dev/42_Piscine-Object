#pragma once

enum class Event
{
	RingBell
};

class IObserver
{
	public:
		virtual ~IObserver() = default;

		virtual void Notify(Event aEvent) = 0;
};
