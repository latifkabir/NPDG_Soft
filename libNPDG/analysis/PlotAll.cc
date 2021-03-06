void PlotAll(int run,int option=0)
{
    TTreeRaw t(run);
    TCanvas *c1=new TCanvas("c1","c1");
    c1->Divide(3,4);
    for (int i = 0; i < 12; i++) 
    {
	c1->cd(i+1);
	if(option!=1)
	    t.Draw(Form("4.65e-9*d21[][%i]:Entry$+Iteration$/49",i),"Entry$<100");    
	if(option==1)
	    t.Draw(Form("4.65e-9*d21[][%i]",i));    
    }

    TCanvas *c2=new TCanvas("c2","c2");
    c2->Divide(3,4);
    for (int i = 12; i < 24; i++) 
    {
	c2->cd(i-11);
	if(option!=1)
	    t.Draw(Form("4.65e-9*d21[][%i]:Entry$+Iteration$/49",i),"Entry$<100");    
	if(option==1)
	    t.Draw(Form("4.65e-9*d21[][%i]",i));    
    }

    TCanvas *c3=new TCanvas("c3","c3");
    c3->Divide(3,4);
    for (int i = 24; i < 36; i++) 
    {
	c3->cd(i-23);
	if(option!=1)
	    t.Draw(Form("4.65e-9*d21[][%i]:Entry$+Iteration$/49",i),"Entry$<100");    
	if(option==1)
	    t.Draw(Form("4.65e-9*d21[][%i]",i));    
    }

    TCanvas *c4=new TCanvas("c4","c4");
    c4->Divide(3,4);
    for (int i = 36; i < 48; i++) 
    {
	c4->cd(i-35);
	if(option!=1)
	    t.Draw(Form("4.65e-9*d21[][%i]:Entry$+Iteration$/49",i),"Entry$<100");    
	if(option==1)
	    t.Draw(Form("4.65e-9*d21[][%i]",i));    
    }


}
