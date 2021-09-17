    int tmpin​ = dup​(​0); 
    int tmpout​ =​ dup​ (​1); 
​//set the initial input  
    int ​fdin​; 
    if ​(​infile​) 
    {​
        fdin ​= ​open​(​infile​,​ O_READ​);  
    } 
    else ​
    {
// Use default input 
        fdin​ = dup​(​tmpin​); 
    } 
    int ​ret​;
    int ​fdout​; 
    for(​i =​ 0;​ i​ <​numsimplecommands​; ​i​++) 
    { 
//redirect input 
    dup2​(​fdin​, ​0); 
    close​(​fdin​); 
//setup output
        if ​(​i ​== ​numsimplecommands​ - 1)
        { 
// Last simple command   
            if(​outfile​)
            {    ​
                fdout​ =​ open​(outfile​, FLAG | FLAG); 
            } 
        else ​
            { 
// Use default output 
                fdout​ =​ dup​(​tmpout​);
            }
        } 
​       else ​
        {
// Not last  
//simple command 
//create pipe 
        int ​fdpipe​[​2]; 
        pipe​(​fdpipe​);
        fdout​ =​ fdpipe​[​1];
        fdin​ =​ fdpipe​[​0]; 
        }​
