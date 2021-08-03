// AwakeListenerEmpty
// Andre Berthiaume, 5/17

#ifndef _AwakeListenerEmpty
#define _AwakeListenerEmpty

class b2Body;

class AwakeListenerEmpty
{
	friend class GameObject2D;
private:
	// We have a clear no-op method here
	virtual void TriggerCallback(b2Body* ) {};

public:
	AwakeListenerEmpty() = default;
	virtual ~AwakeListenerEmpty() = default;

	// Called when body is first awaken
	virtual void BeginAwake(b2Body* )	{ };

	// Called when body is first set to sleep
	virtual void EndAwake(b2Body*) { };

	// A true do-nothing object
	static AwakeListenerEmpty NullAwakeListener;
};

#endif _AwakeListenerEmpty
