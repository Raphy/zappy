
#ifndef		ISAFE_QUEUE_HH_
# define	ISAFE_QUEUE_HH_ 

template <typename T>
class ISafeQueue
{
public:
	virtual ~ISafeQueue() {}

	virtual void push(const T& value) = 0;
	virtual bool tryPop(T& value) = 0;
	virtual T pop(void) = 0;
	virtual bool isFinished(void) = 0;
	virtual bool isEmpty(void) = 0;
	virtual void setFinished(void) = 0;
};

#endif
