#pragma once
template <typename T>
class TSingleton
{
protected:
	TSingleton() {}
	virtual	~TSingleton() {}

public:
	static T* GetInstance()
	{
		return mInstance;
	}

	static void Initialize()
	{
		if (mInstance == nullptr)
		{
			mInstance = new T;
		}
	}

	static void Destroy()
	{
		delete mInstance;
		mInstance = nullptr;
	}

private:
	static T* mInstance;
};

template<typename T>
T* TSingleton<T>::mInstance = nullptr;