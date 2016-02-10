//Loading libNPDG automatically eact time you start root.
//Author: Latiful kabir 
{
  cout << "Attempting to load libNPDG.so ... ";
  gSystem->Load("libTree");
  gSystem->Load("libNPDG.so");
  cout << "attempt completed\n";
}


//Place this script inside "macros" directory under your ROOT installation directory.  
//In that case each time you start root , it will load libn3he.so automatically.
