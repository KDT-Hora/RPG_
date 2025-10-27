#pragma once
#include <memory>
#include <vector>
#include <stack>
#include <stdexcept>

//	前方宣言
template <typename T>
class ObjectPool;


template <typename T>
class PoolHandle
{
	friend class ObjectPool<T>;
	explicit PoolHandle(T* obj, ObjectPool<T>* pool)
		:obj_(obj), pool_(pool)
	{
	}

public:
	//	コピー禁止
	PoolHandle(const PoolHandle&) = delete;
	//	ムーブ可能
	PoolHandle(PoolHandle&& other)noexcept
		:obj_(other.obj_), pool_(other.pool_)
	{
		other.obj_ = nullptr;
		other.pool_ = nullptr;
	}

	//	デストラクタで自動返却
	~PoolHandle()
	{
		if (obj_ && pool_)
		{
			pool_->Release(obj_);
		}
	}

	//	アクセス演算子
	T* operator->() { return obj_; }
	T& operator*() { return *obj_; }

	//	ムーブの定義
	PoolHandle& operator=(PoolHandle&& other) noexcept
	{
		if (this != &other)
		{
			if (obj_ && pool_)
				pool_->Release(obj_);
			obj_ = other.obj_;
			pool_ = other.pool_;
			other.obj_ = nullptr;
			other.pool_ = nullptr;
		}
		return *this;
	}

private:
	T* obj_;
	ObjectPool<T>* pool_;
};

//	オブジェクトプールクラス
template <typename T>
class ObjectPool
{
	friend class PoolHandle<T>;
public:
	explicit ObjectPool(size_t capacity)
	{
		objects_.reserve(capacity);

		for (size_t i = 0; i < capacity; i++)
		{
			objects_.emplace_back(std::make_unique<T>());
			free_.push(objects_.back().get());
		}
	}

	PoolHandle<T> Acquire()
	{
		if (free_.empty()) throw std::runtime_error("empty");
		T* obj = free_.top();
		free_.pop();
		return PoolHandle<T>(obj, this);
	}

private:
	void Release(T* obj) { free_.push(obj); }
	std::vector<std::unique_ptr<T>> objects_;
	std::stack<T*> free_;
};