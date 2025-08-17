let p;
p = new Promise((resolve) => {
  process.nextTick(() => resolve(p));
});

p.catch((err) => console.error(err));
