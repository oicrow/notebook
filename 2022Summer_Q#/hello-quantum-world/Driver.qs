using System;
using Microsoft.Quantum.Simulation.Simulators;

namespace qsharp
{
  public class Driver
  {
    public static void Main(String[] args)
    {
      Hello.Run(new QuantumSimulator()).Wait();
    }
  }
}
