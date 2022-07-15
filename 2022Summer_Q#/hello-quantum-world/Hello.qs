namespace qsharp
{
  open Microsoft.Quantum.Intrinsic;
  open Microsoft.Quantum.Canon;
	
  function Hello () : Unit
  {
    Message("Hello, World!"); // automatically prints new line
    Message("Quantum");
  }
}
