void PlotChannel(int run,int ch,int option=0,int entries=50)
{
    TTreeRaw t(run);
    TCanvas *c1=new TCanvas("c1","c1"); 
    if(option!=1)  
	t.Draw(Form("4.65e-9*d21[][%i]:Entry$+Iteration$/49",ch),Form("Entry$<%i",entries));
    if(option==1)  
	t.Draw(Form("4.65e-9*d21[][%i]",ch));        
}
