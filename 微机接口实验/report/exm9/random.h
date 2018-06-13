unsigned int random(unsigned int from, unsigned int to, unsigned int seed) {
  while(seed < from || seed >= to) {
    seed = seed * 1664525 + 1;
    seed = seed % to;
  }
  return seed;
}
