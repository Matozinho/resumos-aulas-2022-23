package com.producer_consumer;

public interface IBuffer {
  void produz(int v);

  int consome();
}
