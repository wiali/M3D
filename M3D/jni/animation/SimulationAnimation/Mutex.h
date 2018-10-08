/**
 *@file
 *@brief
 *@author	XL
 *@date		2015-2-26
 *@version	1.0
 *
 */
#ifndef MUTEX_H
#define MUTEX_H

namespace NS_SimulationAnimation
{
/// Operating system mutual exclusion primitive.
class   Mutex
{
public:
	/// Construct.
	Mutex();
	/// Destruct.
	~Mutex();

	Mutex(const Mutex& orig);
	Mutex& operator =(const Mutex& orig);

	/// Acquire the mutex. Block if already acquired.
	void Acquire();
	/// Release the mutex.
	void Release();

private:
	/// Mutex handle.
	void* handle_;
};

/// Lock that automatically acquires and releases a mutex.
class   MutexLock
{
public:
	/// Construct and acquire the mutex.
	MutexLock(Mutex& mutex);
	/// Destruct. Release the mutex.
	~MutexLock();

private:
	/// Prevent copy construction.
	MutexLock(const MutexLock& rhs);
	/// Prevent assignment.
	MutexLock& operator =(const MutexLock& rhs);

	/// Mutex reference.
	Mutex& m_mutex;
};

}
#endif //MUTEX_H
