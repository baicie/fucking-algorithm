const PENDING = "pending";
const FULFILLED = "fulfilled";
const REJECTED = "rejected";

class MyPromise {
  constructor(executor) {
    this.state = PENDING;
    this.value = undefined;
    this.reason = undefined;
    this.onFulfilledCallbacks = [];
    this.onRejectedCallbacks = [];

    const resolve = (value) => {
      if (this.state === PENDING) {
        queueMicrotask(() => {
          this.state = FULFILLED;
          this.value = value;
          this.onFulfilledCallbacks.forEach((cb) => cb());
        });
      }
    };

    const reject = (reason) => {
      if (this.state === PENDING) {
        queueMicrotask(() => {
          this.state = REJECTED
          this.reason = reason
          this.onRejectedCallbacks.forEach((cb) => cb())
        });
      }
    };

    try {
      executor(resolve, reject)
    } catch (error) {
      reject(error)
    }
  }

  then(onFulfilled, onRejected) {
    return new MyPromise((resolve, reject) => {
      const fulfilledTask = () => {
        try {
          if (typeof onFulfilled !== 'function') {
            resolve(this.value)
          } else {
            const x = onFulfilled(this.value)
            resolvePromise(x, resolve, reject)
          }
        } catch (error) {
          reject(error)
        }
      }

      const rejectedTask = () => {
        try {
          if (typeof onRejected !== 'function') {
            reject(this.reason)
          } else {
            const x = onRejected(this.reason)
            resolvePromise(x, resolve, reject)
          }
        } catch (error) {
          reject(error)
        }
      }

      if (this.state === FULFILLED) {
        queueMicrotask(fulfilledTask)
      } else if (this.state === REJECTED) {
        queueMicrotask(rejectedTask)
      } else {
        this.onFulfilledCallbacks.push(fulfilledTask)
        this.onRejectedCallbacks.push(rejectedTask)
      }
    })
  }

  catch(onRejected) {
    return this.then(null, onRejected)
  }

  finally(cb) {
    return this.then(
      value => MyPromise.resolve(cb()).then(() => value),
      reason => MyPromise.resolve(cb()).then(() => { throw reason })
    )
  }

  static resolve(value) {
    if (value instanceof MyPromise) return value
    return new MyPromise(resolve => resolve(value))
  }

  static reject(reason) {
    return new MyPromise((_, reject) => reject(reason))
  }
}


function resolvePromise(x, resolve, reject) {
  if (x === resolve || x === reject) {
    return reject(new TypeError('Chaining cycle detected'))
  }

  if (x instanceof MyPromise) {
    x.then(resolve, reject)
  } else if (x && (typeof x === 'object' || typeof x === 'function')) {
    let then
    let called = false

    try {
      then = x.then
      if (typeof then === 'function') {
        then.call(x, y => {
          if (called) return
          called = true
          resolvePromise(y, resolve, reject)
        }, r => {
          if (called) return
          called = true
          reject(r)
        })
      } else {
        resolve(x)
      }
    } catch (error) {
      if (!called) reject(error)
    }
  } else {
    resolve(x)
  }
}