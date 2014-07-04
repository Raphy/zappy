
#ifndef		SAFE_QUEUE_HH_
# define	SAFE_QUEUE_HH_ 

# include	<queue>
# include	"ISafeQueue.hh"
# include	"IMutex.hh"
# include	"ICondVar.hh"

template <typename T>
class SafeQueue : public ISafeQueue<T>
{
public:
  SafeQueue();
  ~SafeQueue();

  void		push(const T& value);
  bool		tryPop(T& value);
  T		pop(void);
  bool		isFinished(void);
  bool		isEmpty(void);
  void		setFinished(void);
  const T&	front(void) const;
  const T&	back(void) const;
  T&		front(void);
  T&		back(void);

private:
	std::queue<T>	_queue;
	IMutex *		_mutex;
	ICondVar *		_cond;
	bool			_finished;
};

#endif
